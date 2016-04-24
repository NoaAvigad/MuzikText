//
//  MZPacket.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 3/30/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZPacketBuilder.h"
#define BYTE_MAX_VALUE     127

@interface MZPacket : NSObject

@property (nonatomic, assign, readonly) Byte header;
@property (nonatomic, assign, readonly) int length;
@property (nonatomic, assign, readonly) Byte type;
@property (nonatomic, assign, readonly) Byte command;
@property (nonatomic, strong, readonly) NSData *body;
@property (nonatomic, assign, readonly) Byte avrcp;

- (instancetype)initWithHeader:(Byte)header
                        length:(int)length
                          type:(Byte)type
                       command:(Byte)command
                          body:(NSMutableData*)body
                         avrcp:(Byte)avrcp;
- (Byte)calculateChecksumWithSequenceNumber:(Byte)sequenceNumber;
+ (instancetype)packetWithBlock:(void(^)(MZPacketBuilder* builder))block;
@end
