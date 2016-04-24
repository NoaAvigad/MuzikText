//
//  MuzikPlugin.m
//

#import "MuzikPlugin.h"

NSString* const TAG = @"MuzikPlugin";

@interface MuzikPlugin ()

@property (atomic, strong) MZAccessory* mzAccessory;
@property (atomic, strong) ConnectionStateBridge* connectionStateBridge;
@property (atomic, strong) GestureBridge* gestureBridge;
@property (atomic, strong) BatteryLevelBridge* batteryLevelBridge;
@property (atomic, strong) ChargeStatusBridge* chargeStatusBridge;
@property (atomic, strong) AccelerometerBridge* accelerometerBridge;
@property (atomic, strong) AutoPlayBridge* autoPlayBridge;
@property (atomic, strong) BluetoothLocalNameBridge* bluetoothLocalNameBridge;
@property (atomic, strong) SerialNumberBridge* serialNumberBridge;
@property (atomic, strong) MspVersionBridge* mspVersionBridge;
@property (atomic, strong) MotionBridge* motionBridge;

@end

@implementation MuzikPlugin

- (void) pluginInitialize {
    self.mzAccessory = [[MZAccessory alloc] init];
    self.connectionStateBridge = [[ConnectionStateBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.gestureBridge = [[GestureBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.batteryLevelBridge = [[BatteryLevelBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.chargeStatusBridge = [[ChargeStatusBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.accelerometerBridge = [[AccelerometerBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.autoPlayBridge = [[AutoPlayBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.bluetoothLocalNameBridge = [[BluetoothLocalNameBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.serialNumberBridge = [[SerialNumberBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.mspVersionBridge = [[MspVersionBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
    self.motionBridge = [[MotionBridge alloc] initWithAccessory:self.mzAccessory plugin:self];
}

- (void) startServer:(CDVInvokedUrlCommand *)command {
    [self.mzAccessory startServer];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Start server success."];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) stopServer:(CDVInvokedUrlCommand *)command {
    [self.mzAccessory stopServer];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Stop server success."];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) getBluetoothLocalName:(CDVInvokedUrlCommand *)command {
    [self.bluetoothLocalNameBridge getBluetoothLocalName:command];
}

- (void) setBluetoothLocalName:(CDVInvokedUrlCommand *)command {
    [self.bluetoothLocalNameBridge setBluetoothLocalName:command];
}

- (void) registerForConnectionState:(CDVInvokedUrlCommand *)command {
    [self.connectionStateBridge registerForConnectionState:command];
}

- (void) unregisterForConnectionState:(CDVInvokedUrlCommand *)command {
    [self.connectionStateBridge unregisterForConnectionState:command];
}

- (void) registerForGestures:(CDVInvokedUrlCommand *)command {
    [self.gestureBridge registerForGestures:command];
}

- (void) registerForAllGestures:(CDVInvokedUrlCommand *)command {
    [self.gestureBridge registerForAllGestures:command];
}

- (void) unregisterForGestures:(CDVInvokedUrlCommand *)command {
    [self.gestureBridge unregisterForGestures:command];
}

- (void) unregisterForAllGestures:(CDVInvokedUrlCommand *)command {
    [self.gestureBridge unregisterForAllGestures:command];
}

- (void) getAccelerometerSample:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge getAccelerometerSample:command];
}

- (void) registerForAccelerometerDataStream:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge registerForAccelerometerDataStream:command];
}

- (void) unregisterForAccelerometerDataStream:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge unregisterForAccelerometerDataStream:command];
}

- (void) startBufferingAccelerometerData:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge startBufferingAccelerometerData:command];
}

- (void) stopBufferingAccelerometerData:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge stopBufferingAccelerometerData:command];
}

- (void) getBufferSnapshot:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge getBufferSnapshot:command];
}

- (void) setAccelerometerBufferSize:(CDVInvokedUrlCommand *)command {
    [self.accelerometerBridge setAccelerometerBufferSize:command];
}

- (void) getBatteryLevel:(CDVInvokedUrlCommand *)command {
    [self.batteryLevelBridge getBatteryLevel:command];
}

- (void) getAutoPlaySetting:(CDVInvokedUrlCommand *)command {
    [self.autoPlayBridge getAutoPlaySetting:command];
}

- (void) setAutoPlaySetting:(CDVInvokedUrlCommand *)command {
    [self.autoPlayBridge setAutoPlaySetting:command];
}

- (void) getChargeStatus:(CDVInvokedUrlCommand *)command {
    [self.chargeStatusBridge getChargeStatus:command];
}

- (void) registerForMotions:(CDVInvokedUrlCommand *)command {
    [self.motionBridge registerForMotions:command];
}

- (void) unregisterForMotions:(CDVInvokedUrlCommand *)command {
    [self.motionBridge unregisterForMotions:command];
}

- (void) unregisterForAllMotions:(CDVInvokedUrlCommand *)command {
    [self.motionBridge unregisterForAllMotions:command];
}

- (void) getSerialNumber:(CDVInvokedUrlCommand *)command {
    [self.serialNumberBridge getSerialNumber:command];
}

- (void) getMspVersion:(CDVInvokedUrlCommand *)command {
    [self.mspVersionBridge getMspVersion:command];
}

-(void) isConnected:(CDVInvokedUrlCommand *)command {
    BOOL isConnected = [self.mzAccessory isConnected];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isConnected];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void) getManufacturer:(CDVInvokedUrlCommand *)command {
    NSString* manufacturer = [self.mzAccessory getManufacturer];
    CDVPluginResult* pluginResult = nil;
    if (manufacturer != nil){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:manufacturer];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Manufacturer is nil."];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void) getFirmwareVersion:(CDVInvokedUrlCommand *)command {
    NSString* firmwareVersion = [self.mzAccessory getFirmwareVersion];
    CDVPluginResult* pluginResult = nil;
    if (firmwareVersion != nil){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:firmwareVersion];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Firmware version is nil."];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void) getHardwareVersion:(CDVInvokedUrlCommand *)command {
    NSString* hardwareVersion = [self.mzAccessory getHardwareVersion];
    CDVPluginResult* pluginResult = nil;
    if (hardwareVersion != nil){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:hardwareVersion];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Hardware version is nil."];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void) getLibraryVersion:(CDVInvokedUrlCommand *)command {
    NSString* libraryVersion = [self.mzAccessory getLibraryVersion];
    CDVPluginResult* pluginResult = nil;
    if (libraryVersion != nil){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:libraryVersion];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Library version is nil."];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end