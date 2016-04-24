//
//  AccelerometerBridge.h
//

#ifndef ACCELEROMETER_BRIDGE_H
#define ACCELEROMETER_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZAccelerometerRequestManager.h"
#import "MZAccelerometerBuffer.h"

@interface AccelerometerBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getAccelerometerSample:(CDVInvokedUrlCommand*)command;
- (void) registerForAccelerometerDataStream:(CDVInvokedUrlCommand*)command;
- (void) unregisterForAccelerometerDataStream:(CDVInvokedUrlCommand*)command;
- (void) startBufferingAccelerometerData:(CDVInvokedUrlCommand*)command;
- (void) stopBufferingAccelerometerData:(CDVInvokedUrlCommand*)command;
- (void) getBufferSnapshot:(CDVInvokedUrlCommand*)command;
- (void) setAccelerometerBufferSize:(CDVInvokedUrlCommand*)command;

@end

#endif
