//
//  UIView+Animation.h
//  UIViewAnimationDemo
//
//  Created by Dry on 2017/7/29.
//  Copyright © 2017年 Dry. All rights reserved.
//
//  这是对UIView进行扩展动画实现的方法，以方便项目中直接使用
//  注释的参数后面的描述文字可能会包含参考数值等
//  其中-(void)removeAnimationForKey:方法是移除layer上的动画的方法，执行完动画
//  之后还应该调用此方法
//
//


#import <UIKit/UIKit.h>

@interface UIView (Animation)

#pragma mark - position
/**
 震动动画
 
 @param times 震动次数     8
 @param duration 震动时间  0.5
 @param amplitude 震动幅度 0.03
 @param key key
 */
- (void)shakeAnimationWithTimes:(NSUInteger)times
                       duration:(float)duration
                      amplitude:(float)amplitude
                         forKey:(nonnull NSString *)key;

#pragma mark - transform

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
                                          forKey:(nonnull NSString *)key;



/**
 移除

 @param key 动画对应的key
 */
- (void)removeAnimationForKey:(nonnull NSString *)key;


@end
