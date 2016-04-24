package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IMotionCallback;

import java.util.ArrayList;
import java.util.HashMap;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class MotionBridge implements IMotionCallback {

    private MzAccessory mzAccessory;
    private HashMap<Integer, CallbackContext> callbacks;

    public MotionBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new HashMap<Integer, CallbackContext>();
    }

    public synchronized void registerForMotions(CallbackContext callback, int... motions) {
        for(int motion : motions) {
            this.callbacks.put(motion, callback);
        }
        this.mzAccessory.registerForMotions(this, motions);
    }

    public synchronized void unregisterForMotions(int... motions) {
        for(int motion : motions) {
            this.callbacks.remove(motion);
        }

        this.mzAccessory.unregisterForMotions(motions);
    }

    public synchronized void unregisterForAllMotions() {
        this.mzAccessory.unregisterForAllMotions();
    }

    @Override
    public synchronized void onMotionDetected(int motion) {
        CallbackContext callback = callbacks.get(motion);
        if (callback != null) {
            PluginResult result = new PluginResult(PluginResult.Status.OK, motion);
            result.setKeepCallback(true);
            callback.sendPluginResult(result);
        }
    }
}
