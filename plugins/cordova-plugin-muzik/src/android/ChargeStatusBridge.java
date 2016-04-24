package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IChargeStatusCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class ChargeStatusBridge implements IChargeStatusCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public ChargeStatusBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getChargeStatus(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getChargeStatus(this);
    }
    
    @Override
    public synchronized void onResponseReceived(boolean charging) {
        if (!this.callbacks.isEmpty()) {
            PluginResult result = new PluginResult(PluginResult.Status.OK, charging);
            this.callbacks.poll().sendPluginResult(result);
        }
    }
}
