package com.muzik.androidplugin;

import com.muzik.accessory.MzAccessory;
import com.muzik.accessory.callback.IAccelerometerCallback;
import com.muzik.accessory.motion.AccelerometerBuffer;

import java.util.LinkedList;
import java.util.Queue;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class AccelerometerBridge implements IAccelerometerCallback {

    private MzAccessory mzAccessory;
    private Queue<CallbackContext> oneTimeCallbackQueue;
    private CallbackContext intervalCallback;

    public AccelerometerBridge(MzAccessory mzAccessory) {
        this.mzAccessory = mzAccessory;
        this.oneTimeCallbackQueue = new LinkedList<CallbackContext>();
    }

    public synchronized void getAccelerometerSample(CallbackContext callback) {
        this.oneTimeCallbackQueue.add(callback);
        this.mzAccessory.getAccelerometerSample(this);
    }

    public synchronized void registerForAccelerometerDataStream(CallbackContext callback) {
        this.intervalCallback = callback;
        this.mzAccessory.registerForAccelerometerDataStream(this);
    }

    public synchronized void unregisterForAccelerometerDataStream() {
        if (this.intervalCallback != null) {
            this.intervalCallback = null;
            this.mzAccessory.unregisterForAccelerometerDataStream();
        }
    }

    public synchronized void startBufferingAccelerometerData() {
        this.mzAccessory.startBufferingAccelerometerData();
    }

    public synchronized void stopBufferingAccelerometerData() {
        this.mzAccessory.stopBufferingAccelerometerData();
    }

    public synchronized JSONObject getBufferSnapshot() {
        AccelerometerBuffer accelerometerBuffer = this.mzAccessory.getBufferSnapshot();
        JSONObject jsonBuffer = new JSONObject();
        try {
            jsonBuffer.put("x", new JSONArray(accelerometerBuffer.getXArray()));
            jsonBuffer.put("y", new JSONArray(accelerometerBuffer.getYArray()));
            jsonBuffer.put("z", new JSONArray(accelerometerBuffer.getZArray()));
            jsonBuffer.put("norm", new JSONArray(accelerometerBuffer.getNormArray()));
            jsonBuffer.put("forwardAngle", new JSONArray(accelerometerBuffer.getForwardAngleArray()));
            jsonBuffer.put("sideAngle", new JSONArray(accelerometerBuffer.getSideAngleArray()));
        }
        catch (JSONException e) { }

        return jsonBuffer;
    }

    public synchronized void setAccelerometerBufferSize(int size) {
        this.mzAccessory.setAccelerometerBufferSize(size);
    }
    
    @Override
    public synchronized void onResponseReceived(float x, float y, float z, float norm, float forwardAngle, float sideAngle) {
        JSONArray response = new JSONArray();
        try {
            response.put((double) x);
            response.put((double) y);
            response.put((double) z);
            response.put((double) norm);
            response.put((double) forwardAngle);
            response.put((double) sideAngle);
        } catch (JSONException e) { }

        if (!this.oneTimeCallbackQueue.isEmpty()) {
            this.oneTimeCallbackQueue.poll().success(response);
        }

        if (this.intervalCallback != null) {
            PluginResult result = new PluginResult(PluginResult.Status.OK, response);
            result.setKeepCallback(true);
            this.intervalCallback.sendPluginResult(result);
        }
    }
}
