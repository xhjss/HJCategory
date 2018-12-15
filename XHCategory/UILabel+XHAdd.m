//
//  UILabel+XHAdd.m
//  HJKit
//
//  Created by xiaohj on 2018/12/15.
//  Copyright © 2018年 xiaohj. All rights reserved.
//

#import "UILabel+XHAdd.h"

@implementation UILabel (XHAdd)

+(UILabel *)initLabelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)textColor
{
    return [self initLabelWithText:text font:font textColor:textColor textAlignment:NSTextAlignmentLeft];
}

+(UILabel *)initLabelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)textColor textAlignment:(NSTextAlignment)textAlignment;
{
    UILabel *label = [UILabel new];
    label.text = text;
    label.font = font;
    label.textColor = textColor;
    label.textAlignment = textAlignment;
    return label;
}


@end
