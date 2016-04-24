//
//  AutoPlayBridge.h
//

#ifndef AUTO_PLAY_BRIDGE_H
#define AUTO_PLAY_BRIDGE_H

// Core imports
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

// Muzik imports
#import "MZAccessory.h"
#import "MZAutoPlayRequestManager.h"

@interface AutoPlayBridge : NSObject

// Constructors
- (id) initWithAccessory:(MZAccessory*)mzAccessory plugin:(CDVPlugin*)plugin;

// Methods
- (void) getAutoPlaySetting:(CDVInvokedUrlCommand*)command;
- (void) setAutoPlaySetting:(CDVInvokedUrlCommand*)command;

@end

#endif
