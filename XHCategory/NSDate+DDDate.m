//
//  NSDate+DDDate.m
//  UIViewControllerCategory
//
//  Created by Dry on 2017/8/1.
//  Copyright © 2017年 Dry. All rights reserved.
//

#import "NSDate+DDDate.h"

@implementation NSDate (DDDate)

/// 返回传入日期是其所在年份中的第几周
+ (NSInteger)weeksInCurrentYear:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:NSCalendarUnitWeekOfYear fromDate:date];
    NSInteger weeks = [components weekOfYear];//这个年的第几周
    return weeks;
}


/// 返回当前日期是其所在月份的第几周
+ (NSInteger)weeksInCurrentMoth:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:NSCalendarUnitWeekOfMonth fromDate:date];
    NSInteger weeks = [components weekOfMonth];//这个月的第几周
    return weeks;
}


/// 返回传入日期是周几
+ (NSString *)weekOfDay:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitWeekday fromDate:date];
    //获取今天是这一周的第几天（第一天是周天，第二天是周一）
    NSInteger dayInteger = [components weekday];
    NSArray *weeks = @[@"周日",@"周一",@"周二",@"周三",@"周四",@"周五",@"周六"];
    if (dayInteger <= weeks.count) {
        return weeks[dayInteger-1];
    }
    return @"";
}

/// 获取传入日期所在周的周一和周天日期
+ (NSArray *)dateWithFirstAndLastInThisWeek:(NSDate *)date {
    //获取日历
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitWeekday fromDate:date];
    //获取今天是这一周的第几天（第一天是周天，第二天是周一）
    NSInteger weekDay = [components weekday];
    //获取今天是几号
    NSInteger day = [components day];
    //将这周的天数按照数字对应，今天是0，比如（-3，-2，-1，0，1，2，3，0代表今天，-1代表昨天，1代表明天）
    //firstDiff代表这周第一天的数字，lastDiff这周最后一天的数字
    long firstDiff,lastDiff;
    //如果今天是这一周的第一天（周天）
    if (weekDay == 1)
    {
        firstDiff = -6;
        lastDiff = 0;
    }
    else
    {
        //将周一设置成第一天
        firstDiff = [calendar firstWeekday] - weekDay + 1;
        //最后一天
        lastDiff = 8 - weekDay;
    }
    
    //在当前日期(去掉时分秒)基础上加上差的天数
    [components setDay:day + firstDiff];
    NSDate *firstDayOfWeek = [calendar dateFromComponents:components];
    
    [components setDay:day + lastDiff];
    NSDate *lastDayOfWeek = [calendar dateFromComponents:components];
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"YYYY-MM-dd"];
    
    NSString *firstDay = [formatter stringFromDate:firstDayOfWeek];
    NSString *lastDay = [formatter stringFromDate:lastDayOfWeek];
    
    NSArray *returnArr = @[firstDay,lastDay];
    
    return returnArr;
}

/// date转字符串
+ (NSString *)dateStringWithDate:(NSDate *)date dateFormat:(NSString *)dateFormat {
    NSDateFormatter *format = [[NSDateFormatter alloc] init];
    if (dateFormat && dateFormat.length) {
        format.dateFormat = dateFormat;
    } else {
        format.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    }
    return [format stringFromDate:date];
}


/// 返回月日
+ (NSString *)dateWithMonthAndDayFormat:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = nil;
    components = [calendar components:NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay fromDate:date];
    
    NSInteger month = components.month;
    NSInteger day = components.day;
    
    return [self dateWithMonth:month day:day];
}
+ (NSString *)dateWithMonth:(NSInteger)month day:(NSInteger)day {
    if( month==2 ){
        if( day>28 ){
            month++;
            day = 1;
        }
    }else if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 ){
        if( day>31 ){
            month++;
            if( month>12 ){
                month = 1;
            }
            day = 1;
        }
    }else{
        if( day>30 ){
            month++;
            day = 1;
        }
    }
    return [NSString stringWithFormat:@"%ld月%ld日",(long)month,(long)day];
}

@end
