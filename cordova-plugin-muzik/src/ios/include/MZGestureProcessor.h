//
//  MZGestureProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZGestureProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(NSNumber*)gestureIndex :(Byte*)data;

@end

@interface MZGestureProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZGestureProcessorCallbackDelegate>)callback;

@end
