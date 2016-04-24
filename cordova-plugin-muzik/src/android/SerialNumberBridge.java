package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.ISerialNumberCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class SerialNumberBridge implements ISerialNumberCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public SerialNumberBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getSerialNumber(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getSerialNumber(this);
    }
    
    @Override
    public synchronized void onResponseReceived(String serialNumber) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(serialNumber);
        }
    }
}
