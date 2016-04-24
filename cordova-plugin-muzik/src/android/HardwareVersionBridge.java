package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IHardwareVersionCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class HardwareVersionBridge implements IHardwareVersionCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public HardwareVersionBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getHardwareVersion(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getHardwareVersion(this);
    }
    
    @Override
    public synchronized void onResponseReceived(String version) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(version);
        }
    }
}
