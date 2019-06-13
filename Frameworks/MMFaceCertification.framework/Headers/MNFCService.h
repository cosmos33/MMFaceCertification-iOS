//
//  MomoFaceService.h
//  MomoNext
//
//  Created by MOMO on 2019/5/9.
//

#import <Foundation/Foundation.h>
#import "MNFCConfig.h"
#import "MNMatchResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MNFCService : NSObject

@property (class, strong, readonly) NSString *appId;

/**
 设置appId

 @param appId appId
 */
+ (void)configAppId:(NSString *)appId;

/**
 扫脸认证注册
 通过Modal的形式展示出扫脸视图控制器，进行扫脸认证注册

 @param config 扫脸配置
 */
+ (void)startCertificationWithConfig:(MNFCDetectionConfig *)config;

/**
 扫脸认证注册
 通过Modal的形式展示出扫脸视图控制器，进行扫脸认证注册
 
 @param config 扫脸配置
 @param themes 界面配置
 */
+ (void)startCertificationWithConfig:(MNFCDetectionConfig *)config themes:(MNFCThemes * _Nullable)themes;

/**
 扫脸认证注册
 通过Modal的形式展示出扫脸视图控制器，进行扫脸认证注册
 
 @param config 扫脸配置
 @param themes 界面配置
 @param presentingViewController 用于present扫脸界面的控制器
 */
+ (void)startCertificationWithConfig:(MNFCDetectionConfig *)config
                              themes:(MNFCThemes * _Nullable)themes
            presentingViewController:(UIViewController * _Nullable)presentingViewController;

/**
 人脸对比
 识别图片中的人物与指定 personId 的人物的相似度

 @param personId 指定对比的 personId
 @param image 对比的图片
 @param completionHandler 对比结果回调
 注：当图片有质量问题时，也可能会有相似度，质量情况可参照 errorCode
 */
+ (void)comparePerson:(NSString *)personId
                image:(UIImage *)image
    completionHandler:(nonnull void(^)(CGFloat score, MNFCDetectionError errorCode))completionHandler;

/**
 人脸对比
 通过URL获取图片，识别图片中的人物与指定 personId 的人物的相似度
 
 @param personId 指定对比的 personId
 @param imageURL 对比图片的URL
 @param completionHandler 对比结果回调
 注：当图片有质量问题时，也可能会有相似度，质量情况可参照 errorCode
 */
+ (void)comparePerson:(NSString *)personId
             imageURL:(NSString *)imageURL
    completionHandler:(nonnull void(^)(CGFloat score, MNFCDetectionError errorCode))completionHandler;

/**
 人脸搜索
 从指定集合中搜索出与图片中人物相似度高于某值的前N个人物
 例：从集合1中获取与图片中人物相似度高于0.43的前10个人物
 [MNFCService searchPersonsInSet:@"1" threshold:0.43 count:10 image:image completionHandler:completionHandler]
 
 @param setId 指定搜索的集合ID
 @param threshold 查询相似度阈值
 @param count 返回topN个数
 @param image 搜索的图片
 @param completionHandler 搜索回调
 注：当图片有质量问题时，也可能会有匹配结果，质量情况可参照 errorCode
 */
+ (void)searchPersonsInSet:(NSString *)setId
                 threshold:(CGFloat)threshold
                     count:(NSUInteger)count
                     image:(UIImage *)image
         completionHandler:(nonnull void(^)(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode))completionHandler;

/**
 人脸搜索
 通过URL获取图片，从指定集合中搜索出与图片中人物相似度高于某值的前N个人物
 
 @param setId 指定搜索的集合ID
 @param threshold 查询相似度阈值
 @param count 返回topN个数
 @param imageURL 搜索图片的URL
 @param completionHandler 搜索回调
 注：当图片有质量问题时，也可能会有匹配结果，质量情况可参照 errorCode
 */
+ (void)searchPersonsInSet:(NSString *)setId
                 threshold:(CGFloat)threshold
                     count:(NSUInteger)count
                  imageURL:(NSString *)imageURL
         completionHandler:(nonnull void(^)(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode))completionHandler;

/**
 人脸搜索
 从指定集合中搜索出与对应的personId的人物相似度高于某值的前N个人物
 
 @param setId 指定搜索的集合ID
 @param threshold 查询相似度阈值
 @param count 返回topN个数
 @param personId 搜索人物的personId
 @param completionHandler 搜索回调
 注：当图片有质量问题时，也可能会有匹配结果，质量情况可参照 errorCode
 */
+ (void)searchPersonsInSet:(NSString *)setId
                 threshold:(CGFloat)threshold
                     count:(NSUInteger)count
                  personId:(NSString *)personId
         completionHandler:(nonnull void(^)(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode))completionHandler;

@end

NS_ASSUME_NONNULL_END
