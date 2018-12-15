//
//  UIButton+DDButton.h
//  CategoryTest
//
//  Created by Dry on 2017/7/26.
//  Copyright © 2017年 Dry. All rights reserved.
//
//  这里是给UIButton写的一个类目，用来扩展系统的UIButton的方法，更好的满足我们的项目需要。
//  如果需要给UIButton成员变量，则需要在此类目中写成员变量的set和get方法。
//  ClickSize是自定义的结构体，用来设置扩大范围。
//  
//

#import <UIKit/UIKit.h>

/* ClickArea.
 *  点击区域结构体
 */
struct ClickSize {
    CGFloat top;
    CGFloat left;
    CGFloat bottom;
    CGFloat right;
};
typedef struct ClickSize ClickSize;

CG_INLINE ClickSize
ClickSizeMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right)
{
    ClickSize clickSize;
    clickSize.top = top;
    clickSize.left = left;
    clickSize.bottom = bottom;
    clickSize.right = right;
    return clickSize;
};


@interface UIButton (DDButton)



/**
 扩大button的点击范围

 @param size 设置点击区域，控制上、左、下、又的扩大外围
 */
- (void)enlargeClickAreaWithClickArea:(ClickSize)size;



/**
 设置button不同状态下的色值

 @param backgroundColor UIColor
 @param state UIControlState
 */
- (void)setBackgroundColor:(UIColor *)backgroundColor forState:(UIControlState)state;


@end
