//
//  MZPacketBuilder.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 3/30/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MZPacket;
@interface MZPacketBuilder : NSObject

@property (nonatomic, assign) Byte header;
@property (nonatomic, assign) Byte command;
@property (nonatomic, assign) Byte type;
@property (nonatomic, assign) Byte avrcp;
@property (nonatomic, assign, readonly) int length;
@property (nonatomic, strong, readonly) NSMutableData* body;

- (MZPacketBuilder*)pushBytesToBody:(Byte*)bytes withLength:(int)length;
- (MZPacket*) build;

@end
