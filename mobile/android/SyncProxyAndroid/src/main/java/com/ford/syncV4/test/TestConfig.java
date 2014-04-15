package com.ford.syncV4.test;

/**
 * Created with Android Studio.
 * Author: Chernyshov Yuriy - Mobile Development
 * Date: 2/27/14
 * Time: 9:58 AM
 */

import com.ford.syncV4.proxy.constants.ProtocolConstants;

/**
 * This class stores all the necessary data for SDK testing
 */
public class TestConfig {

    /**
     * Indicates whether or not to use parameter
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance
     */
    private boolean mUseHashId;

    /**
     * Indicates whether or not to use custom parameter
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance
     */
    private boolean mUseCustomHashId;

    /**
     * Holds a custom value of the
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance
     */
    private String mCustomHashId;

    /**
     * Indicates whether or not it is necessary to call
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} just right after RPC Session is
     * established
     */
    private boolean mDoCallRegisterAppInterface = true;

    /**
     * Indicates whether to keep USB reader thread open when perform session close procedure.
     * This feature is for the such Test Case as: call
     * {@link com.ford.syncV4.proxy.rpc.UnregisterAppInterface} (which will guide to close USB
     * reader)
     */
    private boolean mDoKeepUSBTransportConnected = false;

    /**
     * Min version of the protocol
     */
    private byte mProtocolMinVersion = ProtocolConstants.PROTOCOL_VERSION_MIN;

    /**
     * Max version of the protocol
     */
    private byte mProtocolMaxVersion = ProtocolConstants.PROTOCOL_VERSION_MIN;

    /**
     * @return a value of the functionality: whether or not to use parameter
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance, <b>true</b> | <b>false</b>
     */
    public boolean isUseHashId() {
        return mUseHashId;
    }

    /**
     * Set a value of the functionality: whether or not to use parameter
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance, <b>true</b> | <b>false</b>
     *
     * @param mUseHashId <b>true</b> | <b>false</b>
     */
    public void setUseHashId(boolean mUseHashId) {
        this.mUseHashId = mUseHashId;
    }

    /**
     * @return a value of the functionality: whether or not to use custom parameter
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance, <b>true</b> | <b>false</b>
     */
    public boolean isUseCustomHashId() {
        return mUseCustomHashId;
    }

    /**
     * Set a value of the functionality: whether or not to use custom parameter
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance, <b>true</b> | <b>false</b>
     *
     * @param mUseCustomHashId <b>true</b> | <b>false</b>
     */
    public void setUseCustomHashId(boolean mUseCustomHashId) {
        this.mUseCustomHashId = mUseCustomHashId;
    }

    /**
     * @return custom value of the
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance
     */
    public String getCustomHashId() {
        return mCustomHashId;
    }

    /**
     * Set a custom value of the
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface#getHashID()} when initiating
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} instance
     *
     * @param mCustomHashId {@link java.lang.String}
     */
    public void setCustomHashId(String mCustomHashId) {
        this.mCustomHashId = mCustomHashId;
    }

    /**
     * @return <b>true</b> if it is necessary to call
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} when RPC session has been established,
     * <b>false</b> - if not
     */
    public boolean isDoCallRegisterAppInterface() {
        return mDoCallRegisterAppInterface;
    }

    /**
     * Set <b>true</b> if it is necessary to call
     * {@link com.ford.syncV4.proxy.rpc.RegisterAppInterface} when RPC session has been established,
     * <b>false</b> - if not.<br/
     * <b> When set this value to false it is important to revert it back to true when Test is
     * complete!</b>
     *
     * @param mDoCallRegisterAppInterface boolean  value
     */
    public void setDoCallRegisterAppInterface(boolean mDoCallRegisterAppInterface) {
        this.mDoCallRegisterAppInterface = mDoCallRegisterAppInterface;
    }

    /**
     * @return whether to keep USB reader thread open when perform session close procedure.
     */
    public boolean isDoKeepUSBTransportConnected() {
        return mDoKeepUSBTransportConnected;
    }

    /**
     * Set whether to keep USB reader thread open when perform session close procedure.
     * <b> When set this value to true it is important to revert it back to false when Test is
     * complete!</b>
     *
     * @param mDoKeepUSBTransportConnected boolean value
     */
    public void setDoKeepUSBTransportConnected(boolean mDoKeepUSBTransportConnected) {
        this.mDoKeepUSBTransportConnected = mDoKeepUSBTransportConnected;
    }

    /**
     * @return protocol minimum version
     */
    public byte getProtocolMinVersion() {
        return mProtocolMinVersion;
    }

    /**
     * Set a minimum version of the protocol
     * @param mProtocolVersion protocol version int value
     */
    public void setProtocolMinVersion(byte mProtocolVersion) {
        this.mProtocolMinVersion = mProtocolVersion;
    }

    /**
     * @return protocol maximum version
     */
    public byte getProtocolMaxVersion() {
        return mProtocolMaxVersion;
    }

    /**
     * Set a maximum version of the protocol
     * @param mProtocolVersion protocol version int value
     */
    public void setProtocolMaxVersion(byte mProtocolVersion) {
        this.mProtocolMaxVersion = mProtocolVersion;
    }
}