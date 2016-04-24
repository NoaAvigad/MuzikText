//
//  MZDeviceBluetoothLocalNameProcessor.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"

@protocol MZDeviceBluetoothLocalNameProcessorCallbackDelegate <NSObject>

- (void)onResponseReceived:(NSString*)name;

@end

@interface MZDeviceBluetoothLocalNameProcessor : NSObject <MZProcessorDelegate>

- (instancetype)initWithCallback:(id<MZDeviceBluetoothLocalNameProcessorCallbackDelegate>)callback;

@end
