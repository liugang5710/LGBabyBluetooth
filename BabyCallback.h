/**
  
   @brief babybluetooth 的block的定义和存储

*/
#import <CoreBluetooth/CoreBluetooth.h>
#import "BabyOptions.h"

/**
* Block --- 001 设备状态改变的委托
*/
typedef void (^BBCentralManagerDidUpdateStateBlock)(CBCentralManager *central);

/**
*  Block --- 002 找到设备的委托
*/
typedef void (^BBDiscoverPeripheralsBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI);

/**
*  Block --- 003 连接设备成功的委托
*/
typedef void (^BBConnectedPeripheralBlock)(CBCentralManager *central, CBPeripheral *peripheral);

/**
*   Block --- 004 连接设备失败的委托
*/
typedef void (^BBFailToConnectBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);

/**
*   Block --- 005 断开设备连接的委托
*/
typedef void (^BBDisconnectBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);

/**
*   Block --- 006 找到服务的委托
*/
typedef void (^BBDiscoverServicesBlock)(CBPeripheral *peripheral, NSError *error);

/**
*   Block --- 007 找到characteristics的block
*/
typedef void (^BBDiscoverCharacteristicsBlock)(CBPeripheral *peripheral, CBService *service, NSError *error);

/**
* Block --- 008 更新（获取）Characteristics的value的block
*/
typedef void (^BBReadValueForCharacteristicBlock)(CBPeripheral *peripheral, CBCharacteristic *characteristic, NSError *error);

/**
* Block --- 009 获取Characteristic的名称
*/
typedef void (^BBDiscoverDescriptorsForCharacteristicBlock)(CBPeripheral *peripheral, CBCharacteristic *characteristic, NSError *error);

/**
*  Block --- 010 获取Desriptors的值
*/
typedef void (^BBReadValueForDescriptorsBlock)(CBPeripheral *peripheral, CBDescriptor *descriptor,NSError *error);

/**
*  Block --- 011 babyBluetooth cancelScanBlcok 方法调用后的回调
*/
typedef void (^BBCancelScanBlock)(CBCentralManager *centralManager);

/**
*   Block --- 012 babyBluetooth cancelAllPeripheralsConnection  方法调用后的回调
*/
typedef void (^BBCancelAllPeripheralsConnectionBlock)(CBCentralManager *centralManager);


typedef void (^BBDidWriteValueForCharacteristicBlock)(CBCharacteristic *characteristic, NSError *error);

typedef void (^BBDidWirteValueForDescriptorBlock)(CBDescriptor *descriptor, NSError *error);

typedef void (^BBDidUpdateNotificationStateForCharacteristicBlock)(CBCharacteristic *characteristic, NSError *error);

typedef void (^BBDidReadRSSIBlcok)(NSNumber *RSSI, NSError *error);

typedef void (^BBDidDiscoverIncludedServicesForServiceBlock)(CBService *service, NSError *error);

typedef void (^BBDidUpdateNameBlock)(CBPeripheral *peripheral);

typedef void (^BBDidModifyServiceBlock)(CBPeripheal *peripheral, NSArray *invalidatedServices);


#pargma mark - peripheral model
// 状态更新
typedef void (^BBPeripheralModelDidUpdateState)(CBPeripheralManager *peripheral);

// 外设增加服务
typedef void (^BBPeripheralModelDidAddService)(CBPeripheralManager *peripheralManager *peripheral, CBService *service, NSError *error);

// 开始广播
typedef void (^BBPeripheralModelDidStartAdvertising)(CBPeripheralManager *peripheral,NSError *error);

// 开始接受读取请求
typedef void (^BBPeripheralModelDidReceiveReadRequest)(CBPeripheralManager *peripheral, CBATTRequest *request);

// 接受写请求
typedef void (^BBPeripheralModelDidReceiveWriteRequest)(CBPeripheralManager *peripheral, NSArray *requests);

// 外设是否准备更新订阅者
typedef void (^BBPeripheralModelIsReadyToUpdateSubscribers)(CBPeripheralManager *peripheral);

// 
typefef void (^BBPeripheralModelDidSubscribeToCharacteristic)(CBPeripheralManager *peripheral, CBCentral *central, CBCharacteristic *characteristic);

typedef void (^BBPeripheralModelDidUnSubscribeToCharacteristic)(CBPeripheralManager *peripheral, CBCentral *central, CBCharacteristic *characteristic);


@interface BabyCallback : NSObject

#pragma mark - callback block

// 设置状态改变的委托
@property (nonatomic, copy) BBCentralManagerDidUpdateStateBlock blockOnCentralManagerDidUpdateState;

// 发现peripheral
@property (nonatomic, copy) BBDiscoverPeripheralsBlock blockOnDiscoverPeriperals;

// 连接callback
@property (nonatomic, copy) BBConnectedPeripheralBlock blockOnConnectedPeriphral;

// 连接设备失败的block
@property (nonatomic, copy) BBFailToConnectBlock blockOnFailToConnectBlock;

// 断开设备的连接的block
@property (nonatomic, copy) BBDisconnectBlock blockDisconnect;

// 发现service
@property (nonatomic, copy) BBDiscoverServicesBlock blockOnDiscoverServices;

// 发现characteristics
@property (nonatomic, copy) BBDiscoverCharacteristicsBlock blockOnDiscoverCharacteristics;

// 发现更新的Characteristics
@property (nonatomic, copy) BBReadValueForCharacteristicBlock blockOnReadValueForCharacteristic;

// 获取Characteristics的名称
@property (nonatomic, copy) BBDiscoverDescriptorsForCharacteristicBlock blockOnDiscoverDescriptorForCharacteristic;

// 获取Descriptors的值
@property (nonatomic, copy) BBReadValueForDescriptorBlock blockOnReadValueForDescriptor;

// 写值
@property (nonatomic, copy) BBDidWriteValueForCharacteristicBlock blockOnWriteValueForCharacteristic;

//
@property (nonatomic, copy) BBDidWriteValueForDescriptorBlock blockOnWriteValueForDescriptor;

// 
@property (nonatomic, copy) BBDidUpdateNotificationStateForCharacteristicBlock blockOnUpdateNotification;

//
@property (nonatomic, copy) BBDidReadRSSIBlock blockOnDidReadRSSI;

//
@property (nonatomic, copy) BBDidDiscoverIncludedServicesForServiceBlock blockOnDiscoverIncludedServicesForService;

//
@property (nonatomic, copy) BBDidUpdateNameBlock blockOnDidUpdateName;

//
@property (nonatomic, copy) BBDidModifyServicesBlock blockOnDidModifyServices;


// babyBluetooth stopScan方法调用后的回调
@property (nonatomic, copy) BBCancelScanBlock blockOnCancelScan;

// babyBluetooth stopConnectAllPeripherals方法后的回调
@property (nonatomic, copy) BBCancelAllPeripheralsConnectionBlock blockOnCancelAllPeripheralsConnection;

// babyBluetooth 蓝牙使用的参数
@property (nonatomic, strong) BabyOptions *babyOptions;

#pargma mark - 过滤器Filter
// 发现peripheral的规则
@property (nonatomic, copy) Bool (^filterOnDiscoverPeripherals)(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI);

// 连接外设的规则
@property (nonatomic, copy) Bool (^filterOnConnectToPeripherals)(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI);


# pragma mark - periphral model
@property (nonatomic, copy) BBPeripheralModelDidUpdateState blockOnPeripheralModelDidUpdateState;
@property (nonatomic, copy) BBPeripheralModelDidAddService blockOnPeripheralModelDidAddService;
@property (nonatomic, copy) BBPeripheralModelDidStartAdvertising blockOnPeripheralModelDidStartAdvertising;
@property (nonatomic, copy) BBPeripheralModelDidReceiveReadRequest blockOnPeripheralModelDidReceiveReadRequest;
@property (nonatomic, copy) BBPeripheralModelDidReceiveWriteRequest blockOnPeriphrealModelDidReceiveWriteRequest;
@property (nonatomic, copy) BBPeripheralModelIsReadyToUpdateSubscribers blockOnPeripheralModelIsReadyToUpdateSubscribers;
@property (nonatomic, copy) BBPeripheralModelDidSubscribeToCharacteristic blockOnPeripheralModelDidSubscribeToCharacteristic;
@property (nonatomic, copy) BBPeripheralModelDidUnSubscribeToCharacteristic blockOnPeripheralModelDidUnSubscribeToCharacteristic;
@end






