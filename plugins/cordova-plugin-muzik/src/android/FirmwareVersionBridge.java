package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IFirmwareVersionCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class FirmwareVersionBridge implements IFirmwareVersionCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public FirmwareVersionBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getFirmwareVersion(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getFirmwareVersion(this);
    }
    
    @Override
    public synchronized void onResponseReceived(String version) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(version);
        }
    }
}
