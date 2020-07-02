//
//  MNSampleFace.h
//  MomoNext
//
//  Created by MOMO on 2019/5/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MMFaceFeature;
@interface MNSampleFace : NSObject <NSCopying>

@property (nonatomic, readonly) NSInteger trackID;

/**
 *  @faceRect 人脸位置，裁剪过，相对原PixelBuffer
 */
@property (nonatomic) CGRect rect;

/**
 *  @faceRect 人脸位置, 相对渲染视图
 */
@property (nonatomic) CGRect faceRect;

/**
 *  姿态角
 */
@property (nonatomic, readonly) double yaw;
@property (nonatomic, readonly) double pitch;
@property (nonatomic, readonly) double roll;

/**
 *  96特征点
 */
@property (nonatomic, readonly) NSArray <NSValue*> *landmarks;

@property (nonatomic, readonly) MMFaceFeature *faceFeature;

/**
 *  @feature 图片提起Face的特征数据
 */
@property (nonatomic, nullable, copy) NSData *feature;

@property (nonatomic, assign) BOOL faceInLimitRect;

+ (NSArray<MNSampleFace *> *)sampleFacesWithFaceFeatures:(NSArray<MMFaceFeature *> *)faceFeature;

- (instancetype)initWithFaceFeature:(MMFaceFeature *)faceFeature;

@end

@class MMPB_MNFace;
@interface MNSampleFace (MNProtobuf)

- (MMPB_MNFace *)pbFace;

@end

NS_ASSUME_NONNULL_END
