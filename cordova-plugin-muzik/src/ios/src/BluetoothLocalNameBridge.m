//
//  BluetoothLocalNameBridge.h
//

#import "BluetoothLocalNameBridge.h"
#import "Queue.h"

@interface BluetoothLocalNameBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) Queue* commandQueue;

@end

@implementation BluetoothLocalNameBridge

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

// Get Bluetooth local name
- (void) getBluetoothLocalName:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    MZBluetoothLocalNameCallback callback = ^void(NSString* name){
        CDVInvokedUrlCommand* callbackCommand = nil;
        CDVPluginResult* pluginResult = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            if (name != nil){
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:name];
            } else {
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Bluetooth local name is nil."];
            }
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory getBluetoothLocalNameWithBlock:callback];
}

// Set Bluetooth local name
- (void) setBluetoothLocalName:(CDVInvokedUrlCommand*)command {
    CDVInvokedUrlCommand* callbackCommand = nil;
    CDVPluginResult* pluginResult = nil;
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    @synchronized
    (self) {
        if (![self.commandQueue isEmpty]) {
            callbackCommand = [self.commandQueue poll];
        }
    }
    NSString* name = [command.arguments objectAtIndex:0];
    if (callbackCommand != nil){
        if (name != nil){
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"setBluetoothLocalName success."];
        } else {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"setBluetoothLocalName args are nil."];
        }
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
    }
}
@end