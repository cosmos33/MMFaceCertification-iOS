//
//  MNMatchResult.h
//  MomoNext
//
//  Created by MOMO on 2019/5/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MNMatchResult : NSObject

@property (nonatomic, copy) NSString *personId;
@property (nonatomic, assign) CGFloat score;

@end

NS_ASSUME_NONNULL_END
