//
//  MZAccelerometerRequestManager.h
//
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZAccelerometerProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"
@class MZMotionAnalyzer;
@class MZAccelerometerBuffer;

typedef void (^MZAccelerometerCallback)(float x, float y, float z, float forwardAngle, float sideAngle, float norm);
typedef void (^MZMotionCallback)(NSNumber* motion);
typedef void (^MZBufferSnapshotCallback)(MZAccelerometerBuffer* buffer);

@interface MZAccelerometerRequestManager : NSObject <MZAccelerometerProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)packetFactory;
- (void)getAccelerometerSampleWithBlock:(MZAccelerometerCallback)block;
- (void)registerForAccelerometerDataStreamWithBlock:(MZAccelerometerCallback)block;
- (void)unregisterForAccelerometerDataStream;
- (void)registerForMotions:(NSArray<NSNumber*>*)motions withCallback:(MZMotionCallback)callback;
- (void)unregisterForMotions:(NSArray<NSNumber*>*)motions;
- (void)unregisterForAllMotions;
- (void)setMotionAnalyzer:(MZMotionAnalyzer*)analyzer;
- (void)resetDefaultMotionAnalyzer;
- (void)setAccelerometerBufferSize:(int)size;
- (void)startBufferingAccelerometerData;
- (void)stopBufferingAccelerometerData;
- (MZAccelerometerBuffer*)getBufferSnapshot;

@end
