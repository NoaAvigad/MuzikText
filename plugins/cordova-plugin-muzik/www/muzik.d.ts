declare module "Muzik" {
    module muzik{
        export enum CONNECTION_STATE {
            HEADPHONES_NOT_CONNECTED = 0,
            INTERNAL_ERROR,
            NO_BLUETOOTH_SUPPORT,
            BLUETOOTH_NOT_ENABLED,
            HEADPHONES_CONNECTED
        }
        export enum GESTURE {
            BUTTON_FORWARD = 2,
            BUTTON_UP,
            BUTTON_BACK,
            BUTTON_DOWN,
            SWIPE_UP,
            SWIPE_FAST_UP,
            SWIPE_DOWN,
            SWIPE_FAST_DOWN,
            SWIPE_BACK,
            SWIPE_FORWARD,
            TAP,
            TAP_HOLD
        }
        export enum MOTION {
            MOVING = 0,
            VERTICAL,
            STILL,
            WALKING,
            BOBBING,
            OTHER
        }
        export function startServer(): void;
        export function stopServer(): void;
        export function registerForConnectionState(callback: ((name: number) => void)): void;
        export function unregisterForConnectionState(): void;
        export function isConnected(callback): void;
        export function registerForGestures(callback: ((name: any) => void), ...gestures: number[]): void;
        export function registerForAllGestures(includePassthroughGestures: boolean, callback: ((name: Object) => void)): void;
        export function unregisterForGestures(...gestures: number[]): void;
        export function unregisterForAllGestures(includePassthroughGestures: boolean): void;
        export function registerForMotions(callback: ((name: any) => void), ...motions: number[]): void;
        export function unregisterForMotions(...motions: number[]): void;
        export function unregisterForAllMotions(): void;
        export function getAccelerometerSample(callback: ((name: Array<number>) => void)): void;
        export function registerForAccelerometerDataStream(callback: ((name: Array<number>) => void)): void;
        export function unregisterForAccelerometerDataStream(): void;
        export function startBufferingAccelerometerData(): void;
        export function stopBufferingAccelerometerData(): void;
        export function getBufferSnapshot(callback: (data: Object) => void): void;
        export function setAccelerometerBufferSize(size: number): void;
        export function getBatteryLevel(callback: ((name: number) => void)): void;
        export function getBluetoothLocalName(callback: ((name: string) => void)): void;
        export function setBluetoothLocalName(name: string): void;
        export function getAutoPlaySetting(callback: ((name: boolean) => void)): void;
        export function setAutoPlaySetting(autoPlay: boolean, callback: ((name: boolean) => void)): void;
        export function getChargeStatus(callback: ((name: boolean) => void)): void;
        export function getSerialNumber(callback: ((name: string) => void)): void;
        export function getManufacturer(callback: ((name: string) => void)): void;
        export function getFirmwareVersion(callback: ((name: string) => void)): void;
        export function getHardwareVersion(callback: ((name: string) => void)): void;
        export function getMspVersion(callback: ((name: string) => void)): void;
        export function getLibraryVersion(callback): void;
    }
    export default muzik;
}