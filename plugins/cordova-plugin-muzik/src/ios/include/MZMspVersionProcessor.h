//
//  MZMspVersionProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZMspVersionProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(NSString*)version;

@end

@interface MZMspVersionProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZMspVersionProcessorCallbackDelegate>)callback;

@end
