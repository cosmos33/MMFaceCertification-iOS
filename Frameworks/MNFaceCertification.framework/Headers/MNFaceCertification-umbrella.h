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

#import "MNNetworkManager.h"
#import "MNFCRequest.h"
#import "MNFCAnalytics.h"
#import "MNFCAnalyticsConstant.h"
#import "MNFClogger.h"
#import "MNFCLogObserver.h"
#import "MNFCService+MNFCAnalytics.h"
#import "MNFDNSConfig.h"
#import "MNFaceQualityInfo.h"
#import "Mnimage.pbobjc.h"
#import "MNMatchResult.h"
#import "MNSampleFace.h"
#import "MNSampleImage.h"
#import "MNFCAvatarDetector.h"
#import "MNFCBasicDetector.h"
#import "MNFCConstant.h"
#import "MNFCInteractiveDetector.h"
#import "MNFCOptions.h"
#import "MNFCSilentDetector.h"
#import "MNFCConfig.h"
#import "MNFCService.h"

FOUNDATION_EXPORT double MNFaceCertificationVersionNumber;
FOUNDATION_EXPORT const unsigned char MNFaceCertificationVersionString[];

