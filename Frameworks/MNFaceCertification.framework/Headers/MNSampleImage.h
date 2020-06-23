//
//  MNSampleImage.h
//  MomoNext
//
//  Created by MOMO on 2019/5/25.
//

#import "MNSampleFace.h"

NS_ASSUME_NONNULL_BEGIN

@interface MNSampleImage : NSObject

/**
 *  @image 采集到的图片数据
 */
@property (nonatomic, copy) UIImage *image;

/**
 *  @faces 多个人脸对象
 */
@property (nonatomic, strong) NSArray<MNSampleFace*> *faces;

/**
 *  图片上传生成ID
 */
@property (nonatomic, strong) NSString *imgID;

/**
 *  更新图片ID
 */
- (void)updateImageID:(NSString *)imgID;

/**
 * 所有face的faceFeature数组
 */
- (nullable NSArray <MMFaceFeature *>*)allFaceFeatures;


@end

@interface MNSampleImage (MNProtobuf)

+ (nullable NSData *)protobufImageMsgDataWithArray:(NSArray<MNSampleImage *> *)sampleArray;

+ (NSString *)protobufImageMsgDataBase64StringWithArray:(NSArray<MNSampleImage *> *)sampleArray;

- (nullable NSData *)protobufData;

- (nullable NSData *)protobufImageMsgData;

- (NSString *)protobufImageMsgDataBase64String;

@end

NS_ASSUME_NONNULL_END
