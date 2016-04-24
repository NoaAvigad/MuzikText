//
//  MZDefaultMotion.h
//  MZAccessory
//
//  Created by Michael Spearman on 4/14/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MZDefaultMotion : NSObject

+ (NSNumber*)movingMotion;
+ (NSNumber*)verticalMotion;
+ (NSNumber*)stillMotion;
+ (NSNumber*)walkingMotion;
+ (NSNumber*)bobbingMotion;
+ (NSNumber*)otherMotion;
+ (NSString*)numberToState:(NSNumber*)stateNum;

@end
