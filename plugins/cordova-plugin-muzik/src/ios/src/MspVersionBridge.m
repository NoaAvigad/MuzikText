//
//  MspVersionBridge.h
//

#import "MspVersionBridge.h"
#import "Queue.h"

@interface MspVersionBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) Queue* commandQueue;

@end

@implementation MspVersionBridge

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

// Get msp version
- (void) getMspVersion:(CDVInvokedUrlCommand *)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    MZMspVersionCallback callback = ^void(NSString* version){
        CDVInvokedUrlCommand* callbackCommand = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            CDVPluginResult* pluginResult = nil;
            if (version != nil){
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:version];
            } else {
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Msp version is nil."];
            }
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory getMspVersionWithBlock:callback];
}

@end