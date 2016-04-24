//
//  MZDeviceBluetoothLocalNameProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZBluetoothLocalNameProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(NSString*)name;

@end

@interface MZBluetoothLocalNameProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZBluetoothLocalNameProcessorCallbackDelegate>)callback;

@end
