package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IMspVersionCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class MspVersionBridge implements IMspVersionCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public MspVersionBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getMspVersion(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getMspVersion(this);
    }
    
    @Override
    public synchronized void onResponseReceived(String version) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(version);
        }
    }
}
