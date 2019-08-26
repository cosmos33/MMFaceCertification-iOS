//
//  MNFCConfig.h
//  MomoNext
//
//  Created by MOMO on 2019/5/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 真人检测错误码
 */
typedef NS_ENUM (NSInteger, MNFCDetectionError) {
    MNFCDetectionError_None                 = 0,
    
    // 通用错误
    MNFCDetectionError_LocalServiceError    = 1001,     // 本地异常
    MNFCDetectionError_NetworkError         = 1002,     // 网络异常
    MNFCDetectionError_InvalidAppId         = 1003,     // 无效的AppId
    MNFCDetectionError_ServerError          = 1004,     // 服务器异常
    MNFCDetectionError_SensitivePeople      = 1005,     // 命中敏感人物
    
    // 扫脸认证时会返回的错误
    MNFCDetectionError_UserCanceled         = 2001,     // 用户手动取消
    MNFCDetectionError_DetectTimeout        = 2002,     // 检测超时
    MNFCDetectionError_NoLivesness          = 2003,     // 非活体
    MNFCDetectionError_FaceChanged          = 2004,     // 人脸改变
    MNFCDetectionError_LostFace             = 2005,     // 人脸丢失
    MNFCDetectionError_TooManyFailedCount   = 2006,     // 动作检测失败次数过多
    MNFCDetectionError_NoCameraPermission   = 2007,     // 无相机权限
    
    // 图片检测时会返回的错误
    MNFCDetectionError_LoadImageError       = 3001,     // 图片拉取失败
    MNFCDetectionError_InvalidPersonId      = 3002,     // 无效的PersonId
    MNFCDetectionError_InvalidSetId         = 3003,     // 无效的SetId
};

/**
 真人检测类型
 */
typedef NS_ENUM (NSInteger, MNFCDetectionType) {
    MNFCDetectionTypeInteractive = 0,  // 交互式
    MNFCDetectionTypeSilent            // 静默式
};

/**
 真人检测器配置
 */
@interface MNFCDetectionConfig : NSObject

/**
 扫脸类型 默认是 交互式扫脸
 */
@property (nonatomic, assign) MNFCDetectionType detectionType;

/**
 交互动作数量，默认为4个，取值返回在 [3, 6]，当扫脸类型为静默式时则忽略此参数
 */
@property (nonatomic, assign) NSUInteger motionDetectionCount;

/**
 扫脸结果回调
 */
@property (nonatomic, strong) void(^resultCallBack)(NSString * _Nullable personId, MNFCDetectionError errorCode);

@end

/**
 真人检测UI配置
 */
@interface MNFCThemes : NSObject

@property (nonatomic, copy, nullable) NSString *detectionTitle;

+ (MNFCThemes *)defultThemes;

@end

NS_ASSUME_NONNULL_END
