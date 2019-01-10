//
//  UIImageView+HTSDWebImage.h
//  HTSDWebImage
//
//  Created by xiaoweihe on 2019/1/10.
//  Copyright © 2019 hengtiansoft. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  监听下载成功的Block
 *
 *  @param image 返回下载成功的图片
 */
typedef void(^DownImageSuccessBlock)(UIImage *image);
/**
 *  监听下载失败的Block
 *
 *  @param error 返回错误信息
 */
typedef void(^DownImageFailedBlock)(NSError *error);
/**
 *  监听下载进度的Block
 *
 *  @param progress 返回下载进度
 */
typedef void(^DownImageProgressBlock)(CGFloat progress);

@interface UIImageView (HTSDWebImage)

/**
 *  异步加载图片
 *
 *  @param urlStr    图片地址
 *  @param imageName 占位图片名字
 */
- (void)downloadImage:(NSString *)urlStr placeholder:(NSString *)imageName;

/**
 *  异步加载图片，监听下载进度、成功、失败
 *
 *  @param urlStr    图片地址
 *  @param imageName 占位图片名字
 *  @param success   下载成功
 *  @param failed    下载失败
 *  @param progress  下载进度
 */
- (void)downloadImage:(NSString *)urlStr placeholder:(NSString *)imageName success:(DownImageSuccessBlock)success failed:(DownImageFailedBlock)failed progress:(DownImageProgressBlock)progress;
@end

NS_ASSUME_NONNULL_END
