/**
 * Copyright (c) 2014, Ford Motor Company
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

#ifndef STRUCT_TYPE_FROM_JSON_METHOD_H_
#define STRUCT_TYPE_FROM_JSON_METHOD_H_

#include "cppgen/cpp_function.h"

namespace codegen {
class Struct;

/*
 * Generates struct constructor that assigns fields values taking them from
 * parsed json tree
 */
class StructTypeFromJsonConstructor : public CppStructConstructor {
 public:
  StructTypeFromJsonConstructor(const Struct* strct,
                                const std::string& base_class_name);
  ~StructTypeFromJsonConstructor();
 private:
  // CppFunction pure virtual methods implementation
  virtual void DefineBody(std::ostream* os) const;
 private:
  // Fields
  const Struct* strct_;
};

/*
 * Generates struct method that serializes the struct fields into json tree.
 */
class StructTypeToJsonMethod : public CppFunction {
 public:
  StructTypeToJsonMethod(const Struct* strct);
  ~StructTypeToJsonMethod();
 private:
  // CppFunction pure virtual methods implementation
  virtual void DefineBody(std::ostream* os) const;
 private:
  const Struct* strct_;
};
}  // namespace codegen

#endif /* STRUCT_TYPE_FROM_JSON_METHOD_H_ */
