//
//  MNFCAnalytics.h
//  MMFaceCertification
//
//  Created by MOMO on 2019/8/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 事件统计类
 负责事件打点
 */

typedef NS_ENUM(NSUInteger, MNFCAnalyticsType) {
    MNFCAnalyticsTypeUnknow,
    MNFCAnalyticsTypeVideoDetection,    // 视频检测相关
    MNFCAnalyticsTypeLoadCV,            // CV下载相关
};

typedef NSString *MNFCLogType NS_STRING_ENUM;

extern MNFCLogType const MNFCLogTypeEvent; // 事件日志
extern MNFCLogType const MNFCLogTypeError; // 错误

@interface MNFCAnalytics : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 增加打点数据
 此时数据临时存在内存中

 @param eventType 统计类型
 @param params 打点数据
 */
+ (void)logEvent:(MNFCAnalyticsType)eventType params:(NSDictionary *)params;

/**
增加视频打点数据中日志信息
 
@param log 统计类型
*/
+ (void)appendVideoDetectionLogs:(NSString *)log;

/**
 打点数据落地并上传

 @param type 统计类型
 @param logType 日志类型
 */
+ (void)consumeAnalyticsParamsForType:(MNFCAnalyticsType)type logType:(MNFCLogType)logType;

/**
 打点数据落地
 
 @param type 统计类型
 @param logType 日志类型
 */
+ (void)writeAnalyticsParamsForType:(MNFCAnalyticsType)type logType:(MNFCLogType)logType;

@end

NS_ASSUME_NONNULL_END
