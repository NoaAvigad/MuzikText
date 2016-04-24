//
//  MotionBridge.h
//

#import "MotionBridge.h"

@interface MotionBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) NSMutableDictionary* callbacks;

@end

@implementation MotionBridge

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

// Register for motions
- (void) registerForMotions:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    NSMutableArray<NSNumber*>* mzMotions = [[NSMutableArray<NSNumber*> alloc] init];
    NSArray* motions = command.arguments;
    for (NSUInteger i = 0; i < motions.count; ++i){
        NSUInteger index = [[motions objectAtIndex:i] unsignedIntegerValue];
        NSNumber* key = [NSNumber numberWithUnsignedInteger:index];
        [mzMotions addObject:key];
        [self.callbacks setObject:command forKey:key];
    }
    MZMotionCallback callback = ^void(NSNumber* motion){
        CDVInvokedUrlCommand* motionCommand = [self.callbacks objectForKey:motion];
        CDVPluginResult* pluginResult = nil;
        if (motion != nil){
            NSUInteger motionIndex = [motion unsignedIntegerValue];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsNSUInteger:motionIndex];
            [pluginResult setKeepCallbackAsBool:YES];
        } else {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Invalid motion"];
        }
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:motionCommand.callbackId];
    };
    if (mzMotions.count > 0){
        [self.mzAccessory registerForMotions:[mzMotions copy] withCallback:callback];
    } else {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Empty or invalid motions."];
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }
}

// Unregister for motions
- (void) unregisterForMotions:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    NSMutableArray<NSNumber*>* mzMotions = [[NSMutableArray<NSNumber*> alloc] init];
    NSArray* motions = command.arguments;
    for (NSUInteger i = 0; i < motions.count; ++i){
        NSUInteger index = [[motions objectAtIndex:i] unsignedIntegerValue];
        NSNumber* key = [NSNumber numberWithUnsignedInteger:index];
        [mzMotions addObject:key];
    }
    CDVPluginResult* pluginResult = nil;
    if (mzMotions.count > 0){
        [self.mzAccessory unregisterForMotions:[mzMotions copy]];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"unregisterForMotions success."];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Empty or invalid motions."];
    }
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

// Unregister for all motions
- (void) unregisterForAllMotions:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    [self.mzAccessory unregisterForAllMotions];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"unregisterForAllMotions success."];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end