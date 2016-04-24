package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IMzGestureCallback;
import com.muzik.accessory.MzGesture;

import java.util.ArrayList;
import java.util.HashMap;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class GestureBridge implements IMzGestureCallback {

    private MzAccessory mzAccessory;
    private HashMap<Integer, CallbackContext> callbacks;

    public GestureBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.callbacks = new HashMap<Integer, CallbackContext>();
    }

    public synchronized void registerForGestures(CallbackContext callback, int... gestures) {
        for(int gesture : gestures) {
            this.callbacks.put(gesture, callback);
        }
        MzGesture[] gesturesToRegister = new MzGesture[gestures.length];
        for (int i = 0; i < gesturesToRegister.length; i++) {
            gesturesToRegister[i] = getMuzikGestureForIndex(gestures[i]);
        }
        this.mzAccessory.registerForGestures(this, gesturesToRegister);
    }

    public synchronized void registerForAllGestures(CallbackContext callback, boolean includePassthroughGestures) {
        ArrayList<Integer> gesturesToRegister = new ArrayList<Integer>();
        for (MzGesture gesture : MzGesture.values()) {
            if (!gesture.isPassthrough() || includePassthroughGestures) {
                gesturesToRegister.add(gesture.getValue());
            }
        }

        int[] gestures = new int[gesturesToRegister.size()];
        for (int i = 0; i < gestures.length; i++) {
            gestures[i] = gesturesToRegister.get(i);
        }
        this.registerForGestures(callback, gestures);
    }

    public synchronized void unregisterForGestures(int... gestures) {
        for(int gesture : gestures) {
            this.callbacks.remove(gesture);
        }
        MzGesture[] gesturesToUnregister = new MzGesture[gestures.length];
        for (int i = 0; i < gesturesToUnregister.length; i++) {
            gesturesToUnregister[i] = getMuzikGestureForIndex(gestures[i]);
        }
        this.mzAccessory.unregisterForGestures(gesturesToUnregister);
    }

    public synchronized void unregisterForAllGestures(boolean includePassthroughGestures) {
        ArrayList<Integer> gesturesToUnregister = new ArrayList<Integer>();
        for (MzGesture gesture : MzGesture.values()) {
            if (!gesture.isPassthrough() || includePassthroughGestures) {
                gesturesToUnregister.add(gesture.getValue());
            }
        }

        int[] gestures = new int[gesturesToUnregister.size()];
        for (int i = 0; i < gestures.length; i++) {
            gestures[i] = gesturesToUnregister.get(i);
        }
        this.unregisterForGestures(gestures);
    }

    @Override
    public synchronized void onResponseReceived(MzGesture gesture, byte data[]) {
        CallbackContext callback = callbacks.get(gesture.getValue());
        if (callback != null) {
            PluginResult result = new PluginResult(PluginResult.Status.OK, gesture.getValue());
            result.setKeepCallback(true);
            callback.sendPluginResult(result);
        }
    }

    private MzGesture getMuzikGestureForIndex(int gestureIndex)
    {
        for (MzGesture gesture : MzGesture.values())
        {
            if (gesture.getValue() == gestureIndex)
            {
                return gesture;
            }
        }

        return null;
    }
}
