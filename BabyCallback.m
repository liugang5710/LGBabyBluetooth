#import "BabyCallback.h"

@implementation BabyCallback

- (instancetype)init {
  
  self = [super init];
  if (self) {
      
      [self setFilterOnDiscoverPeripherals:^Bool(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI) {
        
        if(![peripheralName isEqualToString:@""]) {
          
          return YES;
        }
        return NO;
      
      }];
      
      
      [self setFilterOnConnectToPeriphearls:^Bool(NSString *peripheralName, NSDictionary *advertisementData, NSNumer *RSSI){
      
          if (![peripheralName isEqualToString:@""]) {
              return YES;
          }
          return NO;
      }];
  }
  return self;
}

@end
