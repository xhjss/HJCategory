//
//  UIView+Animation.m
//  UIViewAnimationDemo
//
//  Created by Dry on 2017/7/29.
//  Copyright © 2017年 Dry. All rights reserved.
//

#import "UIView+Animation.h"

@implementation UIView (Animation)

/**
 震动动画
 
 @param times 震动次数     8
 @param duration 震动时间  0.5
 @param amplitude 震动幅度 0.03
 */
- (void)shakeAnimationWithTimes:(NSUInteger)times
                       duration:(float)duration
                      amplitude:(float)amplitude
                         forKey:(nonnull NSString *)key
{
    CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"position"];
    
    CGFloat width = CGRectGetWidth(self.frame);
    CGFloat midX = CGRectGetMidX(self.frame);
    CGFloat midY = CGRectGetMidY(self.frame);
    
    CGMutablePathRef shakePath = CGPathCreateMutable();
    CGPathMoveToPoint(shakePath, NULL, midX, midY);
    for (int i = 0; i < times; i++)
    {
        CGPathAddLineToPoint(shakePath, NULL, width - width * amplitude, midY);
        CGPathAddLineToPoint(shakePath, NULL, midX + width * amplitude, midY);
    }
    CGPathCloseSubpath(shakePath);
    animation.path = shakePath;
    animation.duration = duration;
    CFRelease(shakePath);
    
    [self.layer addAnimation:animation forKey:key];
}

/**
 伸缩变化
 
 @param repeatCount 动画重复次数 HUGE表示无限循环
 @param duration 动画时长 1.5
 @param scaleValue 放大（缩小）倍数 1.5
 @param key key
 */
- (void)scallEnlargeAndReductionWithRepeateCount:(NSUInteger)repeatCount
                                        duration:(float)duration
                                    enlargeScale:(float)scaleValue
                                          forKey:(nonnull NSString *)key {
    CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"transform"];
    
    NSMutableArray *values = [[NSMutableArray alloc] init];
    [values addObject:[NSValue valueWithCATransform3D:CATransform3DMakeScale(1, 1, 1.0)]];
    [values addObject:[NSValue valueWithCATransform3D:CATransform3DMakeScale(1.3, 1.3, 1.0)]];
    [values addObject:[NSValue valueWithCATransform3D:CATransform3DMakeScale(1, 1, 1.0)]];
    
    animation.values = values;
    animation.duration = duration;
    animation.repeatCount = repeatCount;

    [self.layer addAnimation:animation forKey:key];
}


/**
 移除
 
 @param key 动画对应的key
 */
- (void)removeAnimationForKey:(nonnull NSString *)key {
    [self.layer removeAnimationForKey:key];
}

@end
