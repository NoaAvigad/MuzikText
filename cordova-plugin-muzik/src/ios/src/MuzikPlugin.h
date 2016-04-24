//
//  MuzikPlugin.h
//

#ifndef MUZIK_PLUGIN_H
#define MUZIK_PLUGIN_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"

// Cordova bridges
#import "ConnectionStateBridge.h"
#import "BluetoothLocalNameBridge.h"
#import "GestureBridge.h"
#import "AccelerometerBridge.h"
#import "BatteryLevelBridge.h"
#import "AutoPlayBridge.h"
#import "ChargeStatusBridge.h"
#import "SerialNumberBridge.h"
#import "MspVersionBridge.h"
#import "MotionBridge.h"

extern NSString* const TAG;

@interface MuzikPlugin : CDVPlugin

- (void) startServer:(CDVInvokedUrlCommand*)command;
- (void) stopServer:(CDVInvokedUrlCommand*)command;
- (void) registerForConnectionState:(CDVInvokedUrlCommand*)command;
- (void) unregisterForConnectionState:(CDVInvokedUrlCommand*)command;
- (void) registerForGestures:(CDVInvokedUrlCommand*)command;
- (void) registerForAllGestures:(CDVInvokedUrlCommand*)command;
- (void) unregisterForGestures:(CDVInvokedUrlCommand*)command;
- (void) unregisterForAllGestures:(CDVInvokedUrlCommand*)command;
- (void) registerForMotions:(CDVInvokedUrlCommand*)command;
- (void) unregisterForMotions:(CDVInvokedUrlCommand*)command;
- (void) unregisterForAllMotions:(CDVInvokedUrlCommand*)command;
- (void) getAccelerometerSample:(CDVInvokedUrlCommand*)command;
- (void) registerForAccelerometerDataStream:(CDVInvokedUrlCommand*)command;
- (void) unregisterForAccelerometerDataStream:(CDVInvokedUrlCommand*)command;
- (void) startBufferingAccelerometerData:(CDVInvokedUrlCommand*)command;
- (void) stopBufferingAccelerometerData:(CDVInvokedUrlCommand*)command;
- (void) getBufferSnapshot:(CDVInvokedUrlCommand*)command;
- (void) setAccelerometerBufferSize:(CDVInvokedUrlCommand*)command;
- (void) getBatteryLevel:(CDVInvokedUrlCommand*)command;
- (void) getBluetoothLocalName:(CDVInvokedUrlCommand*)command;
- (void) setBluetoothLocalName:(CDVInvokedUrlCommand*)command;
- (void) getAutoPlaySetting:(CDVInvokedUrlCommand*)command;
- (void) setAutoPlaySetting:(CDVInvokedUrlCommand*)command;
- (void) getChargeStatus:(CDVInvokedUrlCommand*)command;
- (void) getSerialNumber:(CDVInvokedUrlCommand*)command;
- (void) isConnected:(CDVInvokedUrlCommand*)command;
- (void) getMspVersion:(CDVInvokedUrlCommand*)command;
- (void) getManufacturer:(CDVInvokedUrlCommand*)command;
- (void) getFirmwareVersion:(CDVInvokedUrlCommand*)command;
- (void) getHardwareVersion:(CDVInvokedUrlCommand*)command;
- (void) getLibraryVersion:(CDVInvokedUrlCommand*)command;

@end

#endif


