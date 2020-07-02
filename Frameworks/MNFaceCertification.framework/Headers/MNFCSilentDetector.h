//
//  MNFCSilentDetector.h
//  MomoNext
//
//  Created by MOMO on 2019/5/9.
//

#import "MNFCBasicDetector.h"
#import "MNFCOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 静默式真人检测器
 主要功能：收集5张人脸质量较好的人脸
 */

@interface MNFCSilentOptions : NSObject <NSCopying>

@property (nonatomic) CGSize viewSize;                  // 渲染视图大小
@property (nonatomic) MNFCVideoGravity videoGravity;    // 渲染视图视频填充方式
@property (nonatomic) CGRect faceLimitRect;             // 人脸限定位置

@property (nonatomic) NSTimeInterval detectionDuration; //整体检测时长 0 为无限制  default is 5

@property (nonatomic) NSInteger skipFrame;  // 跳帧处理
@property (nonatomic, readonly) MNFCQualityOptions *qualityOptions;

@end

@interface MNFCSilentDetector : MNFCBasicDetector <MNFCVideoDetectorProtocol>

+ (instancetype)makeDetector; // 自动加载算法模型

- (void)setDelegate:(nullable id<MNFCVideoDetectorDelegate>)delegate;
- (void)setDetectOptions:(MNFCSilentOptions *)detectOptions;

- (void)startDetect;
- (void)resetStatus;

- (nullable NSArray<MNSampleFace *> *)processVideoFrameBuffer:(CVPixelBufferRef)pixelBuffer;

@end

NS_ASSUME_NONNULL_END
