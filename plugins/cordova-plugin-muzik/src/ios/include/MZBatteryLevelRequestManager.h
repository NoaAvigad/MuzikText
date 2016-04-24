//
//  MZBatteryLevelRequestManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZBatteryLevelProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZBatteryLevelCallback)(NSInteger percent);

@interface MZBatteryLevelRequestManager : NSObject <MZBatteryLevelProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)getBatteryLevelWithBlock:(MZBatteryLevelCallback)block;

@end
