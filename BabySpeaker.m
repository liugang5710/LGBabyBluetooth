#import "BabySpeaker.h"
#import "BabyDefine.h"

typedef NS_ENUM(NSUInteger, BabySpeakerType) {
    BabySpeakerTypeDiscoverPeripherals,
    BabySpeakerTypeConnectedPeripheral,
    BabySpeakerTypeDiscoverPeripheralsFailToConnect,
    BabySpeakerTypeDiscoverPeripheralsDisconnect,
    BabySpeakerTypeDiscoverPeripheralsDiscoverServices,
    BabySpeakerTypeDiscoverPeripheralsDiscoverCharacteristics,
    BabySpeakerTypeDiscoverPeripheralsReadValueForCharacteristic,
    BabySpeakerTypeDiscoverPeripheralsDiscoverDescriptorsForCharacteristic,
    BabySpeakerTypeDiscoverPeripheralsReadValueForDescriptorsBlock
}

@implementation BabySpeaker {
    // 所有委托频道
    NSMutableDictionary *channels;
    // 当前委托频道
    NSString *currChannel;
    //notify list
    NSMutableDictionary *notifyList;
}

- (instancetype)init {
    self = [super init];
    if (self) {
      BabyCallback *defaultCallback = [[BabyCallback alloc] init];
      notifyList = [[NSMutalbeDictionary alloc] init];
      channels = [[NSMutableDictionary alloc] init];
      currChannel = KBABY_DEFAULT_CHANNEL;
      [channels setObject:defaultCallback forKey:KBABY_DEFAULT_CHANNEL];
    }
    return self;
}

- (BabyCallback *)callback {
    return [channels objectForKey:channel];
}

- (BabyCallback *)callbackOnCurrChannel {
  return [self callbackOnChnnel:currChannel];
}

- (BabyCallback *)callbackOnChannel:(NSString *)channel {
  if (!channel) {
      return [self callback];
  }
  return [channels objectForKey:channel];
}

- (BabyCallback *)callbackOnCurrChannel:(NSString *)channel {
    return [self callbackOnChnnel:currChannel];
}

- (BabyCallback *)callbackOnChnnel:(NSString*)channel
                  createWhenExist:(BOOL)createWhenNotExist {          
         BabyCallback *callback = [channels objectForKey:channel];
         if (!callback && createWhenNotExist) {
            callback = [[BabyCallback alloc] init];
            [channels setObject:callback forKey:channel];
         }
         return callback;
 }

- (void)switchChannel:(NSString *)channel {
  if (channel) {
      if ([self callbackOnChnnel:channel]) {
        currChannel = channel;
        BabyLog(@">>>已切换到%@", channel);
      }
      else {
        BabyLog(@">>>所要切换的channel不存在");
      }
  }
  else {
       currChannel = KBABY_DEFAULT_CHANNEL;
        BabyLog(@">>>已切换到默认值");
  }
}

// 添加到 notify list
- (void)addNotifyCallback:(CBCharacteristic *)c withBlock:(void(^)(CBPeripheral *peripheral, CBCharaterstic *characteristics, NSError *error))block {
     [notifyList setObject:block forKey:c.UUID.description];
}

// 从notifylist 中移除
- (void)removeNotifyCallback:(CBCharacteristic *)c {
      [notifyList removeObjectForKey:c.UUID.description];
}

// 获取notify List
- (NSMutableDictionary *)notifyCallback {
  return notifyList;
}

// 获取 notifyBlock
- (void(^)(CBPeripheral *peripheral, CBCharacteristic *characteristic, NSError *error)) notifyCallback:(CBCharacteristic *)c {
  return [notifyList objectForKey:c.UUID.description];
}



// 








@end
