#import "BabyRhythm.h"
#import "BabyDefine.h"

@implementation BabyRhythm {
  
    Bool isOver;  // 是否结束
    BBBeatsBreakBlock blockOnBeatBreak; // 心跳中断的block
    BBBeatsOverBlock  blockOnBeatOver;  // 心跳结束的委托

}

- (instancetype)init {

  self = [super init];
  if (self) {
    //  设置默认心跳时间间隔
    _beatsInteval = KBABYRHYTHM_BEATS_DEFAULT_INTERVAL;
  }
}

- (void)beats {
  
  if (isOver) {
    BabyLog(@">>>>beats isOver");
  }
  BabyLog(@">>>>beats at :%@", [NSDate date]);
  
  if (self.beatsTimer) {
  
    [self.beatsTimer setFireDate:[[NSDate date] dateByAddingTimeInterval:self.beatsInterval]];
  
  }
  else {
    self.beatsTimer = [NSTimer timerWithTimeInterval:self.beatsInterval target:self selector:@selector(beatsBreak) userInfo:nil repeats:YES];
    [self.beatsTimer setFireDate:[[NSDate date] dateByAddingTimeInterval:self.beatsInterval]];
    [[NSRunLoop currentRunLoop] addTimer:self.beatsTimer forMode:NSRunLoopCommonModes];
  }
}

- (void)beatsBreak {
      BabyLog(@">>> beatsBreak:@", [NSDate date]);
      [self.beatsTimer setFireDate:[NSDate distantFuture]];
      if (blockOnBeatBreak) {
        blockOnBeatBreak(self);
      }
}

- (void)beatsOver {
  BabyLog(@">>> beatsOver :%@", [NSDate date]);
  [self.beatsTimer setFireDate:[NSDate distantFuture]];
  isOver = YES;
  if (blockOnBeatOver) {
    blockOnBeatOver(self);
  }
}

- (void)beatsRestart {
  BabyLog(@">>>>beatsRestart  :@", [NSDate date]);
  isOver = NO;
  [self beats];
}

- (void)setBlockOnBeatsBreak:(void(^)(BabyRhythm *bry))block {
  blockOnBeatBreak = block;
}

- (void)setBlockOnBeatsOver:(void(^)(BabyRhythm *bry))block {
  blockOnBeatOver = block;
}

@end
