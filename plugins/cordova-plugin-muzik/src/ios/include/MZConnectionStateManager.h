//
//  MZConnectionStateManager.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/12/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZBluetoothServer.h"

typedef void (^MZConnectionStateCallback)(NSUInteger state);

@interface MZConnectionStateManager : NSObject

- (instancetype)initWithServer:(MZBluetoothServer*)server;
- (void)registerForConnectionState:(MZConnectionStateCallback)callback;
- (void)unregisterForConnectionState;

@end
