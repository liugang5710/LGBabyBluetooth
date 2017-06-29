/*
   BabyBluetooth
   @brief预定义一些库的执行行为和配置
*/
// Created by 刘刚 on 30/6/17


#import <Foundation/Foundation.h>

# pragma mark - baby 行为定义

/**
  001 
  Baby if show log 是否打印日志：默认1:打印，   0：不打印
*/
# define KBABY_IS_SHOW_LOG 1


/**
  002
  CBcentralManager  等待设备打开次数
*/
# define KBABY_CENTRAL_MANAGER_INIT_WAIT_TIMES 5

/**
  003
  CBcentralManager 等待设备打开间隔时间
*/
# define KBABY_CENTRAL_MANAGER_INIT_WAIT_SECOND 2.0

/**
  004
  BabyRhythm 默认心跳时间间隔
*/
#define KBABYRHYTHM_BEATS_DEFAULT_INTERAL 3

/**
  005
  Baby默认链式方法channel名称
*/
# define KBABY_DEFAULT_CHANNEL @"babyDefault"

# pragma mark - baby 通知

/**
* 蓝牙系统通知
*/

/**
*  Notification --- 001
*  centralManager status did change notification
*/ 
# define BabyNotificationAtCentralManagerDidUpdateState  @"BabyNotificationAtCentralManagerDidUpdateState"


/**
*  Notification --- 002
*  did discover peripheral notification
*/ 
#define BabyNotificationAtDidDiscoverPeripheral @"BabyNotificationAtDidDiscoverPeripheral"

/**
*  Notification --- 003
*   did connection peripheral notification
*/
#define BabyNotificationAtDidConnectPeripheral @"BabyNotificationAtDidConnectPeripheral"

/***
*  Notification --- 004
*  did failed connect Peripheral notification
**/
#define BabyNotificationAtDidFailToConnectPeripheral @"BabyNotificationAtDidFailToConnectPeripheral"

/**
*  Notification --- 005
*  did disconnect peripheral notification
*/
#define BabyNotificationAtDidDisconnectPeripheral @"BabyNotificationAtDidDisconnectPeripheral"

/**
*  Notification --- 006
*  did discover services notification
*/
#define BabyNotificationAtDidDiscoverServices @"BabyNotificationAtDidDiscoverServices"

/**
* Notification --- 007
* did discover characteristics notification
*/
#define BabyNotificationAtDidDiscoverCharacteristicForService @"BabyNotificationAtDidDiscoverCharaceristicsForService"

/**
*  Notification --- 008
*  did read or notify characteristic when received value notification
*/
#define BabyNotificationAtDidReadValueForCharacteristic @"BabyNotificationAtDidReadValueForCharacteristic"

/**
*  Notification --- 009
*  did write characteristic and response value notification
*/
#define BabyNotificationAtDidWriteValueForCharacteristic @"BabyNotificationAtDidWriteValueForCharacteristic"

/**
*  Notification --- 010
*  did change characteristics notify status notification
*/
#define BabyNotificationAtDidUpdateNotificationStateForCharacteristic @"BabyNotificationAtDidUpdateNotificationStateForCharacteristic"

/**
* Notification --- 011
* did read rssi and received value notification
*/
#define BabyNotificationAtDidReadRSSI @"BabyNotificationAtDidReadRSSI"

/**
*  Notification --- 012
*  蓝牙扩展通知
*  did centralManager enable notification
*/
#define BabyNotificationAtCentralManagerEnable @"BabyNotificationAtCentralManagerEnable"

#prama mark - baby 定义的方法
// Baby log
#define BabyLog(fmt, ...) if(KBABY_IS_SHOW_LOG) { NSLog(fmt,##__VA_ARGS__);}

@interface BabyDefine : NSObject

@end


