//
//  ChargeStatusProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZChargeStatusProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(BOOL)charging;

@end

@interface MZChargeStatusProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZChargeStatusProcessorCallbackDelegate>)callback;

@end
