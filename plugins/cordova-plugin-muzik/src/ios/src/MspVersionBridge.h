//
//  MspVersionBridge.h
//

#ifndef MSP_VERSION_BRIDGE_H
#define MSP_VERSION_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZMspVersionRequestManager.h"

@interface MspVersionBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getMspVersion:(CDVInvokedUrlCommand*)command;

@end

#endif
