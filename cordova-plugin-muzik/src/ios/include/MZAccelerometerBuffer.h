//
//  MZAccelerometerBuffer.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/13/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>

const static int DEFAULT_MAX_SIZE = 1000;

@interface MZAccelerometerBuffer : NSObject <NSCopying>

@property (nonatomic, assign) NSUInteger filterSize;
@property (nonatomic, assign) BOOL filterNewValues;
@property (nonatomic, assign) NSUInteger maxSampleCount;

- (instancetype)initWithMaxSampleCount:(int)maxSampleCount;
- (instancetype)initWithBufferData:(NSMutableArray<NSMutableArray<NSNumber*>*>*)bufferData;
- (void)addSampleWithData:(NSArray<NSNumber*>*)formattedXYZArray;
- (MZAccelerometerBuffer*)getDataFrom:(float)timeSinceStart to:(float)timeSinceEnd;
- (MZAccelerometerBuffer*)getDataSince:(float)timeSecondsAgo;
- (MZAccelerometerBuffer*)withoutLast:(float)timeSecondsAgo;
- (NSUInteger)getSampleCountDuringLast:(float)timeSeconds;
- (void)clear;
- (double)getBufferLengthSeconds;
- (float)average:(NSMutableArray<NSNumber*>*)filterBuffer;
- (NSDate*)lastSampleTime;
- (NSDate*)firstSampleTime;
- (NSArray<NSNumber*>*)getLastSample;
- (NSArray<NSNumber*>*)getTimeArray;
- (NSArray<NSNumber*>*)getXArray;
- (NSArray<NSNumber*>*)getYArray;
- (NSArray<NSNumber*>*)getZArray;
- (NSArray<NSNumber*>*)getNormArray;
- (NSArray<NSNumber*>*)getForwardAngleArray;
- (NSArray<NSNumber*>*)getSideAngleArray;
- (NSUInteger)getSampleCount;
- (float)getAngleWithAxis:(float)axis withNorm:(float)norm;
- (float)getNormWithX:(float)x withY:(float)y withZ:(float)z;
- (BOOL)isFull;
- (float)round:(float)number;

@end
