package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IAutoPlayCallback;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class AutoPlayBridge implements IAutoPlayCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> callbacks;

    public AutoPlayBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new LinkedList<CallbackContext>();
    }

    public synchronized void getAutoPlaySetting(CallbackContext callback) {
        this.callbacks.add(callback);
        this.mzAccessory.getAutoPlaySetting(this);
    }

    public synchronized void setAutoPlaySetting(CallbackContext callback, boolean autoPlay) {
        this.callbacks.add(callback);
        this.mzAccessory.setAutoPlaySetting(this, autoPlay);
    }
    
    @Override
    public synchronized void onResponseReceived(boolean isAutoPlay) {
        if (!this.callbacks.isEmpty()) {
            PluginResult result = new PluginResult(PluginResult.Status.OK, isAutoPlay);
            this.callbacks.poll().sendPluginResult(result);
        }
    }
}
