//
//  NptAccessory.h
//  NptAccessoryLib

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ExternalAccessory/ExternalAccessoryDefines.h"
#import "ExternalAccessory/EAAccessory.h"
#import "ExternalAccessory/EASession.h"
#import "ExternalAccessory/EAAccessoryManager.h"

#define kAccessorySongInfoTrackKey		@"TrackName"
#define kAccessorySongInfoArtistKey		@"ArtistName"
#define kAccessorySongInfoAlbumKey		@"AlbumName"

#define kAccessoryGestureMapUp			@"UpGesture"
#define kAccessoryGestureMapDown		@"DownGesture"
#define kAccessoryGestureMapLeft		@"LeftGesture"
#define kAccessoryGestureMapRight		@"RightGesture"

@protocol NptAccessoryDelegate <NSObject>
@optional

-(void) Accessory:(BOOL)wasAttached;		// Notification Accessory was connected/disconnected
-(void) SerialNumberReceived:(UInt32)serialNumber;		// Notification Serial number of the Accessory was received
-(void) GestureReceived:(NSInteger)gestureIndex withData:(NSData*)theData;	// Notification that a gesture has been received
-(void) MspVersionReceived:(NSString*)version;
-(void) BatteryLevel:(NSInteger)percentage;
-(void) AccelerometerDataReceived:(SInt16)x :(SInt16)y :(SInt16)z;
-(void) AppLaunchSettingReceived:(BOOL)launch;
-(void) AutoPlaySettingReceived:(BOOL)autoPlay;
-(void) ChargeStatusReceived:(BOOL)charging;
-(void) LocalNameReceived:(NSString*)name;
-(void) SpeedDialEntrySet:(NSInteger)which withResult:(Byte)result;

-(void) DspRefreshComplete;
-(void) LocalNameUpdated;
-(void) GesturePassThruUpdated;

-(void) AudioEnhancementsSetResult:(UInt16)updatedValue withResult:(Byte)result;
-(void) AudioEnhancementsValue:(UInt16)value;

-(void) SetPsKeyResult:(Byte)which withResult:(Byte)result;
-(void) PsKeyValue:(Byte)which withResult:(NSData*)value;

-(void) TrackInfoReceived:(NSDictionary*)trackInfo;
-(void) GestureMap:(NSDictionary*)map;
-(void) DeepSleepEnableResult:(BOOL)enabled;

@end

@protocol NptUpdateDelegateProtocol
-(void) UpdateStarted;
-(void) BlocksComplete:(NSInteger)sent :(NSInteger)total;
-(void) TransferComplete;
-(void) UpdateFailed:(NSInteger)reason;
-(void) UpdateComplete;
-(void) AttemptingResumeAtBlock:(NSInteger)blockNum;
-(void) ResumingAtBlock:(NSInteger)blockNum;
-(NSString *) FilenameForDestination:(Byte)which;
@end

#define MAX_BODY_SIZE			256
#define MAX_LOCAL_NAME_SIZE     33

enum
{
	UDPATE_DST_TOUCH_BOARD=1,
	UPDATE_DST_MAIN_BOARD,
	UPDATE_DST_MAX,
};

enum
{
	UPDATE_ERR_CHIP_ERASE,
	UPDATE_ERR_BAD_CKSUM,
	UPDATE_ERR_TIMEOUT,
	UPDATE_ERR_ACC_ABORT,
	UPDATE_ERR_USER_ABORT,
	UPDATE_ERR_GENERAL,
	
	UPDATE_ERR_BAD_FILE,
	UPDATE_ERR_SYNC,
	UPDATE_ERR_SYNC_DEST,
	
	UPDATE_ERR_MAX,
};

// You will receive one of these when a gesture occurrs
enum
{
	GESTURE_VOLUME,				// 1 Finger Up/Down
	GESTURE_PLAY_CONTROL,		// Tap for play/pause, 1 Finger forward skip, 1 finger back previous
	GESTURE_2_FINGER_FWD,
	GESTURE_2_FINGER_UP,
	GESTURE_2_FINGER_BACK,
	GESTURE_2_FINGER_DOWN,
	
	GESTURE_PASSTHRU_UP,
	GESTURE_PASSTHRU_FAST_UP,
	GESTURE_PASSTHRU_DOWN,
	GESTURE_PASSTHRU_FAST_DOWN,
	GESTURE_PASSTHRU_BACK,
	GESTURE_PASSTHRU_FORWARD,
	GESTURE_PASSTHRU_TAP,
	GESTURE_PASSTHRU_TAP_HOLD,

	GESTURE_MAX,
};

typedef NS_ENUM(NSUInteger, GestureAction)
{
	GestureActionDefault,
	GestureActionPlayPause,
	GestureActionNextTrack,
	GestureActionPreviousTrack,
	GestureActionVolumeUp,
	GestureActionVolumeDown,
	GestureActionVoice,
	
	GestureActionMax
};

// Use these defines when setting pass thru gestures.
// To enable multiple pass thru gestures, logically OR them together
#define PASSTHRU_ENABLE_UP			0x01
#define PASSTHRU_ENABLE_FAST_UP		0x02
#define PASSTHRU_ENABLE_DOWN		0x04
#define PASSTHRU_ENABLE_FAST_DOWN	0x08
#define PASSTHRU_ENABLE_BACK		0x10
#define PASSTHRU_ENABLE_FORWARD		0x20
#define PASSTHRU_ENABLE_TAP			0x40
#define PASSTHRU_ENABLE_TAP_HOLD	0x80

@interface NptAccessory : NSObject <NSStreamDelegate>
{
}

@property (nonatomic, weak) id <NptUpdateDelegateProtocol> updateDelegate;
@property (readonly) CGFloat PacketTimerInterval;
@property (readwrite) Byte UpdateDestination;
@property (readwrite) Byte UpdateBlockSize;

// Setup and tear down
+ (NptAccessory*)sharedAccessory;
-(bool)startAccessory;
-(void) CleanUp;

// Message Delegates
-(void) addDelegatesObject:(NSObject *)object;
-(void) removeDelegatesObject:(NSObject *)object;
-(void) removeAllDelegatesObjects;

// Accessory Information
- (NSString*) GetDeviceName;
- (NSString*) GetManufacturer;
- (NSString*) GetSoftwareVersion;
- (NSString*) GetHardwareVersion;
-(uint32_t) GetSerialNumber;
-(void) ReadSerialNumber;
-(void) ReadBatteryLevel;
-(void) SetBatteryLevelReadTimer:(NSTimeInterval)interval;
-(void) ReadAccelerometerData;
-(void) ReadAccelerometerDataWithInterval:(CGFloat)interval;

-(void) ReadMspVersion;

-(void) SetPsKey:(Byte)whichKey withData:(NSData*)data;
-(void) ReadPsKey:(Byte)whichKey;

-(void) ReadAutoPlay;
-(void) SetAutoPlay:(Byte)setting;
-(void) ReadAppLaunch;
-(void) SetAppLaunch:(Byte)setting;

-(void) ReadChargeStatus;
-(void) SetGesturePassThru:(Byte)which;
-(void) ReadLocalName;
-(BOOL) SetLocalName:(NSString*)name;
-(BOOL) SetGesureSpeedDialEntry:(NSInteger)which withNumber:(NSString*)number;
-(void) SetDeepSleepEnable:(BOOL)enable;

-(void) ReadAudioEnhancements;
-(void) SetAudioEnhancements:(UInt16)value;

-(void)readGestureMap;
-(void)setGestureMap:(NSDictionary*)map;

-(void)sendDspRefresh;

-(NSInteger)calculateBatteryPercentage:(NSInteger)mV;

-(NSDictionary*)getTrackInfo;
-(void)readTrackInfo;

// Connection Information
-(bool) IsDeviceConnected;

// Data Handler
-(void) StartPacketTimer:(BOOL)start :(float)interval;
-(bool) OutputBytes;

// Update functions
-(BOOL) LoadUpdateFile:(NSString *)filename;
-(BOOL) StartSoftwareUpdate;
-(void) ResumeSoftwareUpdate;
-(void) AbortSoftwareUpdate;
-(void) UpdateFlash;

// Version Information
-(NSString*) GetLibraryVersion;

@end

extern NptAccessory *g_Accessory __attribute__((deprecated("Use [NptAccessory sharedAccessory] instead")));
