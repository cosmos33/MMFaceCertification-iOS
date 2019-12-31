//
//  MNRefereeService.h
//  MNReferee
//
//  Created by MOMO on 2019/10/17.
//  Copyright © 2019 MOMO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MNRefereeProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface MNRefereeService : NSObject <MNRefereeProtocol>

+ (id<NSURLSessionDelegate>)sessionDelegate;

/*
 判断Referee模块是否生效, 默认开启
 */
+ (BOOL)isRefereeModuleEnabled;

/*
 开启Referee模块
 @parameter en YES 开启 NO 禁用
 */
+ (void)enableRefereeModule:(BOOL)en;

/**
 获取可用的连接host

 @param host 原请求的host
 @return 真实请求使用的ip
 */
+ (NSString *)getIPbyHost:(NSString *)host;

/**
 连接成功后调用

 @param succeedDomain 原请求 在请求成功时使用的域名
 @param successedPort 请求成功时使用的port
 */
+ (void)requestSucceedForDomain:(NSString *)mainDomain andSucceedDomain:(NSString *)succeedDomain andSuccessedPort:(NSInteger)successedPort;

/**
 连接失败后调用

 @param failedDomain 原请求 在请求失败时使用的域名
 @param failedPort 请求失败时使用的port
 */
+ (void)requestFailedForDomain:(NSString *)mainDomain andFailedDomain:(NSString *)failedDomain andFailedPort:(NSInteger)failedPort;

@end

NS_ASSUME_NONNULL_END
