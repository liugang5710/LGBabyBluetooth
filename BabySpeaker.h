/**
* @brief babybluetooth block 查找和替换
*/

#import "BabyCallback.h"
#import <CoreBluetooth/CoreBluetooth.h>

@interface BabySpeaker : NSObject

- (BabyCallback *)callBack;
- (BabyCallback *)callBackOnCurrChannel;
- (BabyCallback *)callBackOnChnnel:(NSString *)channel;
- (BabyCallback *)callBackOnChnnel:(NSString *)channel
                  createWhenNotExist:(BOOL)createWhenNotExist;
 
 // 切换频道
 - (void)switchChannel:(NSString *)channel;
 
 // 添加到 notify list
 - (void)addNotifyCallback:(CBCharacteristic *)c
                    WithBlock:(void(^)(CBPeripheral* peripheral, CBCharacteristic *characteristic, NSError *error))block;
  
  // 从notify list中移除
  - (void)removeNotifyCallback:(CBCharacteristic *)c;
  
  // 获取notify list 
  - (NSMutalbeDictionary *)notifyCallBackList;
  
  // 获取notifyBlock
  - (void(^)(CBPeripheral *peripheral, CBCharacteristic *characteristics, NSError *error))
                notifyCallback:(CBCharacteristic *)c;
  
  
  
@end
