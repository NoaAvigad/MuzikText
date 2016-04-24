//
//  MZAutoPlayRequestManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZAutoPlayProcessor.h"
#import "MZBluetoothServer.h"
#import "MZPacketFactory.h"

typedef void (^MZAutoPlayCallback)(BOOL autoPlay);

@interface MZAutoPlayRequestManager : NSObject <MZAutoPlayProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)getAutoPlaySettingWithBlock:(MZAutoPlayCallback)block;
- (void)setAutoPlaySettingWith:(BOOL)autoPlay WithBlock:(MZAutoPlayCallback)block;

@end
