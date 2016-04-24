//
//  AccelerometerBridge.h
//

#import "AccelerometerBridge.h"
#import "Queue.h"

@interface AccelerometerBridge ()

@property (nonatomic, strong) MZAccessory* mzAccessory;
@property (nonatomic, strong) CDVPlugin* plugin;
@property (nonatomic, strong) Queue* commandQueue;
@property (nonatomic, strong) CDVInvokedUrlCommand* intervalCommand;

@end

@implementation AccelerometerBridge

// Default constructor
- (id) init {
    self = [super init];
    if (self) {
        self.mzAccessory = nil;
        self.plugin = nil;
        self.commandQueue = [[Queue alloc] init];
        self.intervalCommand = nil;
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
        self.intervalCommand = nil;
    }
    return self;
}

- (void) getAccelerometerSample:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    @synchronized
    (self) {
        [self.commandQueue add:command];
    }
    MZAccelerometerCallback callback = ^void(float x, float y, float z, float forwardAngle, float sideAngle, float norm){
        CDVInvokedUrlCommand* callbackCommand = nil;
        @synchronized
        (self) {
            if (![self.commandQueue isEmpty]) {
                callbackCommand = [self.commandQueue poll];
            }
        }
        if (callbackCommand != nil){
            NSArray* sample = [NSArray arrayWithObjects:
                               [NSNumber numberWithFloat:x],
                               [NSNumber numberWithFloat:y],
                               [NSNumber numberWithFloat:z],
                               [NSNumber numberWithFloat:forwardAngle],
                               [NSNumber numberWithFloat:sideAngle],
                               [NSNumber numberWithFloat:norm], nil];
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:sample];
            [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:callbackCommand.callbackId];
        }
    };
    [self.mzAccessory getAccelerometerSampleWithBlock:callback];
}

- (void) registerForAccelerometerDataStream:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    self.intervalCommand = command;
    MZAccelerometerCallback callback = ^void(float x, float y, float z, float forwardAngle, float sideAngle, float norm){
        NSArray* sample = [NSArray arrayWithObjects:
                                              [NSNumber numberWithFloat:x],
                                              [NSNumber numberWithFloat:y],
                                              [NSNumber numberWithFloat:z],
                                              [NSNumber numberWithFloat:forwardAngle],
                                              [NSNumber numberWithFloat:sideAngle],
                                              [NSNumber numberWithFloat:norm], nil];
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:sample];
        [pluginResult setKeepCallbackAsBool:YES];
        [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:self.intervalCommand.callbackId];
    };
    [self.mzAccessory registerForAccelerometerDataStreamWithBlock:callback];
}

- (void) unregisterForAccelerometerDataStream:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    [self.mzAccessory unregisterForAccelerometerDataStream];
    self.intervalCommand = nil;
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"unregisterForAccelerometerDataStream success."];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) startBufferingAccelerometerData:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    [self.mzAccessory startBufferingAccelerometerData];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"startBufferingAccelerometerData success."];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) stopBufferingAccelerometerData:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    [self.mzAccessory stopBufferingAccelerometerData];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"stopBufferingAccelerometerData success."];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) getBufferSnapshot:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    MZAccelerometerBuffer* accelerometerBuffer = [self.mzAccessory getBufferSnapshot];
    NSDictionary* buffer = @{@"x" : [accelerometerBuffer getXArray],
                             @"y" : [accelerometerBuffer getYArray],
                             @"z" : [accelerometerBuffer getZArray],
                             @"norm" : [accelerometerBuffer getNormArray],
                             @"forwardAngle" : [accelerometerBuffer getForwardAngleArray],
                             @"sideAngle" : [accelerometerBuffer getSideAngleArray]
                             };
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:buffer];
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setAccelerometerBufferSize:(CDVInvokedUrlCommand*)command {
    if (command == nil){
        return;
    }
    CDVPluginResult* pluginResult = nil;
    if (command.arguments.count > 0){
        int size = [[command.arguments objectAtIndex:0] intValue];
        [self.mzAccessory setAccelerometerBufferSize:size];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"setAccelerometerBufferSize success."];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"setAccelerometerBufferSize args are nil."];
    }
    [self.plugin.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end