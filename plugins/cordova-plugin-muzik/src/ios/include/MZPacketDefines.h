//
//  MZPacketDefines.h
//  NptAccessoryLib
//
//  Created by Michael Spearman on 3/30/16.
//  Copyright © 2016 Chris Sumner. All rights reserved.
//

#ifndef MZPacketDefines_h
#define MZPacketDefines_h

////////////////////////////////////////////////////
/// Packet Header Types
////////////////////////////////////////////////////
#define PACKET_START_BYTE		0xFE
#define PACKET_START_AVRCP_BYTE	0xFD

////////////////////////////////////////////////////
/// Packet Types
////////////////////////////////////////////////////
#define PACKET_TYPE_COMMON				0x00
#define PACKET_TYPE_APPCESSORY			0x13
#define PACKET_TYPE_MSP430				0x14


////////////////////////////////////////////////////
// TYPE COMMON commands
////////////////////////////////////////////////////
#define COMMON_GET_SERIAL_NUMBER	0x01
#define COMMON_RET_SERIAL_NUMBER	0x02
#define COMMON_RESET_DATABASE		0x03
#define COMMON_GET_DEVICE_INFO		0x04
#define COMMON_RET_DEVICE_INFO		0x05

////////////////////////////////////////////////////
// TYPE COMMON BODY commands
////////////////////////////////////////////////////





////////////////////////////////////////////////////
// TYPE APPCESSORY commands
////////////////////////////////////////////////////
#define APPCESSORY_GESTURE          0x03

#define APPCESSORY_GESTURE_DATA		0xC0
// Specific gesture defines in Accessory.h so the customer has access

#define APPCESSORY_GESTURE_MAP                    0x25
/* byte 0: GESTURE_HOLD_FRONT event */
/* byte 1: GESTURE_HOLD_UP event */
/* byte 2: GESTURE_HOLD_BACK event */
/* byte 3: GESTURE_HOLD_DOWN event */
#define APPCESSORY_GESTURE_MAP_RSP                0x26
/* see mapping above */

#define APPCESSORY_GESTURE_MAP_GET                0x27

#define APPCESSORY_BAT_LEVEL_REQ    0x04
#define APPCESSORY_BAT_LEVEL_RSP    0x05

#define APPCESSORY_SET_ACCEL_QUERY  0x06
#define APPCESSORY_RET_ACCEL_QUERY  0x07

#define APPCESSORY_APP_LAUNCH_GET   0x08
#define APPCESSORY_APP_LAUNCH_SET   0x09
#define APPCESSORY_APP_LAUNCH_RSP   0x0A

#define APPCESSORY_AUTO_PLAY_GET		0x0B
#define APPCESSORY_AUTO_PLAY_SET		0x0C
#define APPCESSORY_AUTO_PLAY_RSP		0x0D

#define APPCESSORY_SET_PSKEY			0x0E
// Byte 0 = which key to set (0-99)
// Byte 1 = length
// Byte 2-n = data
#define APPCESSORY_SET_PSKEY_RSP		0x0F
// Byte 0 = which key
// Byte 1 = result (0=fail, 1=ok)
#define APPCESSORY_GET_PSKEY			0x10
// Byte 0 = which key to get (0-99)
#define APPCESSORY_GET_PSKEY_RSP		0x11
// Byte 0 = which key
// Byte 1 = (0=fail key doesn't exist, 1=OK)
// Byte 2 = length (only if byte 0=1)
// Byte 3-n data (only if byte 0=1)

#define APPCESSORY_GET_CHARGER_STATUS           0x12
#define APPCESSORY_GET_CHARGER_STATUS_RSP       0x13
/* byte 0: 0 = charger not connected, 1 = charger connected */

#define APPCESSORY_SET_LOCAL_NAME               0x14
/* byte 0: name length - 32 max */
/* byte 1-n: the name (ASCII chars) */

#define APPCESSORY_SET_GESTURE_PASSTHRU         0x15
/* byte 0: bitfield of gestures to passthru - 1 = passthru, 0 = don't passthru */
/* defaults to all zeros on headphone boot/reboot */
/* bit 0 = GESTURE_PASSTHRU_UP */
/* bit 1 = GESTURE_PASSTHRU_FAST_UP */
/* bit 2 = GESTURE_PASSTHRU_DOWN */
/* bit 3 = GESTURE_PASSTHRU_FAST_DOWN */
/* bit 4 = GESTURE_PASSTHRU_BACK */
/* bit 5 = GESTURE_PASSTHRU_FORWARD */
/* bit 6 = GESTURE_PASSTHRU_TAP */
/* bit 7 = GESTURE_PASSTHRU_TAP_HOLD */
#define APPCESSORY_PSKEY_SEGMENT_PREAMBLE       0x16
/* byte 0: which key */
/* byte 1: total length of key  */
/* byte 2: length of this segment */
/* byte 3 - n: first segment, up to 48 bytes */
#define APPCESSORY_PSKEY_SEGMENT                0x17
/* byte 0: length of this segment */
/* byte 1 - n: subsequent segments, up to 48 bytes */

#define APPCESSORY_GET_LOCAL_NAME               0x18
#define APPCESSORY_GET_LOCAL_NAME_RSP           0x19

#define APPCESSORY_TRACK_INFO_GET				0x23
#define APPCESSORY_TRACK_INFO_RSP				0x24
    // Song info...
    #define TRACK_INFO_TITLE			0x01
    #define TRACK_INFO_ARTIST			0x02
    #define TRACK_INFO_ALBUM			0x03

#define APPCESSORY_GESTURE_DATA                 0xC0


////////////////////////////////////////////////////
// TYPE APPCESSORY BODY commands
////////////////////////////////////////////////////
// byte 0 - immediate = 0, periodic - 1
#define APPCESSORY_BODY_ACCEL_QUERY_NOW				0x00
#define APPCESSORY_BODY_ACCEL_QUERY_PERIODIC		0x01
// bytes 1-4 report period in ms
#define APPCESSORY_BODY_ACCEL_STOP_QUERY			0x02

// Version 0.10.15 uses a different location for speed dial gestures
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_OLD_12		38
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_OLD_3		39
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_OLD_6		41
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_OLD_9		43

#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_12	38
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_3	39
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_6	29
#define APPCESSORY_BODY_SPEED_DIAL_GESTURE_9	32


////////////////////////////////////////////////////
// TYPE MSP430 commands
////////////////////////////////////////////////////
#define MSP430_GET_VERSION			0x10
#define MSP430_RET_VERSION			0x11

#endif /* MZPacketDefines_h */
