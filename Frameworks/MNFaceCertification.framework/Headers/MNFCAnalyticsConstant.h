//
//  MNFCAnalyticsConstant.h
//  MMFaceCertification
//
//  Created by MOMO on 2019/8/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**详情说明：
 https://docs.google.com/spreadsheets/d/1cyDlY5R3GNMw379ils5lNQQzbbtTovEdj16BSPBR4HM/edit#gid=727998106
 */
typedef NSString * MNFCLoggerKey NS_STRING_ENUM;

extern MNFCLoggerKey const mmface_perf_stat_type;
extern MNFCLoggerKey const mmface_log_type;
extern MNFCLoggerKey const mmface_business_category;
extern MNFCLoggerKey const mmface_network_status;

extern MNFCLoggerKey const mmface_video_detect_type;
extern MNFCLoggerKey const mmface_video_detect_local_error;
extern MNFCLoggerKey const mmface_video_detect_network_errors;
extern MNFCLoggerKey const mmface_video_detect_result;
extern MNFCLoggerKey const mmface_video_face_qualitys;
extern MNFCLoggerKey const mmface_video_interactive_type;
extern MNFCLoggerKey const mmface_video_interactive_timeout_type;
extern MNFCLoggerKey const mmface_video_detect_logs;
extern MNFCLoggerKey const mmface_video_cancel_exit_count;

extern MNFCLoggerKey const mmface_model_name;
extern MNFCLoggerKey const mmface_model_error_type;
extern MNFCLoggerKey const mmface_model_error_msg;
extern MNFCLoggerKey const mmface_model_error_code;
extern MNFCLoggerKey const mmface_model_sd_free;

typedef NSString *MNFCVideoDetectType NS_STRING_ENUM;

extern MNFCVideoDetectType const mmface_video_detect_type_silent;
extern MNFCVideoDetectType const mmface_video_detect_type_interactive;

NS_ASSUME_NONNULL_END
