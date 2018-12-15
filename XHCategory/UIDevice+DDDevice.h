//
//  UIDevice+DDDevice.h
//  DingDing
//
//  Created by Dry on 2017/8/2.
//  Copyright © 2017年 Cstorm. All rights reserved.
//
//  摘抄自（https://github.com/fahrulazmi/UIDeviceHardware/blob/master/UIDeviceHardware.m）
//


#import <UIKit/UIKit.h>

@interface UIDevice (DDDevice)

//mac address
+ (NSString *)macAddress;

//Return the current device CPU frequency
+ (NSUInteger)cpuFrequency;

//Return the current device BUS frequency
+ (NSUInteger)busFrequency;

//current device RAM size
+ (NSUInteger)ramSize;

//Return the current device CPU number
+ (NSUInteger)cpuNumber;


/// 获取手机内存总量, 返回的是字节数
+ (NSUInteger)totalMemoryBytes;
/// 获取手机可用内存, 返回的是字节数
+ (NSUInteger)freeMemoryBytes;

/// 获取手机硬盘空闲空间, 返回的是字节数
+ (long long)freeDiskSpaceBytes;
/// 获取手机硬盘总空间, 返回的是字节数
+ (long long)totalDiskSpaceBytes;


/// 获取iOS系统的版本号
+ (NSString *)systemVersion;

@end
