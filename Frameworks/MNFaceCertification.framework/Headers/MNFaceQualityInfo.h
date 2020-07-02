//
//  MNFaceQualityInfo.h
//  MomoNext
//
//  Created by MOMO on 2019/5/10.
//

#ifndef MNFaceQualityInfo_h
#define MNFaceQualityInfo_h

NS_ASSUME_NONNULL_BEGIN

/**
 人脸质量信息
 */

typedef NS_ENUM(NSInteger, MNFaceQualityCode) {
    MNFaceQualityCodeDefault            = -1,
    MNFaceQualityCodeUnkown             = 0,
    MNFaceQualityCodePerfect            = 1,
    MNFaceQualityCodeBrighspot          = 2,
    MNFaceQualityCodeClarityError       = 3,
    MNFaceQualityCodeBrightnessError    = 4,
    MNFaceQualityCodeContrastError      = 5,
    MNFaceQualityCodeFaceOutOfScreen    = 6,
};

typedef NS_ENUM(NSInteger, MNFacePoseType) {
    MNFacePoseTypeDefault               = -1,
    MNFacePoseTypeGooodFrontalFace      = 0,
    MNFacePoseTypeSamllDegreeSideFace   = 1,
    MNFacePoseTypeBigDegreeSideFace     = 2,
};

typedef NS_ENUM(NSInteger, MNFaceOcclusionType) {
    MNFaceOcclusionTypeDefault      = -1,
    MNFaceOcclusionTypeNoOcclusion  = 0,
    MNFaceOcclusionTypeHasOcclusion = 1,
};

typedef NS_ENUM(NSInteger, MNFaceLivenessType) {
    MNFaceLivenessTypeDefault       = -1,
    MNFaceLivenessTypeNoLivesness   = 0,
    MNFaceLivenessTypeLivesness     = 1,
};

typedef NS_ENUM(NSInteger, MNFaceMotionBlurType) {
    MNFaceMotionBlurTypeDefault = -1,
    MNFaceMotionBlurTypeClear   = 0,
    MNFaceMotionBlurTypeBlur    = 1,
};

typedef NS_OPTIONS(NSInteger, MNFaceQualityError) {
    MNFaceQualityErrorNone              = 0,
    MNFaceQualityErrorInvalid           = 1,       // 质量提取失败
    MNFaceQualityErrorOcclusion         = 1 << 1,  // 有遮挡
    MNFaceQualityErrorSideways          = 1 << 2,  // 大侧脸
    MNFaceQualityErrorBlur              = 1 << 3,  // 模糊
    MNFaceQualityErrorDarkness          = 1 << 4,  // 过暗
    MNFaceQualityErrorOverexposure      = 1 << 5,  // 过爆
    MNFaceQualityErrorHighContrast      = 1 << 6,  // 对比度过高
    MNFaceQualityErrorBrighspot         = 1 << 7,  // 有光斑
    MNFaceQualityErrorNotLiveness       = 1 << 8,  // 非活体
    MNFaceQualityErrorNotCenter         = 1 << 9,  // 不在指定位置
};

struct MNFaceQualityInfo {
    float qualityScore;
    
    MNFaceQualityCode qualityCode;
    MNFacePoseType postType;
    MNFaceOcclusionType occlusionType;
    MNFaceLivenessType livenessType;
    MNFaceMotionBlurType motionBlurType;
    
    float spotRatio;
    float brightness;
    float clarity;
    
    float spotScore;
    float brightnessScore;
    float clarityScore;
    float motionBlurScore;
};
typedef struct MNFaceQualityInfo MNFaceQualityInfo;

OBJC_EXTERN const MNFaceQualityInfo MNFaceQualityInfoNULL;

OBJC_EXTERN MNFaceQualityError MNFaceQualityErrorInMNFaceQualityInfo(MNFaceQualityInfo qualityInfo);

NS_ASSUME_NONNULL_END

#endif /* MNFaceQualityInfo_h */
