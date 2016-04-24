//
//  MZMotionAnalyzer.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/14/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZMotion.h"
#define MOTION_CHANGED_NOTIFICATION_NAME @"MotionChanged"

@class MZAccelerometerBuffer;
@interface MZMotionAnalyzer : NSObject {
    double xArray_Average;
    double yArray_Average;
    double zArray_Average;
    double vectorNormArray_Average;
    double forwardAngleArray_Average;
    double sideAngleArray_Average;
    
    double xArray_Range;
    double yArray_Range;
    double zArray_Range;
    double vectorNormArray_Range;
    double forwardAngleArray_Range;
    double sideAngleArray_Range;
    
    double xArray_Change;
    double yArray_Change;
    double zArray_Change;
    double vectorNormArray_Change;
    double forwardAngleArray_Change;
    double sideAngleArray_Change;
    
    double xArray_Variation_Range;
    double yArray_Variation_Range;
    double zArray_Variation_Range;
    double vectorNormArray_Variation_Range;
    double forwardAngleArray_Variation_Range;
    double sideAngleArray_Variation_Range;
}

- (instancetype)initWithBuffer:(MZAccelerometerBuffer*)buffer;
- (instancetype)initWithBuffer:(MZAccelerometerBuffer*)buffer withWindowLength:(float)windowLength withInterval:(float)interval;
- (void)start;
- (void)stop;
- (void)setBuffer:(MZAccelerometerBuffer*)buffer;
- (NSMutableArray<NSNumber*>*)currentMotionStates;
- (void)updateValuesWithBuffer:(MZAccelerometerBuffer*)bufferWindow;
- (void)computeMotionStates;
- (void)updateMotionStates:(NSArray<NSNumber*>*)activeCustomStates withStates:(NSArray<NSNumber*>*)allCustomStates;
- (void)removeStates:(NSArray<NSNumber*>*)states;
- (void)addStates:(NSArray<NSNumber*>*)states;
- (BOOL)hasState:(NSNumber*)state;
- (double)softMaxWithScore:(double)score;
- (BOOL)isBetween:(double)number min:(double)a max:(double)b;
- (NSArray*)softMaxWithArray:(NSArray<NSNumber*>*)scoreArray;
- (NSUInteger)maxIndex:(NSArray*)array;
- (NSNumber*)range:(NSArray*)array;
- (NSNumber*)max:(NSArray*)array;
- (NSNumber*)min:(NSArray*)array;
- (NSNumber*)average:(NSArray*)array;
- (NSNumber*)sum:(NSArray*)array;
- (NSNumber*)change:(NSArray*)array;
- (NSArray*)variation:(NSArray*)array;
- (NSNumber*)absSum:(NSArray*)array;
- (double)computeMovingScore;

@end
