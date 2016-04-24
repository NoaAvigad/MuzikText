//
//  MZSerialNumberRequestManager.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/20/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZSerialNumberProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZSerialNumberCallback)(NSString* serialNumber);

@interface MZSerialNumberRequestManager : NSObject <MZSerialNumberProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)getSerialNumberWithBlock:(MZSerialNumberCallback)block;

@end
