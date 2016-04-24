//
//  GestureBridge.h
//

#ifndef GESTURE_BRIDGE_H
#define GESTURE_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZGestureRequestManager.h"

@interface GestureBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) registerForGestures:(CDVInvokedUrlCommand*)command;
- (void) registerForAllGestures:(CDVInvokedUrlCommand*)command;
- (void) unregisterForGestures:(CDVInvokedUrlCommand*)command;
- (void) unregisterForAllGestures:(CDVInvokedUrlCommand*)command;
- (MZGesture*) getMuzikGestureForIndex:(NSUInteger)index;

@end

#endif
