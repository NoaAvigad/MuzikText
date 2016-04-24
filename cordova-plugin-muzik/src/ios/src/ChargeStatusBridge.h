//
//  ChargeStatusBridge.h
//

#ifndef CHARGE_STATUS_BRIDGE_H
#define CHARGE_STATUS_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZChargeStatusRequestManager.h"

@interface ChargeStatusBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getChargeStatus:(CDVInvokedUrlCommand*)command;

@end

#endif
