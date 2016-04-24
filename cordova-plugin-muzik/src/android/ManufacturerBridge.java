package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IManufacturerCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class ManufacturerBridge implements IManufacturerCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public ManufacturerBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getManufacturer(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getManufacturer(this);
    }
    
    @Override
    public synchronized void onResponseReceived(String manufacturer) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(manufacturer);
        }
    }
}
