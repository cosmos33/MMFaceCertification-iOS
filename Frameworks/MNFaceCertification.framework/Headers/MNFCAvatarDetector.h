//
//  MNFCAvatarDetector.h
//  MomoNext
//
//  Created by MOMO on 2019/5/9.
//

#import "MNFCBasicDetector.h"
#import "MNFCOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 头像检测器
 用于提取头像图片中的人脸特征
 */

@interface MNFCAvatarDetector : MNFCBasicDetector

+ (nullable instancetype)makeDetector; // 自动加载算法模型
+ (void)asyncMakeDetector:(void(^)(MNFCAvatarDetector * _Nullable detector))completionHandler;


/**
 处理图片

 @param image 图片
 @param resultBlock 处理结果
 */
- (void)processImage:(UIImage *)image
         resultBlock:(void(^__nullable)(MNSampleImage * _Nullable mnImage))resultBlock;

/**
 批量处理图片

 @param images 图片数组
 @param resultBlock 处理结果
 */
- (void)processImages:(NSArray<UIImage *> *)images
         resultBlock:(void(^__nullable)(NSArray<MNSampleImage *> * _Nullable mnImages))resultBlock;

@end

NS_ASSUME_NONNULL_END
