//
//  ChargeStatusBridge.h
//

#import "ChargeStatusBridge.h"
#import "Queue.h"

@interface ChargeStatusBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) Queue* commandQueue;

@end

@implementation ChargeStatusBridge

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

// Get charge status
- (void) getChargeStatus:(CDVInvokedUrlCommand *)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    MZChargeStatusCallback callback = ^void(BOOL charging){
        CDVInvokedUrlCommand* callbackCommand = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:charging];
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory getChargeStatusWithBlock:callback];
}

@end