//
//  AutoPlayBridge.g
//

#import "AutoPlayBridge.h"
#import "Queue.h"

@interface AutoPlayBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) Queue* commandQueue;

@end

@implementation AutoPlayBridge

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

// Get autoplay setting
- (void) getAutoPlaySetting:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    MZAutoPlayCallback callback = ^void(BOOL autoPlay){
        CDVInvokedUrlCommand* callbackCommand = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:autoPlay];
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory getAutoPlaySettingWithBlock:callback];
}

// Set autoplay setting
- (void) setAutoPlaySetting:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    BOOL autoPlay = [[command.arguments objectAtIndex:0] boolValue];
    MZAutoPlayCallback callback = ^void(BOOL autoPlay){
        CDVInvokedUrlCommand* callbackCommand = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:autoPlay];
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory setAutoPlaySetting:autoPlay withBlock:callback];
}

@end