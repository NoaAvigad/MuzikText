//
//  Queue.m
//

#import "Queue.h"

@interface Queue ()

@property (nonatomic, strong) NSMutableArray* queue;

@end

@implementation Queue

- (id) init {
    self = [super init];
    if (self) {
        self.queue = [[NSMutableArray alloc] init];
    }
    return self;
}

- (BOOL) isEmpty {
    return self.queue.count == 0;
}

- (NSUInteger) size {
    return self.queue.count;
}

- (void) add:(id)object {
    [self.queue addObject:object];
}

- (void) remove :(id)object{
    if (!self.isEmpty){
        [self.queue removeObject:object];
    }
}

- (id) poll {
    id object = nil;
    if (!self.isEmpty){
        object = self.queue.firstObject;
        [self.queue removeObjectAtIndex:0];
    }
    return object;
}

- (id) peek {
    id object = nil;
    if (!self.isEmpty){
        object = self.queue.firstObject;
    }
    return object;
}

@end
