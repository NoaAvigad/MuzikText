//
//  MotionBridge.h
//

#ifndef MOTION_BRIDGE_H
#define MOTION_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZAccelerometerRequestManager.h"

@interface MotionBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) registerForMotions:(CDVInvokedUrlCommand*)command;
- (void) unregisterForMotions:(CDVInvokedUrlCommand*)command;
- (void) unregisterForAllMotions:(CDVInvokedUrlCommand*)command;

@end

#endif
