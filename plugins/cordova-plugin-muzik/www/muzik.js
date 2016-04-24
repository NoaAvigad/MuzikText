muzik = module.exports;

muzik.CONNECTION_STATE = {
    HEADPHONES_NOT_CONNECTED: 0,
    INTERNAL_ERROR: 1,
    NO_BLUETOOTH_SUPPORT: 2,
    BLUETOOTH_NOT_ENABLED: 3,
    CONNECTED: 4
};

muzik.GESTURE = {
    BUTTON_FORWARD: 2,
    BUTTON_UP: 3,
    BUTTON_BACK: 4,
    BUTTON_DOWN: 5,
    SWIPE_UP: 6,
    SWIPE_FAST_UP: 7,
    SWIPE_DOWN: 8,
    SWIPE_FAST_DOWN: 9,
    SWIPE_BACK: 10,
    SWIPE_FORWARD: 11,
    TAP: 12,
    TAP_HOLD: 13
};

muzik.MOTION = {
    MOVING: 0,
    VERTICAL: 1,
    STILL: 2,
    WALKING: 3,
    BOBBING: 4,
    OTHER: 5
};

muzik.startServer = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "startServer", []);
};

muzik.stopServer = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "stopServer", []);
};

muzik.registerForConnectionState = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "registerForConnectionState", []);
};

muzik.unregisterForConnectionState = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "unregisterForConnectionState", []);
};

muzik.isConnected = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "isConnected", []);
};

muzik.registerForGestures = function (callback/*, gestures...*/) {
    cordova.exec(callback, noop, "MuzikPlugin", "registerForGestures", [].slice.call(arguments, 1));
};

muzik.registerForAllGestures = function (callback, includePassthroughGestures) {
    cordova.exec(callback, noop, "MuzikPlugin", "registerForAllGestures", [includePassthroughGestures]);
};

muzik.unregisterForGestures = function (/*gestures...*/) {
    cordova.exec(noop, noop, "MuzikPlugin", "unregisterForGestures", [].slice.call(arguments));
};

muzik.unregisterForAllGestures = function (includePassthroughGestures) {
    cordova.exec(noop, noop, "MuzikPlugin", "unregisterForAllGestures", [includePassthroughGestures]);
};

muzik.registerForMotions = function (callback/*, motions...*/) {
    cordova.exec(callback, noop, "MuzikPlugin", "registerForMotions", [].slice.call(arguments, 1));
};

muzik.unregisterForMotions = function (/*motions...*/) {
    cordova.exec(noop, noop, "MuzikPlugin", "unregisterForMotions", [].slice.call(arguments));
}

muzik.unregisterForAllMotions = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "unregisterForAllMotions", []);
}

muzik.getAccelerometerSample = function (callback) {
    var tempCallback = function (responseArr) {
        callback.apply(null, responseArr);
    };
    cordova.exec(tempCallback, noop, "MuzikPlugin", "getAccelerometerSample", []);
};

muzik.registerForAccelerometerDataStream = function (callback) {
    var tempCallback = function (responseArr) {
        callback.apply(null, responseArr);
    };
    cordova.exec(tempCallback, noop, "MuzikPlugin", "registerForAccelerometerDataStream", []);
};

muzik.unregisterForAccelerometerDataStream = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "unregisterForAccelerometerDataStream", []);
};

muzik.startBufferingAccelerometerData = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "startBufferingAccelerometerData", []);
};

muzik.stopBufferingAccelerometerData = function () {
    cordova.exec(noop, noop, "MuzikPlugin", "stopBufferingAccelerometerData", []);
};

muzik.getBufferSnapshot = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getBufferSnapshot", []);
};

muzik.setAccelerometerBufferSize = function (size) {
    cordova.exec(noop, noop, "MuzikPlugin", "setAccelerometerBufferSize", [size]);
};

muzik.getBatteryLevel = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getBatteryLevel", []);
};

muzik.getBluetoothLocalName = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getBluetoothLocalName", []);
};

muzik.setBluetoothLocalName = function (name) {
    cordova.exec(noop, noop, "MuzikPlugin", "setBluetoothLocalName", [name]);
};

muzik.getAutoPlaySetting = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getAutoPlaySetting", []);
};

muzik.setAutoPlaySetting = function (callback, autoPlay) {
    cordova.exec(callback, noop, "MuzikPlugin", "setAutoPlaySetting", [autoPlay]);
};

muzik.getChargeStatus = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getChargeStatus", []);
};

muzik.getSerialNumber = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getSerialNumber", []);
};

muzik.getManufacturer = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getManufacturer", []);
};

muzik.getFirmwareVersion = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getFirmwareVersion", []);
};

muzik.getHardwareVersion = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getHardwareVersion", []);
};

muzik.getMspVersion = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getMspVersion", []);
};

muzik.getLibraryVersion = function (callback) {
    cordova.exec(callback, noop, "MuzikPlugin", "getLibraryVersion", []);
}

function noop() { }