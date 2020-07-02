//
//  MNFCQualityOptions.h
//  MomoNext
//
//  Created by MOMO on 2019/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 人脸质量检测配置
 */
@interface MNFCQualityOptions : NSObject <NSCopying>

@property (nonatomic, assign) BOOL detectStrict;        //default is YES
@property (nonatomic, assign) BOOL livenessDetect;      //default is YES
@property (nonatomic, assign) BOOL motionBlurDetect;    //default is YES
@property (nonatomic, assign) BOOL faceOcclusionDetect; //default is YES
@property (nonatomic, assign) float motionBlurResultThreshold;

- (void)setStrictMode:(BOOL)isStrict;

- (void)copyWithQualityOptions:(MNFCQualityOptions *)qualityOptions;

@end

NS_ASSUME_NONNULL_END
