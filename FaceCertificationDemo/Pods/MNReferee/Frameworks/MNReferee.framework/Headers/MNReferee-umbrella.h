#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MNRefereeService.h"
#import "MNRefereeProtocol.h"
#import "NNRESessionDelegate.h"
#import "NSString+MNRE_OAURLEncodingAdditions.h"

FOUNDATION_EXPORT double MNRefereeVersionNumber;
FOUNDATION_EXPORT const unsigned char MNRefereeVersionString[];

