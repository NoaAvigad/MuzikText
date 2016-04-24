//
//  ConnectionStateBridge.m
//

#import "ConnectionStateBridge.h"
#import "Queue.h"

@interface ConnectionStateBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) CDVInvokedUrlCommand* registerCommand;

@end

@implementation ConnectionStateBridge

// Default constructor
- (id) init {
    self = [super init];
    if (self) {
        self.mzAccessory = nil;
        self.plugin = nil;
        self.registerCommand = nil;
    }
    return self;
}

// Constructor with references to an instance of MZAccessory, and CDVPlugin
- (id) initWithAccessory:(MZAccessory *)mzAccessory plugin:(CDVPlugin*)plugin{
    self = [super init];
    if (self) {
        self.mzAccessory = mzAccessory;
        self.plugin = plugin;
        self.registerCommand = nil;
    }
    return self;
}

// Register a callback for connection state
- (void) registerForConnectionState:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    self.registerCommand = command;
    MZConnectionStateCallback callback = ^void(NSUInteger state){
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsNSUInteger:state];
        [pluginResult setKeepCallbackAsBool:YES];
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:self.registerCommand.callbackId];
    };
    [self.mzAccessory registerForConnectionState:callback];
}

// Unregister a callback for connection state
- (void) unregisterForConnectionState:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    [self.mzAccessory unregisterForConnectionState];
    self.registerCommand = nil;
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"unregisterForConnectionState success."];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end