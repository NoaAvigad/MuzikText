//
//  MZDeviceLocalBluetoothNameManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/10/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZBluetoothLocalNameProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZBluetoothLocalNameCallback)(NSString* name);

@interface MZBluetoothLocalNameManager : NSObject <MZBluetoothLocalNameProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)getBluetoothLocalNameWithBlock:(MZBluetoothLocalNameCallback)block;
- (void)setBluetoothLocalName:(NSString*)localName;

@end
