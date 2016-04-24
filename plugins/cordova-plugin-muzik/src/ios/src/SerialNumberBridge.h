//
//  SerialNumberBridge.h
//

#ifndef SERIAL_NUMBER_BRIDGE_H
#define SERIAL_NUMBER_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZSerialNumberRequestManager.h"

@interface SerialNumberBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getSerialNumber:(CDVInvokedUrlCommand*)command;

@end

#endif
