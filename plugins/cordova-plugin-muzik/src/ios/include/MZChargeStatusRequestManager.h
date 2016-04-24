//
//  MZChargeStatusRequestManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZChargeStatusProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZChargeStatusCallback)(BOOL chargeStatus);

@interface MZChargeStatusRequestManager : NSObject <MZChargeStatusProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)getChargeStatusWithBlock:(MZChargeStatusCallback)block;

@end
