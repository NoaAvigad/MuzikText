//
//  MZSerialNumberProcessor.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/20/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZSerialNumberProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(NSString*)serialNumber;

@end

@interface MZSerialNumberProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZSerialNumberProcessorCallbackDelegate>)callback;


@end
