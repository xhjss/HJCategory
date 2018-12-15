//
//  NSDate+DDDate.h
//  UIViewControllerCategory
//
//  Created by Dry on 2017/8/1.
//  Copyright © 2017年 Dry. All rights reserved.
//
//  项目NSDate分类，扩展关于日期的方法
//
//

#import <Foundation/Foundation.h>

@interface NSDate (DDDate)

#pragma mark 周
/**
 返回传入日期是其所在年份中的第几周

 @param date 传入日期
 @return date时间所在的年的第几周
 */
+ (NSInteger)weeksInCurrentYear:(NSDate *)date;
/**
 返回当前日期是其所在月份的第几周

 @param date 传入日期
 @return date时间所在月份的第几周
 */
+ (NSInteger)weeksInCurrentMoth:(NSDate *)date;
/**
 返回传入日期是周几

 @param date 传入日期
 @return 周，例如：周一
 */
+ (NSString *)weekOfDay:(NSDate *)date;




#pragma mark 日期字符串
/**
 获取传入日期所在周的周一和周天日期
 
 @param date 传入date
 @return 返回周一和周日的日期数组@[@"该周周一日期",@"该周周天日期"]，格式：
 */
+ (NSArray *)dateWithFirstAndLastInThisWeek:(NSDate *)date;
/**
 将date转化成对应格式的字符串

 @param date 传入date
 @param dateFormat 默认是yyyy-MM-dd HH:mm:ss
 @return 时间字符串
 */
+ (NSString *)dateStringWithDate:(NSDate *)date dateFormat:(NSString *)dateFormat;
/**
 返回月日

 @param date date
 @return 例如5月10日
 */
+ (NSString *)dateWithMonthAndDayFormat:(NSDate *)date;

@end
