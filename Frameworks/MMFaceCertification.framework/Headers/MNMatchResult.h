//
//  MNMatchResult.h
//  MomoNext
//
//  Created by MOMO on 2019/5/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSInteger, MNMatchQualityCode) {
    MNMatchQualityCode_Normal               = 0,
    MNMatchQualityCode_NOFACE               = 50,   // 无脸
    MNMatchQualityCode_MULTI                = 51,   // 多个人脸
    MNMatchQualityCode_SMALL                = 52,   // 面积太小
    MNMatchQualityCode_OCC                  = 53,   // 遮挡
    MNMatchQualityCode_NOTFRONT             = 54,   // 大侧脸
    MNMatchQualityCode_BLUR                 = 55,   // 模糊
    MNMatchQualityCode_DARK                 = 56,   // 太暗
    MNMatchQualityCode_LIGHT                = 57,   // 过曝
    MNMatchQualityCode_HICONTRAST           = 58,   // 对比度过高
    MNMatchQualityCode_LIGHTSPOT            = 59,   // 有光斑
};

@interface MNMatchResult : NSObject

@property (nonatomic, copy) NSString *personId;
@property (nonatomic, assign) CGFloat score;

@end

@interface MNCompareResult : MNMatchResult

@property (nonatomic, assign) CGFloat beautyScore;
@property (nonatomic, assign) MNMatchQualityCode qualityCode;

@end

@interface MNSearchResult : NSObject

@property (nonatomic, assign) MNMatchQualityCode qualityCode;
@property (nonatomic, copy) NSArray<MNMatchResult *> *matchResults;

@end

NS_ASSUME_NONNULL_END
