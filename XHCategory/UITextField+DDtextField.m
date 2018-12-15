//
//  UITextField+DDtextField.m
//  UIViewControllerCategory
//
//  Created by Dry on 2017/7/31.
//  Copyright © 2017年 Dry. All rights reserved.
//

#import "UITextField+DDtextField.h"
#import <objc/runtime.h>

static const void *JKTextFieldInputLimitMaxLength = &JKTextFieldInputLimitMaxLength;

@implementation UITextField (DDtextField)

- (NSInteger)limitMaxLength {
    return [objc_getAssociatedObject(self, JKTextFieldInputLimitMaxLength) integerValue];
}

- (void)setLimitMaxLength:(NSInteger)limitMaxLength {
    objc_setAssociatedObject(self, JKTextFieldInputLimitMaxLength, @(limitMaxLength), OBJC_ASSOCIATION_ASSIGN);
    [self addTarget:self action:@selector(jk_textFieldTextDidChange) forControlEvents:UIControlEventEditingChanged];
}

- (void)jk_textFieldTextDidChange {
    NSString *toBeString = self.text;
    //获取高亮部分
    UITextRange *selectedRange = [self markedTextRange];
    UITextPosition *position = [self positionFromPosition:selectedRange.start offset:0];
    
    //没有高亮选择的字，则对已输入的文字进行字数统计和限制
    //在iOS7下,position对象总是不为nil
    if ( (!position ||!selectedRange) && (self.limitMaxLength > 0 && toBeString.length > self.limitMaxLength))
    {
        NSRange rangeIndex = [toBeString rangeOfComposedCharacterSequenceAtIndex:self.limitMaxLength];
        if (rangeIndex.length == 1)
        {
            self.text = [toBeString substringToIndex:self.limitMaxLength];
        }
        else
        {
            NSRange rangeRange = [toBeString rangeOfComposedCharacterSequencesForRange:NSMakeRange(0, self.limitMaxLength)];
            NSInteger tmpLength;
            if (rangeRange.length > self.limitMaxLength) {
                tmpLength = rangeRange.length - rangeIndex.length;
            }else{
                tmpLength = rangeRange.length;
            }
            self.text = [toBeString substringWithRange:NSMakeRange(0, tmpLength)];
        }
    }
}

@end
