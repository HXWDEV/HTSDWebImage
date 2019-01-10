//
//  UIImageView+HTSDWebImage.m
//  HTSDWebImage
//
//  Created by xiaoweihe on 2019/1/10.
//  Copyright © 2019 hengtiansoft. All rights reserved.
//

#import "UIImageView+HTSDWebImage.h"
#import "UIImageView+WebCache.h"
//#import <UIImageView+WebCache.h>

@implementation UIImageView (HTSDWebImage)
- (void)downloadImage:(NSString *)urlStr placeholder:(NSString *)imageName {
    
    [self sd_setImageWithURL:[NSURL URLWithString:urlStr] placeholderImage:[UIImage imageNamed:imageName] options:SDWebImageRetryFailed|SDWebImageLowPriority];
}

- (void)downloadImage:(NSString *)urlStr placeholder:(NSString *)imageName success:(DownImageSuccessBlock)success failed:(DownImageFailedBlock)failed progress:(DownImageProgressBlock)progress {
    
    [self sd_setImageWithURL:[NSURL URLWithString:urlStr] placeholderImage:[UIImage imageNamed:imageName] options:SDWebImageRetryFailed|SDWebImageLowPriority progress:^(NSInteger receivedSize, NSInteger expectedSize, NSURL * _Nullable targetURL) {
        progress(receivedSize * 1.0 / expectedSize);
    } completed:^(UIImage * _Nullable image, NSError * _Nullable error, SDImageCacheType cacheType, NSURL * _Nullable imageURL) {
        if (error) {
            failed(error);
        } else {
            self.image = image;
            success(image);
        }
    }];
}
@end
