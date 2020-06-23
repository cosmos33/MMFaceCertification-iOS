//
//  MNNetworkManager.h
//  MomoFace
//
//  Created by MOMO on 2019/5/7.
//

#import <Foundation/Foundation.h>
#import "MNSampleImage.h"
#import "MNMatchResult.h"

NS_ASSUME_NONNULL_BEGIN
/**
 网络管理类
 负责真人认证的全部网络请求
 */

@interface MNNetworkManager : NSObject

- (instancetype)init;

- (void)configAppId:(NSString *)appId;

- (nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                             parameters:(nullable id)parameters
                      completionHandler:(nullable void (^)(id _Nullable responseObject, NSError * _Nullable error))completionHandler;

@end

@interface MNNetworkManager (FaceCertification)

/**
 注册接口
 注：内部已调用上传图片接口，注册阶段直接调用此接口即可
 */
- (void)autoRegisterWithMNImages:(NSArray<MNSampleImage *> *)images
               completionHandler:(void (^)(NSString * _Nullable personId, NSError * _Nullable error))completionHandler;

/**
 上传图片接口
*/
- (void)uploadImages:(NSArray<UIImage *> *)images
   completionHandler:(void (^)(NSArray<NSString *> * _Nullable guids, NSError * _Nullable error))completionHandler;
/**
 上传base图片接口
*/
- (void)uploadBaseImage:(UIImage *)image
      completionHandler:(void (^)(NSArray<NSString *> * _Nullable guids, NSError * _Nullable error))completionHandler;

/**
 上传非base图片接口
*/
- (void)uploadOhterImages:(NSArray<UIImage *> *)images
                    guids:(NSArray<NSString *> *)guids
        completionHandler:(nullable void (^)(NSError * _Nullable))completionHandler;

/**
 注册接口
*/
- (void)registerWithMNImages:(NSArray<MNSampleImage *> *)images
           completionHandler:(void (^)(NSString * _Nullable personId, NSError * _Nullable error))completionHandler;

#pragma mark - 1：1接口
/**
 指定peronId 与 图片url 进行1：1比对
*/
- (void)comparePersion:(NSString *)personId
           toURLString:(NSString *)urlString
     completionHandler:(void (^)(MNCompareResult * _Nullable compareResult, NSError * _Nullable error))completionHandler;
/**
 指定peronId 与 算法提取到的人脸特征 进行1：1比对
*/
- (void)comparePersion:(NSString *)personId
         toSampleImage:(MNSampleImage *)sampleImage
     completionHandler:(void (^)(MNCompareResult * _Nullable compareResult, NSError * _Nullable error))completionHandler;

/**
 指定peronId 与 图片 进行1：1比对
*/
- (void)comparePersion:(NSString *)personId
               toImage:(UIImage *)image
     completionHandler:(void (^)(MNCompareResult * _Nullable compareResult, NSError * _Nullable error))completionHandler;

#pragma mark - 1：N接口
/**
 指定setId 与 图片url 进行1：N搜索
*/
- (void)searchPersonWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                    URLString:(NSString *)urlString
            completionHandler:(void (^)(MNSearchResult * _Nullable searchResult, NSError * _Nullable error))completionHandler;

/**
 指定setId 与 算法提取到的人脸特征 进行1：N搜索
*/
- (void)searchPersonWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                  sampleImage:(MNSampleImage *)sampleImage
            completionHandler:(void (^)(MNSearchResult * _Nullable searchResult, NSError * _Nullable error))completionHandler;

/**
 指定setId 与 图片 进行1：N搜索
*/
- (void)searchPersonWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                        image:(UIImage *)image
            completionHandler:(void (^)(MNSearchResult * _Nullable searchResult, NSError * _Nullable error))completionHandler;

/**
 指定setId 与 人物Id 进行1：N搜索
*/
- (void)searchPersonWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                     personId:(NSString *)personId
            completionHandler:(void (^)(MNSearchResult * _Nullable searchResult, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
