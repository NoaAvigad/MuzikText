//
//  BluetoothLocalNameBridge.h
//

#ifndef BLUETOOTH_LOCAL_NAME_BRIDGE_H
#define BLUETOOTH_LOCAL_NAME_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZBluetoothLocalNameManager.h"

@interface BluetoothLocalNameBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getBluetoothLocalName:(CDVInvokedUrlCommand*)command;
- (void) setBluetoothLocalName:(CDVInvokedUrlCommand*)command;

@end

#endif
