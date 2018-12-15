//
//  XHMacro.h
//  HJKit
//
//  Created by xiaohj on 2018/12/15.
//  Copyright © 2018年 xiaohj. All rights reserved.
//

#ifndef XHMacro_h
#define XHMacro_h

#pragma mark- 屏幕相关
    //屏幕相关
#define XHScreenWidth [UIScreen mainScreen].bounds.size.width
#define XHScreenHeight  [UIScreen mainScreen].bounds.size.height
#define XHIOS(float) @available(iOS (float), *)
#define XHIOS11   @available(iOS 11.0, *)
#define ISiPhoneX \({BOOL isPhoneX = NO;\if (@available(iOS11.0, *)) {\isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom >0.0;\}\(isPhoneX);})
#define XHStatusBar_Height      [[UIApplication sharedApplication] statusBarFrame].size.height
#define XHNavigationBar_Height   (ISiPhoneX  ?  88 : 64)
#define XHTabBar_Height         (ISiPhoneX ? 83.f : 49.f)
#define XHScreen_Bounds         [UIScreen mainScreen].bounds
    // 底部安全区域远离高度
#define kBottomSafeHeight  (CGFloat)(ISiPhoneX?(34):(0))

#pragma mark- 系统对象
    //APP对象 （单例对象）
#define XHApplication [UIApplication sharedApplication]
    //主窗口 （keyWindow）
#define XHKeyWindow [UIApplication sharedApplication].keyWindow
    //NSUserDefaults实例化
#define XHUserDefaults [NSUserDefaults standardUserDefaults]
    //通知中心 （单例对象）
#define XHNotificationCenter [NSNotificationCenter defaultCenter]
    //APP版本号
#define XHVersion [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]
    //系统版本号
#define XHSystemVersion [[UIDevice currentDevice] systemVersion]

    //永久存储对象
#define XHSetUserDefaults(object, key)                                                                                                 \
({                                                                                                                                             \
NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults];                                                                         \
[defaults setObject:object forKey:key];                                                                                                    \
[defaults synchronize];                                                                                                                    \
})
    //获取对象
#define XHGetUserDefaults(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
    //删除某一个对象
#define XHRemoveUserDefaults(key)                                         \
({                                                                          \
NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];       \
[defaults removeObjectForKey:_key];                                     \
[defaults synchronize];                                                 \
})
    //清除 NSUserDefaults 保存的所有数据
#define XHRemoveAllUserDefaults  [[NSUserDefaults standardUserDefaults] removePersistentDomainForName:[[NSBundle mainBundle] bundleIdentifier]]

#pragma mark- GCD
    //GCD - 一次性执行
#define XHDisPatch_Once_Block(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

    //GCD - 在Main线程上运行
#define XHDisPatch_Main_Thread(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

    //GCD - 开启异步线程
#define XHDisPatch_Global_Queue(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);

#pragma mark- 沙盒路径
    //获取沙盒 temp
#define XHPathTemp NSTemporaryDirectory()
    //获取沙盒 Document
#define XHPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
    //获取沙盒 Cache
#define XHPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
    //Library/Caches 文件路径
#define XHFilePath ([[NSFileManager defaultManager] URLForDirectory:NSCachesDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:YES error:nil])

#pragma mark- 判空
    //字符串是否为空
#define XHIsNullString(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
    //如果是空字符串对象，就返回@“” 不是就返回原来的
#define XHNullString(str) (XHIsNullString(str) ? @"" : str )
    //数组是否为空
#define XHIsNullArray(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0 ||[array isEqual:[NSNull null]])
    //字典是否为空
#define XHIsNullDict(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0 || [dic isEqual:[NSNull null]])
    //是否是空对象
#define XHIsNullObject(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))


#pragma mark- 引用
    //弱引用
#define XHWeakSelf(type) __weak typeof(type)weak##type = type;
    //强引用
#define XHStrongSelf(type)__strong typeof(type)type = weak##type;

#pragma mark- View圆角和加边框
    //View圆角和加边框
#define XHViewBorderRadius(View,Radius,Width,Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

    // View圆角
#define XHViewRadius(View,Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

#pragma mark- property属性快速声明
    //property属性快速声明
#define XHPropertyString(s) @property(nonatomic,copy) NSString * s
#define XHPropertyNSInteger(s) @property(nonatomic,assign) NSInteger s
#define XHPropertyFloat(s) @property(nonatomic,assign) float s
#define XHPropertyLongLong(s) @property(nonatomic,assign) long long  s
#define XHPropertyNSDictionary(s) @property(nonatomic,strong) NSDictionary * s
#define XHPropertyNSArray(s) @property(nonatomic,strong) NSArray * s
#define XHPropertyNSMutableArray(s) @property(nonatomic,strong) NSMutableArray * s

#pragma mark- 打印日志
    //DEBUG模式下打印日志,当前行
#ifdef DEBUG

#define XHLog(fmt,...)NSLog((@"%s[Line %d]" fmt),__PRETTY_FUNCTION__,__LINE__,##__VA_ARGS__);

#else

#define XHLog(...)

#endif

#pragma mark- 拼接字符串
    //拼接字符串
#define XHNSStringFormat(format,...)[NSString stringWithFormat:format,##__VA_ARGS__]

#pragma mark- 颜色
    //RGB格式
#define XHRGB(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define XHRGBSame(float) [UIColor colorWithRed:(float)/255.0 green:(float)/255.0 blue:(float)/255.0 alpha:1.0]
    //RGBA格式
#define XHRGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define XHRGBASame(float,a) [UIColor colorWithRed:(float)/255.0 green:(float)/255.0 blue:(float)/255.0 alpha:a]

#define XHClearColor[UIColor clearColor]
#define XHWhiteColor[UIColor whiteColor]
#define XHBlackColor[UIColor blackColor]
#define XHGrayColor[UIColor grayColor]
#define XHGray2Color[UIColor lightGrayColor]
#define XHBlueColor[UIColor blueColor]
#define XHRedColor[UIColor redColor]
#define XHRandomColorKRGBColor(arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0)//随机色生成

#pragma mark- 字体
    //字体
#define XHBoldFont(size) [UIFont boldSystemFontOfSize:size]
#define XHFont(size) [UIFont systemFontOfSize:size]
#define XHNameFont(name,size)[UIFont fontWithName:(name) size:(size)]
#define XHFont_12 XHFont(12)
#define XHFont_13 XHFont(13)
#define XHFont_14 XHFont(14)
#define XHFont_15 XHFont(15)
#define XHFont_16 XHFont(16)
#define XHFont_17 XHFont(17)
#define XHFont_20 XHFont(20)


#pragma mark- 单例化一个类
    //单例化一个类
#define SingletonHeader(className)\
\
+(className *)shared##className;

#define SingletonClass(className)\
\
+(className *)shared##className { \
static className *shared##className = nil;\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken,^{ \
shared##className =[[self alloc]init];\
});\
return shared##className;\
}

#endif /* XHMacro_h */
