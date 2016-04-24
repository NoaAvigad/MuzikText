//
//  BatteryLevelBridge.m
//

#import "BatteryLevelBridge.h"
#import "Queue.h"

@interface BatteryLevelBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) Queue* commandQueue;

@end

@implementation BatteryLevelBridge

// Default constructor
- (id) init {
    self = [super init];
    if (self) {
        self.mzAccessory = nil;
        self.plugin = nil;
        self.commandQueue = [[Queue alloc] init];
    }
    return self;
}

// Constructor with references to an instance of MZAccessory, and CDVPlugin
- (id) initWithAccessory:(MZAccessory *)mzAccessory plugin:(CDVPlugin*)plugin{
    self = [super init];
    if (self) {
        self.mzAccessory = mzAccessory;
        self.plugin = plugin;
        self.commandQueue = [[Queue alloc] init];
    }
    return self;
}

// Get battery level
- (void) getBatteryLevel:(CDVInvokedUrlCommand *)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    MZBatteryLevelCallback callback = ^void(NSInteger percent){
        CDVInvokedUrlCommand* callbackCommand = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsNSInteger:percent];
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory getBatteryLevelWithBlock:callback];
}

@end