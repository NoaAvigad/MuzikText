//
//  MZGesture.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/6/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MZGesture : NSObject

- (NSNumber*)value;
- (BOOL)passthrough;

+ (NSArray<MZGesture*>*)values;
+ (MZGesture*) buttonForwardGesture;
+ (MZGesture*) buttonUpGesture;
+ (MZGesture*) buttonBackGesture;
+ (MZGesture*) buttonDownGesture;
+ (MZGesture*) swipeUpGesture;
+ (MZGesture*) swipeFastUpGesture;
+ (MZGesture*) swipeDownGesture;
+ (MZGesture*) swipeFastDownGesture;
+ (MZGesture*) swipeBackGesture;
+ (MZGesture*) swipeForwardGesture;
+ (MZGesture*) tapGesture;
+ (MZGesture*) tapHoldGesture;

@end
