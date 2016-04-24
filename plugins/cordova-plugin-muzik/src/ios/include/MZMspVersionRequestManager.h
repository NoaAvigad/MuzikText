//
//  MZMspVersionRequestManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZMspVersionProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZMspVersionCallback)(NSString* version);

@interface MZMspVersionRequestManager : NSObject <MZMspVersionProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)getMspVersionWithBlock:(MZMspVersionCallback)block;

@end
