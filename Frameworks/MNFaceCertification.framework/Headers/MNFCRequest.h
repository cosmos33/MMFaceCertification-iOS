//
//  MFRequest.h
//  MomoFace
//
//  Created by MOMO on 2019/5/7.
//

#import <MMNNetwork/MNBaseRequest.h>
#import "MNSampleImage.h"
#import "MNMatchResult.h"

NS_ASSUME_NONNULL_BEGIN
/**
 真人认证相关请求
 */
@interface MNFCBaseRequest : MNBaseRequest

@end

/**
 上传多张图片
*/
@interface MNFCUploadImageRequest : MNFCBaseRequest

- (instancetype)initWithImages:(NSArray<UIImage *> *)images;

@property (nonatomic, copy) NSArray<NSString *> *guids;

@end

/**
 上传base图片
*/
@interface MNFCUploadBaseImageRequest : MNFCBaseRequest

- (instancetype)initWithImage:(UIImage*)image;

@property (nonatomic, copy) NSArray<NSString *> *guids;

@end

/**
 上传非base脸其余图片
*/
@interface MNFCUploadOtherImageRequest : MNFCBaseRequest

- (instancetype)initWithImages:(NSArray<UIImage *> *)images guids:(NSArray<NSString *> *)guids;

@property (nonatomic, strong) NSDictionary *results;

@end

@interface MNFCRegisterRequest : MNFCBaseRequest

- (instancetype)initWithMNImages:(NSArray<MNSampleImage *> *)mnImages;

@property (nonatomic, copy) NSString *personId;

@end

/**
 比对请求
*/
@interface MNFCCompareRequest : MNFCBaseRequest

- (instancetype)initWithPersonId:(NSString *)personId
                       URLString:(NSString *)urlString;

- (instancetype)initWithPersonId:(NSString *)personId
                     sampleImage:(MNSampleImage *)sampleImage;

- (instancetype)initWithPersonId:(NSString *)personId
                           image:(UIImage *)image;

@property (nonatomic, strong) MNCompareResult *compareResult;

@end

/**
 搜索请求
*/
@interface MNFCSearchRequest : MNFCBaseRequest

/**
 @param setId 集合ID
 @param threshold 查询相似度阈值
 @param count 返回topN个数
 @param urlString 图片url
 */

- (instancetype)initWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                    URLString:(NSString *)urlString;

/**
@param setId 集合ID
@param threshold 查询相似度阈值
@param count 返回topN个数
@param sampleImage 样本图片类
*/
- (instancetype)initWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                  sampleImage:(MNSampleImage *)sampleImage;

/**
@param setId 集合ID
@param threshold 查询相似度阈值
@param count 返回topN个数
@param image 样本图片
*/
- (instancetype)initWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                        image:(UIImage *)image;

/**
@param setId 集合ID
@param threshold 查询相似度阈值
@param count 返回topN个数
@param personId 人物Id
*/
- (instancetype)initWithSetId:(NSString *)setId
                    threshold:(CGFloat)threshold
                        count:(NSUInteger)count
                     personId:(NSString *)personId;

@property (nonatomic, strong) MNSearchResult *searchResult;

@end


NS_ASSUME_NONNULL_END
