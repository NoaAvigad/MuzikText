package com.muzik.androidplugin;

import android.util.Log;

import com.muzik.accessory.*;
import com.muzik.accessory.callback.*;

import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;

public class MuzikPlugin extends CordovaPlugin {

    private static final String TAG = "MuzikPlugin";

    private MzAccessory mzAccessory;
    private MzConnectionStateBridge mzConnectionStateBridge;
    private SerialNumberBridge serialNumberBridge;
    private FirmwareVersionBridge firmwareVersionBridge;
    private HardwareVersionBridge hardwareVersionBridge;
    private ManufacturerBridge manufacturerBridge;
    private GestureBridge gestureBridge;
    private BluetoothLocalNameBridge bluetoothLocalNameBridge;
    private MspVersionBridge mspVersionBridge;
    private BatteryLevelBridge batteryLevelBridge;
    private ChargeStatusBridge chargeStatusBridge;
    private AccelerometerBridge accelerometerBridge;
    private AutoPlayBridge autoPlayBridge;
    private MotionBridge motionBridge;

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        mzAccessory = new MzAccessory();
        mzConnectionStateBridge = new MzConnectionStateBridge(mzAccessory);
        serialNumberBridge = new SerialNumberBridge(mzAccessory);
        firmwareVersionBridge = new FirmwareVersionBridge(mzAccessory);
        hardwareVersionBridge = new HardwareVersionBridge(mzAccessory);
        manufacturerBridge = new ManufacturerBridge(mzAccessory);
        gestureBridge = new GestureBridge(mzAccessory);
        bluetoothLocalNameBridge = new BluetoothLocalNameBridge(mzAccessory);
        mspVersionBridge = new MspVersionBridge(mzAccessory);
        batteryLevelBridge = new BatteryLevelBridge(mzAccessory);
        chargeStatusBridge = new ChargeStatusBridge(mzAccessory);
        accelerometerBridge = new AccelerometerBridge(mzAccessory);
        autoPlayBridge = new AutoPlayBridge(mzAccessory);
        motionBridge = new MotionBridge(mzAccessory);
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {

        if (action.equals("startServer")) {
            mzAccessory.startServer();
            return true; 
        }
        else if (action.equals("stopServer")) {
            mzAccessory.stopServer();
            return true; 
        }
        else if (action.equals("isConnected")) {
            PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, mzAccessory.isConnected());
            callbackContext.sendPluginResult(pluginResult);
            return true; 
        }
        else if (action.equals("registerForConnectionState")) {
            mzConnectionStateBridge.registerForConnectionState(callbackContext);
            return true; 
        }
        else if (action.equals("unregisterForConnectionState")) {
            mzConnectionStateBridge.unregisterForConnectionState();
            return true; 
        }
        else if (action.equals("registerForGestures")) {
            int[] gestures = new int[args.length()];
            try {
                for (int i = 0; i < gestures.length; i++) {
                    gestures[i] = args.getInt(i);
                }
            }
            catch (JSONException e) { }

            gestureBridge.registerForGestures(callbackContext, gestures);
            return true; 
        }
        else if (action.equals("registerForAllGestures")) {
            Boolean includePassthroughGestures = false;
            try {
                includePassthroughGestures = args.getBoolean(0);
            }
            catch (JSONException e) {
                Log.e(TAG, "registerForAllGesture: argument passed inexistant or not boolean");
            }

            gestureBridge.registerForAllGestures(callbackContext, includePassthroughGestures);
            return true; 
        }
        else if (action.equals("unregisterForGestures")) {
            int[] gestures = new int[args.length()];
            try {
                for (int i = 0; i < gestures.length; i++) {
                    gestures[i] = args.getInt(i);
                }
            }
            catch (JSONException e) { }

            gestureBridge.unregisterForGestures(gestures);
            return true; 
        }
        else if (action.equals("unregisterForAllGestures")) {
            Boolean includePassthroughGestures = false;
            try {
                includePassthroughGestures = args.getBoolean(0);
            }
            catch (JSONException e) { }

            gestureBridge.unregisterForAllGestures(includePassthroughGestures);
            return true; 
        }
        else if (action.equals("registerForMotions")) {
            int[] motions = new int[args.length()];
            try {
                for (int i = 0; i < motions.length; i++) {
                    motions[i] = args.getInt(i);
                }
            }
            catch (JSONException e) { }

            motionBridge.registerForMotions(callbackContext, motions);
            return true; 
        }
        else if (action.equals("unregisterForMotions")) {
            int[] motions = new int[args.length()];
            try {
                for (int i = 0; i < motions.length; i++) {
                    motions[i] = args.getInt(i);
                }
            }
            catch (JSONException e) { }

            motionBridge.unregisterForMotions(motions);
            return true; 
        }
        else if (action.equals("unregisterForAllMotions")) {
            motionBridge.unregisterForAllMotions();
            return true; 
        }
        else if (action.equals("getAccelerometerSample")) {
            accelerometerBridge.getAccelerometerSample(callbackContext);
            return true; 
        }
        else if (action.equals("registerForAccelerometerDataStream")) {
            accelerometerBridge.registerForAccelerometerDataStream(callbackContext);
            return true; 
        }
        else if (action.equals("unregisterForAccelerometerDataStream")) {
            accelerometerBridge.unregisterForAccelerometerDataStream();
            return true; 
        }
        else if (action.equals("startBufferingAccelerometerData")) {
            accelerometerBridge.startBufferingAccelerometerData();
            return true;
        }
        else if (action.equals("stopBufferingAccelerometerData")) {
            accelerometerBridge.stopBufferingAccelerometerData();
            return true;
        }
        else if (action.equals("getBufferSnapshot")) {
            callbackContext.success(accelerometerBridge.getBufferSnapshot());
            return true; 
        }
        else if (action.equals("setAccelerometerBufferSize")) {
            Integer size = null;
            try {
                size = args.getInt(0);
            }
            catch (JSONException e) { }
            if (size != null) {
                accelerometerBridge.setAccelerometerBufferSize(size);
            }
            return true; 
        }
        else if (action.equals("getBatteryLevel")) {
            batteryLevelBridge.getBatteryLevel(callbackContext);
            return true; 
        }
        else if (action.equals("getBluetoothLocalName")) {
            bluetoothLocalNameBridge.getBluetoothLocalName(callbackContext);
            return true; 
        }
        else if (action.equals("setBluetoothLocalName")) {
            String name = args.optString(0);
            if (name != "") {
                bluetoothLocalNameBridge.setBluetoothLocalName(name);
            }
            return true; 
        }
        else if (action.equals("getAutoPlaySetting")) {
            autoPlayBridge.getAutoPlaySetting(callbackContext);
            return true; 
        }
        else if (action.equals("setAutoPlaySetting")) {
            Boolean setAutoPlay = false;
            try {
                setAutoPlay = args.getBoolean(0);
            }
            catch (JSONException e) { }
            autoPlayBridge.setAutoPlaySetting(callbackContext, setAutoPlay);
            return true; 
        }
        else if (action.equals("getChargeStatus")) {
            chargeStatusBridge.getChargeStatus(callbackContext);
            return true; 
        }
        else if (action.equals("getSerialNumber")) {
            serialNumberBridge.getSerialNumber(callbackContext);
            return true; 
        }
        else if (action.equals("getManufacturer")) {
            manufacturerBridge.getManufacturer(callbackContext);
            return true; 
        }
        else if (action.equals("getFirmwareVersion")) {
            firmwareVersionBridge.getFirmwareVersion(callbackContext);
            return true; 
        }
        else if (action.equals("getHardwareVersion")) {
            hardwareVersionBridge.getHardwareVersion(callbackContext);
            return true; 
        }
        else if (action.equals("getMspVersion")) {
            mspVersionBridge.getMspVersion(callbackContext);
            return true; 
        }
        else if (action.equals("getLibraryVersion")) {
            callbackContext.success(mzAccessory.getLibraryVersion());
        }

        return false;
    }
}
