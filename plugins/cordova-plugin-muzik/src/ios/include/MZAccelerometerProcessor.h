//
//  MZAccelerometerProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZAccelerometerProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(int)x :(int)y :(int)z;

@end

@interface MZAccelerometerProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZAccelerometerProcessorCallbackDelegate>)callback;

@end
