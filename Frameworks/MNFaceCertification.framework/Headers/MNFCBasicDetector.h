//
//  MNFCBasicDetector.h
//  MomoNext
//
//  Created by MOMO on 2019/4/28.
//

#import <Foundation/Foundation.h>
#import "MNSampleFace.h"
#import "MNSampleImage.h"
#import "MNFCConstant.h"

NS_ASSUME_NONNULL_BEGIN

/**
 人脸检测器基类
 */

@class MMFaceDetector;
@class MMFaceQualityDetector;
@interface MNFCBasicDetector : NSObject

- (BOOL)detectorLoaded; // 判断检测器是否加载完成

/**
 使用之前必须加载对应检测器

 @param faceDetector 脸部检测器
 @param faceQualityDetector 脸部质量检测器
 */
- (void)loadFaceDetector:(MMFaceDetector *)faceDetector
     faceQualityDetector:(MMFaceQualityDetector * _Nullable)faceQualityDetector;

@end

NS_ASSUME_NONNULL_END
