//
//  MZDeviceLocalBluetoothNameManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/10/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZDeviceBluetoothLocalNameProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZDeviceBluetoothLocalNameCallback)(NSString* name);

@interface MZDeviceBluetoothLocalNameManager : NSObject <MZDeviceBluetoothLocalNameProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)requestGetDeviceLocalBluetoothNameWithBlock:(MZDeviceBluetoothLocalNameCallback)block;
- (void)requestSetDeviceLocalBluetoothName:(NSString*)localName;

@end
