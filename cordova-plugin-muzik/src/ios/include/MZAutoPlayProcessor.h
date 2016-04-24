//
//  MZAutoPlayProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZAutoPlayProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(BOOL)isAutoPlay;

@end

@interface MZAutoPlayProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZAutoPlayProcessorCallbackDelegate>)callback;

@end
