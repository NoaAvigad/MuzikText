//
//  MZBluetoothServer.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZProcessorDelegate.h"
#import "MZConnectionState.h"

@interface MZBluetoothServer : NSObject <NSStreamDelegate>

@property (nonatomic, assign) NSUInteger connectionState;

- (void)addProcessor:(id<MZProcessorDelegate>)processor;
- (void)startServer;
- (void)stopServer;
- (void)sendPacket:(MZPacket*)packet;

- (NSString*)getAccessorySerialNumber;
- (NSString*)getAccessoryManufacturer;
- (NSString*)getAccessoryHardwareRevision;
- (NSString*)getAccessoryFirmwareRevision;

@end
