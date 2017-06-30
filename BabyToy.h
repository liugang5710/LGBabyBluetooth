/**
*   @brief babyBluetooth 工具类
*/

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface BabyToy : NSObject

/// 十六进制转换为普通字符串
+(NSString *)ConvertHexStringToString:(NSString *)hexString;

/// 普通字符串转换为十六进制
+(NSString *)ConvertStringToHexString:(NSString *)string;

/// int 转为 data
+(NSData *)ConvertIntToData:(int)i;

/// data 转为 int
+(int)ConvertDataToInt:(NSData *)data;

/// 十六进制转换为普通字符串data
+(NSData *)ConvertHexStringToData:(NSString *)hexString;

/// 根据UUIDString 查找 CBCharateristic
+(CBCharacteristic *)findCharacteristicFormServices:(NSMutableArray *)services
                UUIDString:(NSString *)UUIDString;

@end
