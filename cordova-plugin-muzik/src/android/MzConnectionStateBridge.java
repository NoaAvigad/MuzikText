package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.MzConnectionState;
import com.muzik.accessory.callback.IMzConnectionStateCallback;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

public class MzConnectionStateBridge implements IMzConnectionStateCallback {

    private MzAccessory mzAccessory;
    private CallbackContext callback;

    public MzConnectionStateBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
    }
    
    public synchronized void registerForConnectionState(CallbackContext callback) {
        this.callback = callback;
        this.mzAccessory.registerForConnectionState(this);
    }

    public synchronized void unregisterForConnectionState() {
        this.mzAccessory.unregisterForConnectionState();
    }

    @Override
    public synchronized void onConnectionStateChange(MzConnectionState state) {
        if (callback != null) {
            PluginResult result = new PluginResult(PluginResult.Status.OK, state.getValue());
            result.setKeepCallback(true);
            callback.sendPluginResult(result);
        }
    }
}
