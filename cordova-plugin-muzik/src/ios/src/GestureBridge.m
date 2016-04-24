//
//  GestureBridge.h
//

#import "GestureBridge.h"

@interface GestureBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) NSMutableDictionary* callbacks;

@end

@implementation GestureBridge

// Default constructor
- (id) init {
    self = [super init];
    if (self) {
        self.mzAccessory = nil;
        self.plugin = nil;
        self.callbacks = [[NSMutableDictionary alloc] init];
    }
    return self;
}

// Constructor with references to an instance of MZAccessory, and CDVPlugin
- (id) initWithAccessory:(MZAccessory *)mzAccessory plugin:(CDVPlugin*)plugin{
    self = [super init];
    if (self) {
        self.mzAccessory = mzAccessory;
        self.plugin = plugin;
        self.callbacks = [[NSMutableDictionary alloc] init];
    }
    return self;
}

// Register for gestures
- (void) registerForGestures:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    NSMutableArray<MZGesture*>* mzGestures = [[NSMutableArray<MZGesture*> alloc] init];
    NSArray* gestures = command.arguments;
    for (NSUInteger i = 0; i < gestures.count; ++i){
        NSUInteger index = [[gestures objectAtIndex:i] unsignedIntegerValue];
        MZGesture* gesture = [self getMuzikGestureForIndex:index];
        NSNumber* key = [NSNumber numberWithUnsignedInteger:index];
        [mzGestures addObject:gesture];
        [self.callbacks setObject:command forKey:key];
    }
    MZGestureCallback callback = ^void(MZGesture* gesture, Byte* data){
        CDVInvokedUrlCommand* gestureCommand = [self.callbacks objectForKey:gesture.value];
        CDVPluginResult* pluginResult = nil;
        if (gesture != nil){
            NSUInteger gestureIndex = [gesture.value unsignedIntegerValue];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsNSUInteger:gestureIndex];
            [pluginResult setKeepCallbackAsBool:YES];
        } else {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Invalid gesture"];
        }
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:gestureCommand.callbackId];
    };
    [self.mzAccessory registerForGestures:[mzGestures copy] withBlock:callback];
}

// Register for all gestures
- (void) registerForAllGestures:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    BOOL includePassthroughGestures = [[command.arguments objectAtIndex:0] boolValue];
    MZGestureCallback callback = ^void(MZGesture* gesture, Byte* data){
        CDVPluginResult* pluginResult = nil;
        if (gesture != nil){
            NSUInteger gestureIndex = [gesture.value unsignedIntegerValue];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsNSUInteger:gestureIndex];
            [pluginResult setKeepCallbackAsBool:YES];
        } else {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Invalid gesture"];
        }
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };
    [self.mzAccessory registerForAllGesturesWithPassthroughs:includePassthroughGestures withBlock:callback];
}

// Unregister for gestures
- (void) unregisterForGestures:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    NSMutableArray<MZGesture*>* mzGestures = [[NSMutableArray<MZGesture*> alloc] init];
    NSArray* gestures = command.arguments;
    for (NSUInteger i = 0; i < gestures.count; ++i){
        NSUInteger index = [[gestures objectAtIndex:i] unsignedIntegerValue];
        MZGesture* gesture = [self getMuzikGestureForIndex:index];
        [mzGestures addObject:gesture];
    }
    [self.mzAccessory unregisterForGestures:[mzGestures copy]];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"unregisterForGestures success."];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

// Unregister for all gestures
- (void) unregisterForAllGestures:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    BOOL passthroughs = [[command.arguments objectAtIndex:0] boolValue];
    NSString* message = [[NSString alloc] initWithFormat:@"unregisterForAllGestures success withPassthroughs: %@", (passthroughs ? @"YES" : @"NO")];
    [self.mzAccessory unregisterForAllGesturesWithPassthroughs:passthroughs];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (MZGesture*) getMuzikGestureForIndex:(NSUInteger)index{
    for (MZGesture* gesture in MZGesture.values){
        NSUInteger gestureValue = [gesture.value unsignedIntegerValue];
        if (index == gestureValue){
            return gesture;
        }
    }
    return nil;
}

@end