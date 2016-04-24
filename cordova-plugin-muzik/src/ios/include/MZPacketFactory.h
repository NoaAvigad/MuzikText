//
//  MZPacketFactory.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 3/30/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZPacket.h"

@interface MZPacketFactory : NSObject

+ (id)getInstance;
- (MZPacket*)getAccelerometerPacket;
- (MZPacket*)getAccelerometerPacketWithInterval:(int) interval;
- (MZPacket*)getAccelerometerPacketWithIntervalStop;
- (MZPacket*)getAutoPlayGetPacket;
- (MZPacket*)getAutoPlaySetPacket:(BOOL) isAutoPlay;
- (MZPacket*)getChargeStatusGetPacket;
- (MZPacket*)getBatteryLevelGetPacket;
- (MZPacket*)getGesturePassthroughSetPacket:(Byte)flag;
- (MZPacket*)getMspVersionGetPacket;
- (MZPacket*)getLocalNameGetPacket;
- (MZPacket*)getLocalNameSetPacket:(NSString*)localName;
- (MZPacket*)getSerialNumberGetPacket;

@end
