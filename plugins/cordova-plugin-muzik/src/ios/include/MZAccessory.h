//
//  MZAccessory.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZAccelerometerRequestManager.h"
#import "MZAutoPlayRequestManager.h"
#import "MZBatteryLevelRequestManager.h"
#import "MZChargeStatusRequestManager.h"
#import "MZGestureRequestManager.h"
#import "MZMspVersionRequestManager.h"
#import "MZBluetoothLocalNameManager.h"
#import "MZConnectionStateManager.h"
#import "MZSerialNumberRequestManager.h"
#import "MZMotion.h"
#import "MZConnectionState.h"

@interface MZAccessory : NSObject

- (void)startServer;
- (void)stopServer;
- (BOOL)isConnected;

- (void)registerForConnectionState:(MZConnectionStateCallback)block;
- (void)unregisterForConnectionState;
- (void)registerForAllGesturesWithPassthroughs:(BOOL)passthroughs withBlock:(MZGestureCallback)block;
- (void)registerForGestures:(NSArray<MZGesture*>*)gestures withBlock:(MZGestureCallback)callback;
- (void)unregisterForAllGesturesWithPassthroughs:(BOOL)passthroughs;
- (void)unregisterForGestures:(NSArray<MZGesture*>*)gestures;
- (void)getBluetoothLocalNameWithBlock:(MZBluetoothLocalNameCallback)callback;

- (void)registerForMotions:(NSArray<NSNumber*>*)motions withCallback:(MZMotionCallback)callback;
- (void)unregisterForMotions:(NSArray<NSNumber*>*)motions;
- (void)unregisterForAllMotions;
- (void)setMotionAnalyzer:(MZMotionAnalyzer*)analyzer;
- (void)resetDefaultMotionAnalyzer;
- (MZAccelerometerBuffer*)getBufferSnapshot;
- (void)setAccelerometerBufferSize:(int)size;
- (void)startBufferingAccelerometerData;
- (void)stopBufferingAccelerometerData;

- (void)setBluetoothLocalName:(NSString*)localName;
- (void)getMspVersionWithBlock:(MZMspVersionCallback)callback;
- (void)getBatteryLevelWithBlock:(MZBatteryLevelCallback)callback;
- (void)getChargeStatusWithBlock:(MZChargeStatusCallback)callback;
- (void)getAccelerometerSampleWithBlock:(MZAccelerometerCallback)callback;
- (void)registerForAccelerometerDataStreamWithBlock:(MZAccelerometerCallback)callback;
- (void)unregisterForAccelerometerDataStream;
- (void)getAutoPlaySettingWithBlock:(MZAutoPlayCallback)callback;
- (void)setAutoPlaySetting:(BOOL)autoPlay withBlock:(MZAutoPlayCallback)callback;
- (void)getSerialNumberWithBlock:(MZSerialNumberCallback)callback;
- (NSString*)getFirmwareVersion;
- (NSString*)getHardwareVersion;
- (NSString*)getManufacturer;
- (NSString*)getLibraryVersion;

@end
