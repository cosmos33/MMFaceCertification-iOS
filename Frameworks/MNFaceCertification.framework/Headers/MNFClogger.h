//
//  MNFClogger.h
//  MMFaceCertification
//
//  Created by MOMO on 2019/8/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 日志上传类，负责上传日志
 */
@interface MNFClogger : NSObject

- (instancetype)initWithCachePath:(NSString *)cachePath;

@property (nonatomic, readonly) NSString *cachePath;

- (void)writeBody:(NSString *)body;
- (void)forceUploadMMFile;

- (void)enableLogger:(BOOL)enable;
+ (NSString *)userAgentString ;
@end

NS_ASSUME_NONNULL_END
