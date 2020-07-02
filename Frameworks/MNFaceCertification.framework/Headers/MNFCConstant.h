//
//  MNFCConstant.h
//  MomoNext
//
//  Created by MOMO on 2019/5/9.
//

#ifndef MNFCConstant_h
#define MNFCConstant_h

#import "MNFaceQualityInfo.h"
#import "MNMatchResult.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSInteger, MNFCVideoGravity) {
    MNFCVideoGravityResizeAspect = 0,
    MNFCVideoGravityResizeAspectFill,
    MNFCVideoGravityResize
};

typedef NS_ENUM (NSInteger, MNFCDetectStep) {
    MNFCDetectStepNone = 0,
    MNFCDetectStepFrontDetection,
    MNFCDetectStepFittedLivenessDetection,
    MNFCDetectStepFailed,
    MNFCDetectStepDone,
};

typedef NS_ENUM (NSInteger, MNFCDetectFailedReason) {
    MNFCDetectFailedReasonNone = 0,
    MNFCDetectFailedReasonTimeout,              // 超时
    MNFCDetectFailedReasonNoLivesness,          // 非活体
    MNFCDetectFailedReasonTrackIDChanged,       // 人脸改变
    MNFCDetectFailedReasonLoseFace,             // 人脸丢失
    MNFCDetectFailedReasonTooManyFailedCount,   // 动作检测失败次数过多
    MNFCDetectFailedReasonNotEnoughBaseFace,    // 未采集到足够多的base脸
};

typedef NS_ENUM(NSUInteger, MNFCLivingnessCheckType) {
    MNFCLivingnessCheckTypeNone = 0,
    MNFCLivingnessCheckTypeFrontFace,           // 正脸
    MNFCLivingnessCheckTypeLiveEyes,            // 眨眼
    MNFCLivingnessCheckTypeLiveMouth,           // 张嘴
    MNFCLivingnessCheckTypeLiveYawRight,        // 右摇头
    MNFCLivingnessCheckTypeLiveYawLeft,         // 左摇头
    MNFCLivingnessCheckTypeLivePitchUp,         // 抬头
    MNFCLivingnessCheckTypeLivePitchDown        // 低头
};

typedef NS_ENUM(NSUInteger, MNFCBaseFaceErrorCode) {
    MNFCBaseFaceErrorCode_None          = 0,
    MNFCBaseFaceErrorCode_OCC           = 35,   // 有遮挡
    MNFCBaseFaceErrorCode_NOTFRONT      = 36,   // 大侧脸
    MNFCBaseFaceErrorCode_BLUR          = 37,   // 模糊
    MNFCBaseFaceErrorCode_DARK          = 38,   // 太暗
    MNFCBaseFaceErrorCode_LIGHT         = 39,   // 过曝
    MNFCBaseFaceErrorCode_HICONTRAST    = 40,   // 对比度太高
    MNFCBaseFaceErrorCode_LIGHTSPOT     = 41,   // 光斑
    MNFCBaseFaceErrorCode_NOTCENTOR     = 42,   // 不在指定区域
    MNFCBaseFaceErrorCode_NOTLIVESNESS  = 43,   // 非活体
    MNFCBaseFaceErrorCode_NOFACE        = 44,   // 没有脸
    MNFCBaseFaceErrorCode_LOWQUALITY    = 45,   // 质量分过低
    MNFCBaseFaceErrorCode_QUALITYERROR  = 46    // 质量检测模块加载失败
};

//typedef NS_ENUM(NSUInteger, MNFCAvatarErrorCode) {
//    MNFCAvatarErrorCode_None            = 0,
//    MNFCAvatarErrorCode_QUALITYERROR    = MNFCBaseFaceErrorCode_QUALITYERROR,
//    MNFCAvatarErrorCode_NOFACE          = MNMatchQualityCode_NOFACE,
//    MNFCAvatarErrorCode_MULTI           = MNMatchQualityCode_MULTI,
//    MNFCAvatarErrorCode_SMALL           = MNMatchQualityCode_SMALL,
//    MNFCAvatarErrorCode_OCC             = MNMatchQualityCode_OCC,
//    MNFCAvatarErrorCode_NOTFRONT        = MNMatchQualityCode_NOTFRONT,
//    MNFCAvatarErrorCode_BLUR            = MNMatchQualityCode_BLUR,
//    MNFCAvatarErrorCode_DARK            = MNMatchQualityCode_DARK,
//    MNFCAvatarErrorCode_LIGHT           = MNMatchQualityCode_LIGHT,
//    MNFCAvatarErrorCode_HICONTRAST      = MNMatchQualityCode_HICONTRAST,
//    MNFCAvatarErrorCode_LIGHTSPOT       = MNMatchQualityCode_LIGHTSPOT,
//};


OBJC_EXTERN MNFCBaseFaceErrorCode MNFCBaseFaceErrorCodeWithFaceQualityError(MNFaceQualityError qualityError);
//OBJC_EXTERN MNFCAvatarErrorCode MNFCAvatarErrorCodeWithFaceQualityError(MNFaceQualityError qualityError);
OBJC_EXTERN NSString *MNFCDetectFailedReasonFromENUM(MNFCDetectFailedReason failedReason);

@class MNSampleFace;
@class MNSampleImage;

@protocol MNFCVideoDetectorProtocol <NSObject>

- (BOOL)detectorLoaded;
- (void)startDetect;
- (void)resetStatus;

- (nullable NSArray<MNSampleFace *> *)processVideoFrameBuffer:(CVPixelBufferRef)pixelBuffer;

@end

typedef id<MNFCVideoDetectorProtocol> MNFCVideoDetector;

@protocol MNFCVideoDetectorDelegate <NSObject>
@optional

/**
 检测成功回调
 */
- (void)videoDetector:(MNFCVideoDetector)detector detectSuccess:(NSArray<MNSampleImage *> *)faceImages;

/**
 检测失败回调
 */
- (void)videoDetector:(MNFCVideoDetector)detector detectFailed:(MNFCDetectFailedReason)reason;

/**
 检测质量错误回调
 */
- (void)videoDetector:(MNFCVideoDetector)detector qualityErrorCode:(MNFCBaseFaceErrorCode)errorCode;

/**
 开始收集base脸数据
 */
- (void)videoDetectorBeginCatchingFaceImages:(MNFCVideoDetector)detector;

/**
 完成收集base脸数据
 */
- (void)videoDetectorFinishCatchingFaceImages:(MNFCVideoDetector)detector;

/**
 目前收集到的base脸数量总和
 */
- (void)videoDetector:(MNFCVideoDetector)detector catchedFaceCount:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END

#endif /* MNFCConstant_h */
