//
//  UIImage+DDImage.h
//  DingDing
//
//  Created by Dry on 2017/8/2.
//  Copyright © 2017年 Cstorm. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (DDImage)

/**
 *  根据颜色生成响应的图片
 *
 * @param color 颜色值
 *
 * @return 返回图片对象
 */
+ (UIImage *)imageWithColor_Ext:(UIColor *)color;

/**
 *	加载图片
 *  @param name 图片的名字,会自动在图片后缀上添加“topic_Ext”,"UIApplication+Extension"的扩展的字段
 *  @return 返回图片对象
 */
+ (UIImage *)imageNamed_Ext:(NSString *)name;

/**
 *  将UIImage缩放到指定大小尺寸
 *
 * @param size 得到的图片尺寸大小
 *
 * @return 图片对象
 */
- (UIImage *)imageZoomToSize_Ext:(CGSize)size;

/**
 *  按比例， 将UIImage“按比例”缩放到指定大小尺寸
 *
 * @param size 指定图片的大小
 *
 * @return 图片对象
 */
-(UIImage *) imageScalZoonToSize_Ext:(CGSize)size;

/**
 *  按比例， 将UIImage“按比例”缩放到指定大小尺寸
 *
 * @param defineWidth 指定图片的宽度
 *
 * @return 图片对象
 */
-(UIImage *) imageScalZoonToWidth_Ext:(CGFloat)defineWidth;


/**
 * 将图片切成圆角图片
 *
 * @param size 返回图片的大小
 * @param r 圆角的大小
 *
 * @return 图片对象
 */
- (UIImage *)imageWithRoundedSize:(CGSize)size radius:(NSInteger)r;

/*压缩图片*/
-(UIImage*)scaleToSize:(CGSize)size;

/**
 *  压缩图片
 *  image:将要压缩的图片   size：压缩后的尺寸
 */
-(UIImage*)OriginImage:(UIImage *)image scaleToSize:(CGSize)size;
/**
 *  压缩图片到指定尺寸大小
 *
 *  @param image 原始图片
 *  @param size  目标大小
 *
 *  @return 生成图片
 */
-(UIImage *)compressOriginalImage:(UIImage *)image toSize:(CGSize)size;
/**
 *  压缩图片到指定文件大小
 *
 *  @param image 目标图片
 *  @param size  目标大小（最大值）
 *
 *  @return 返回的图片文件
 */
- (NSData *)compressOriginalImage:(UIImage *)image toMaxDataSizeKBytes:(CGFloat)size;
// 压缩图片到指定文件大小
-(UIImage*)imageByScalingAndCroppingForSize:(CGSize)targetSize;
/*
 UIImage *animation = [UIImage animatedImageWithAnimatedGIFData:theData];
 
 I interpret `theData` as a GIF.  I create an animated `UIImage` using the source images in the GIF.
 
 The GIF stores a separate duration for each frame, in units of centiseconds (hundredths of a second).  However, a `UIImage` only has a single, total `duration` property, which is a floating-point number.
 
 To handle this mismatch, I add each source image (from the GIF) to `animation` a varying number of times to match the ratios between the frame durations in the GIF.
 
 For example, suppose the GIF contains three frames.  Frame 0 has duration 3.  Frame 1 has duration 9.  Frame 2 has duration 15.  I divide each duration by the greatest common denominator of all the durations, which is 3, and add each frame the resulting number of times.  Thus `animation` will contain frame 0 3/3 = 1 time, then frame 1 9/3 = 3 times, then frame 2 15/3 = 5 times.  I set `animation.duration` to (3+9+15)/100 = 0.27 seconds.
 * 播放GIF图片，放到imageView里面自动播放；
 * @param theData GIF图片的data
 * @return 返回一个GIF的图片
 */
+ (UIImage *)animatedImageWithAnimatedGIFData_Ext:(NSData *)theData;

/*
 UIImage *image = [UIImage animatedImageWithAnimatedGIFURL:theURL];
 
 I interpret the contents of `theURL` as a GIF.  I create an animated `UIImage` using the source images in the GIF.
 
 I operate exactly like `+[UIImage animatedImageWithAnimatedGIFData:]`, except that I read the data from `theURL`.  If `theURL` is not a `file:` URL, you probably want to call me on a background thread or GCD queue to avoid blocking the main thread.
 * 播放GIF图片，放到imageView里面自动播放；
 * @param theURL GIF图片的URL
 * @return 返回一个GIF的图片
 */
+ (UIImage *)animatedImageWithAnimatedGIFURL_Ext:(NSURL *)theURL;

- (UIImage*)imageWithCornerRadius:(CGFloat)radius;


@end
