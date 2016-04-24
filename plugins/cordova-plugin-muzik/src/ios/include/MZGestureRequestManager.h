//
//  MZGestureRequestManager.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/5/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZGestureProcessor.h"
#import "MZPacketFactory.h"
#import "MZBluetoothServer.h"
#import "MZGesture.h"

typedef void (^MZGestureCallback)(MZGesture* gesture, Byte* data);

@interface MZGestureRequestManager : NSObject <MZGestureProcessorCallbackDelegate>

- (instancetype)initWithServer:(MZBluetoothServer*)server withFactory:(MZPacketFactory*)factory;
- (void)registerForAllGesturesWithPassthroughs:(BOOL)passthroughs withBlock:(MZGestureCallback)block;
- (void)registerForGestures:(NSArray<MZGesture*>*)gestures withBlock:(MZGestureCallback)block;
- (void)unregisterForAllGesturesWithPassthroughs:(BOOL)passthroughs;
- (void)unregisterForGestures:(NSArray<MZGesture*>*)gestures;

@end
