//
//  Queue.h
//

#ifndef QUEUE_H
#define QUEUE_H

#import <Foundation/Foundation.h>

@interface Queue : NSObject

- (BOOL) isEmpty;
- (NSUInteger) size;

- (void) add:(id)object;
- (void) remove:(id)object;

- (id) poll;
- (id) peek;

@end

#endif
