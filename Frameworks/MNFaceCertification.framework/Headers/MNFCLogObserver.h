//
//  MNFCLogObserver.h
//  MMFaceCertification
//
//  Created by MOMO on 2019/8/22.
//

#import <Foundation/Foundation.h>
#import <MomoCVCenter/MCCLogDelegate.h>

NS_ASSUME_NONNULL_BEGIN
/**
 日志监听类
 负责监听日志打点，桥接数据
*/
@interface MNFCLogObserver : NSObject <MCCLogDelegate>

/// 接收MMCV打点数据
- (void)receiveMomoCVCenterLogInfo:(NSDictionary *)logDic;

@end

NS_ASSUME_NONNULL_END
