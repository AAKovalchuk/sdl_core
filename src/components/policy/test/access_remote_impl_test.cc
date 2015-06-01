/*
 * Copyright (c) 2015, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "gtest/gtest.h"
#include "policy/access_remote_impl.h"

namespace policy {

TEST(AccessRemoteImplTest, Allow) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Object what = { policy_table::MT_RADIO };
  access_remote.Allow(who, what);
  AccessRemoteImpl::AccessControlList::const_iterator i = access_remote.acl_
      .find(what);
  ASSERT_NE(access_remote.acl_.end(), i);
  AccessRemoteImpl::AccessControlRow::const_iterator j = i->second.find(who);
  ASSERT_NE(i->second.end(), j);
  EXPECT_EQ(TypeAccess::kAllowed, j->second);
}

TEST(AccessRemoteImplTest, KeyMapTest) {
  // Testing operator < to use as key of map
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Object what1 = { policy_table::MT_RADIO };
  Object what2 = { policy_table::MT_CLIMATE };
  access_remote.Allow(who, what1);
  access_remote.Allow(who, what2);
  ASSERT_EQ(2, access_remote.acl_.size());
}

TEST(AccessRemoteImplTest, Deny) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Object what = { policy_table::MT_RADIO };
  access_remote.Deny(who, what);
  AccessRemoteImpl::AccessControlList::const_iterator i = access_remote.acl_
      .find(what);
  ASSERT_NE(access_remote.acl_.end(), i);
  AccessRemoteImpl::AccessControlRow::const_iterator j = i->second.find(who);
  ASSERT_NE(i->second.end(), j);
  EXPECT_EQ(TypeAccess::kDisallowed, j->second);
}

TEST(AccessRemoteImplTest, ChangeAccess) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Object what = { policy_table::MT_RADIO };
  access_remote.Allow(who, what);
  ASSERT_EQ(TypeAccess::kAllowed, access_remote.acl_[what][who]);
  access_remote.Deny(who, what);
  ASSERT_EQ(TypeAccess::kDisallowed, access_remote.acl_[what][who]);
  access_remote.Allow(who, what);
  EXPECT_EQ(TypeAccess::kAllowed, access_remote.acl_[what][who]);
}

TEST(AccessRemoteImplTest, ResetBySubject) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Object what1 = { policy_table::MT_RADIO };
  Object what2 = { policy_table::MT_CLIMATE };
  access_remote.Allow(who, what1);
  access_remote.Deny(who, what2);
  ASSERT_EQ(2, access_remote.acl_.size());
  ASSERT_EQ(1, access_remote.acl_[what1].size());
  ASSERT_EQ(1, access_remote.acl_[what2].size());

  access_remote.Reset(who);
  ASSERT_EQ(2, access_remote.acl_.size());
  EXPECT_TRUE(access_remote.acl_[what1].empty());
  EXPECT_TRUE(access_remote.acl_[what2].empty());
}

TEST(AccessRemoteImplTest, ResetByObject) {
  AccessRemoteImpl access_remote;
  Subject who1 = { "dev1", "12345" };
  Subject who2 = { "dev2", "123456" };
  Object what = { policy_table::MT_RADIO };
  access_remote.Allow(who1, what);
  access_remote.Deny(who2, what);
  ASSERT_EQ(1, access_remote.acl_.size());
  ASSERT_EQ(2, access_remote.acl_[what].size());

  access_remote.Reset(what);
  EXPECT_TRUE(access_remote.acl_.empty());
}

TEST(AccessRemoteImplTest, CheckAllowed) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Object what = { policy_table::MT_RADIO };
  access_remote.Allow(who, what);

  EXPECT_EQ(TypeAccess::kAllowed, access_remote.Check(who, what));
}

TEST(AccessRemoteImplTest, CheckDisallowed) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Subject who1 = { "dev1", "123456" };
  Object what = { policy_table::MT_RADIO };

  access_remote.Allow(who, what);
  EXPECT_EQ(TypeAccess::kDisallowed, access_remote.Check(who1, what));

  access_remote.Reset(who);
  access_remote.Deny(who1, what);
  EXPECT_EQ(TypeAccess::kDisallowed, access_remote.Check(who1, what));
}

TEST(AccessRemoteImplTest, CheckManual) {
  AccessRemoteImpl access_remote;
  Subject who = { "dev1", "12345" };
  Subject who1 = { "dev1", "123456" };
  Object what = { policy_table::MT_RADIO };

  EXPECT_EQ(TypeAccess::kManual, access_remote.Check(who, what));

  access_remote.Deny(who1, what);
  EXPECT_EQ(TypeAccess::kManual, access_remote.Check(who, what));
}

TEST(AccessRemoteImplTest, MatchPredicate) {
  policy_table::FunctionalGroupings groups;
  policy_table::Rpc& rpcs = groups["group1"].rpcs;
  policy_table::RpcParameters& rpc = rpcs["SetMaxVolume"];
  rpc.parameters->push_back(policy_table::P_VIN);

  RemoteControlParams empty;
  RemoteControlParams vin;
  vin.push_back("vin");
  RemoteControlParams gps;
  gps.push_back("gps");
  RemoteControlParams wrong;
  wrong.push_back("wrong");

  EXPECT_TRUE(Match(groups, "SetMaxVolume", vin)("group1"));
  EXPECT_FALSE(Match(groups, "Any", empty)("no-group"));
  EXPECT_FALSE(Match(groups, "no-rpc", empty)("group1"));
  EXPECT_FALSE(Match(groups, "SetMaxVolume", empty)("group1"));
  EXPECT_FALSE(Match(groups, "SetMaxVolume", wrong)("group1"));
  EXPECT_FALSE(Match(groups, "SetMaxVolume", gps)("group1"));
}

}  // namespace policy

