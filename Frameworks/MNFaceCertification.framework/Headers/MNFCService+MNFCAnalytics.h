//
//  MNFCService+MNFCAnalytics.h
//  Pods
//
//  Created by MOMO on 2019/8/23.
//

#import "MNFCService.h"

NS_ASSUME_NONNULL_BEGIN

@interface MNFCService (MNFCAnalytics)
/**
 统计检测错误

 @param error 错误
 @param detectionType 检测类型
 */
+ (void)analyticsDetectionWithError:(MNFCDetectionError)error
                      detectionType:(MNFCDetectionType)detectionType;

@end

NS_ASSUME_NONNULL_END
