//
//  MZProcessorDelegate.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 4/4/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MZPacket.h"

@protocol MZProcessorDelegate <NSObject>

@required
- (BOOL)process:(MZPacket*)pkt;

@end
