//
//  MNFCInteractiveDetector.h
//  MomoNext
//
//  Created by MOMO on 2019/3/16.
//

#import "MNFCBasicDetector.h"
#import "MNFCOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 交互式真人检测器
 主要功能：1. 收集人脸
         2. 识别用户是否完成交互动作
 */

@class MNFCInteractiveDetector;
@protocol MNFCInteractiveDetectDelegate <MNFCVideoDetectorDelegate>
@optional
/**
 配合式真人检测单项成功回调
 */
- (void)videoDetector:(MNFCInteractiveDetector *)detector singleSuccessWithType:(MNFCLivingnessCheckType)checkType;

/**
 配合式真人检测单项超时回调，业务层打点，Debug使用
 */
- (void)videoDetector:(MNFCInteractiveDetector *)detector singleFailedWithType:(MNFCLivingnessCheckType)checkType;

/**
 配合式真人检测提示回调
 */
- (void)videoDetector:(MNFCInteractiveDetector *)detector checkType:(MNFCLivingnessCheckType)checkType;

/**
 配合式真人检测提示回调, 指定开始时机 (如果存在UI动画，可以在动画完成后执行 beginCheckHandler)
 */
- (void)videoDetector:(MNFCInteractiveDetector *)detector checkType:(MNFCLivingnessCheckType)checkType beginCheckHandler:(void(^)(void))beginCheckHandler;

@end

@interface MNFCInteractiveOptions : NSObject <NSCopying>

@property (nonatomic) CGSize viewSize;                  // 渲染视图大小
@property (nonatomic) MNFCVideoGravity videoGravity;    // 渲染视图视频填充方式
@property (nonatomic) CGRect faceLimitRect;             // 人脸限定位置

@property (nonatomic) NSTimeInterval detectionDuration; // 整体检测时长 0 为无限制  default is 25
@property (nonatomic) NSTimeInterval singleDetectionDuration; // 单项检测时长 0 为无限制 default is 5
@property (nonatomic) NSUInteger singleDetectCount; // 单项检测数量 default 4, 可配范围 3~6

@property (nonatomic) NSInteger skipFrame;  // 跳帧处理
@property (nonatomic, readonly) MNFCQualityOptions *qualityOptions;

@end

@interface MNFCInteractiveDetector : MNFCBasicDetector <MNFCVideoDetectorProtocol>

+ (instancetype)makeDetector; // 自动加载算法模型

- (void)setDelegate:(nullable id<MNFCInteractiveDetectDelegate>)delegate;
- (void)setDetectOptions:(MNFCInteractiveOptions *)detectOptions;

- (void)startDetect;
- (void)resetStatus;

- (nullable NSArray<MNSampleFace *> *)processVideoFrameBuffer:(CVPixelBufferRef)pixelBuffer;

@end

NS_ASSUME_NONNULL_END
