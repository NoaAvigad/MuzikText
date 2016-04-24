//
//  MZBatteryLevelProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZBatteryLevelProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(NSInteger)batteryPercent;

@end

@interface MZBatteryLevelProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZBatteryLevelProcessorCallbackDelegate>)callback;

@end
