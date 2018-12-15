//
//  UITextField+DDtextField.h
//  UIViewControllerCategory
//
//  Created by Dry on 2017/7/31.
//  Copyright © 2017年 Dry. All rights reserved.
//
//  出自https://github.com/shaojiankui/JKCategories
//
//  项目中对UITextField的扩展，限制输入长度等
//

#import <UIKit/UIKit.h>

@interface UITextField (DDtextField)

@property (assign, nonatomic) NSInteger limitMaxLength;//if <=0, no limit

@end
