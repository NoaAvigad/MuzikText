package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IBatteryLevelCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class BatteryLevelBridge implements IBatteryLevelCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public BatteryLevelBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getBatteryLevel(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getBatteryLevel(this);
    }
    
    @Override
    public synchronized void onResponseReceived(int percentage) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(percentage);
        }
    }
}
