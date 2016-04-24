package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IBluetoothLocalNameCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class BluetoothLocalNameBridge implements IBluetoothLocalNameCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public BluetoothLocalNameBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getBluetoothLocalName(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getBluetoothLocalName(this);
    }

    public synchronized void setBluetoothLocalName(String name) {
        this.mzAccessory.setBluetoothLocalName(name);
    }
    
    @Override
    public synchronized void onResponseReceived(String name) {
        if (!this.callbacks.isEmpty()) {
            this.callbacks.poll().success(name);
        }
    }
}
