//
//  UILabel+XHAdd.h
//  HJKit
//
//  Created by xiaohj on 2018/12/15.
//  Copyright © 2018年 xiaohj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UILabel (XHAdd)

+(UILabel *)initLabelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)textColor;

+(UILabel *)initLabelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)textColor textAlignment:(NSTextAlignment)textAlignment;

@end

NS_ASSUME_NONNULL_END
