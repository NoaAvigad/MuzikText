//
//  ConnectionStateBridge.h
//

#ifndef CONNECTION_STATE_BRIDGE_H
#define CONNECTION_STATE_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZConnectionStateManager.h"

@interface ConnectionStateBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) registerForConnectionState:(CDVInvokedUrlCommand*)command;
- (void) unregisterForConnectionState:(CDVInvokedUrlCommand*)command;

@end

#endif
