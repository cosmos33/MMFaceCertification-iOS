//
//  MNFDNSConfig.h
//  MNFaceCertification
//
//  Created by BJ3382 on 2020/6/23175.
//

#import <Foundation/Foundation.h>
#import <PhotonHTTPDNS/PhotonHTTPDNSConfigProtocol.h>
NS_ASSUME_NONNULL_BEGIN

@interface MNFDNSConfig : NSObject<PhotonHTTPDNSConfigProtocol>

+ (instancetype)shareInstance;

- (NSString *)getIPbyHost:(nullable NSString *)host;


- (void)requestSucceedForDomain:(nullable NSString *)mainDomain andSucceedDomain:(nullable NSString *)succeedDomain andSuccessedPort:(NSInteger)successedPort;

- (void)requestFailedForDomain:(nullable NSString *)mainDomain andFailedDomain:(nullable NSString *)failedDomain andFailedPort:(NSInteger)failedPort;

@end

NS_ASSUME_NONNULL_END
