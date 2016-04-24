//
//  BatteryLevelBridge.h
//

#ifndef BATTERY_LEVEL_BRIDGE_H
#define BATTERY_LEVEL_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZBatteryLevelRequestManager.h"

@interface BatteryLevelBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getBatteryLevel:(CDVInvokedUrlCommand*)command;

@end

#endif
