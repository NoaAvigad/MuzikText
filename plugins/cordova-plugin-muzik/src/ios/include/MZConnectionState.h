//
//  MZConnectionState.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/21/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MZConnectionState : NSObject

+ (NSUInteger)notConnected;
+ (NSUInteger)internalError;
+ (NSUInteger)noBluetoothSupport;
+ (NSUInteger)bluetoothNotEnabled;
+ (NSUInteger)connected;
+ (NSUInteger)serverOff;
+ (NSString*)numberToState:(NSUInteger)stateNum;

@end
