//
//  ViewController.m
//  FaceCertifactionDemo
//
//  Created by MOMO on 2019/5/21.
//  Copyright © 2019 MOMO. All rights reserved.
//

#import "ViewController.h"
#import <MMFaceCertification/MNFCService.h>

@interface ViewController ()

@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [MNFCService configAppId:@"YourAppId"];
    if (![MNFCService isPrepared]) {
        [MNFCService prepareEnvironment:^(BOOL prepared) {
            
        }];
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0) {
        [self slienceDetect];
    } if (indexPath.row == 1) {
        [self interactiveDetect];
    }
}

- (void)slienceDetect {
    MNFCDetectionConfig *config = [[MNFCDetectionConfig alloc] init];
    config.detectionType = MNFCDetectionTypeSilent;
    config.resultCallBack = ^(NSString * _Nullable personId, MNFCDetectionError errorCode) {
        [self handleDetectionResult:personId errorCode:errorCode];
    };
    
    MNFCThemes *themes = [MNFCThemes defultThemes];
    themes.detectionTitle = @"自定义标题";
    [MNFCService startCertificationWithConfig:config themes:themes];
}

- (void)interactiveDetect {
    MNFCDetectionConfig *config = [[MNFCDetectionConfig alloc] init];
    config.motionDetectionCount = 4;
    config.resultCallBack = ^(NSString * _Nullable personId, MNFCDetectionError errorCode) {
        [self handleDetectionResult:personId errorCode:errorCode];
    };
    [MNFCService startCertificationWithConfig:config];
}

- (void)handleDetectionResult:(NSString *)personId errorCode:(MNFCDetectionError)errorCode {
    NSString *title = nil;
    NSString *message = nil;
    if (personId) {
        title = @"注册成功";
        message =[NSString stringWithFormat:@"注册ID为：%@", personId];
    } else {
        title = @"注册失败";
        message =[NSString stringWithFormat:@"错误码：%ld", (long)errorCode];
    }
    [self presentResultAlertWithTitle:title message:message];
}

- (void)presentResultAlertWithTitle:(NSString *)title message:(NSString *)message {
    UIAlertController * alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    [alert addAction:cancel];
    [self presentViewController:alert animated:YES completion:nil];
}

- (UIActivityIndicatorView *)activityIndicator {
    if (!_activityIndicator) {
        _activityIndicator = [[ UIActivityIndicatorView alloc ] initWithFrame:CGRectMake(0,0,80.0,80.0)];
        _activityIndicator.center = self.view.center;
        _activityIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleWhiteLarge;
        _activityIndicator.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.4];
        _activityIndicator.layer.cornerRadius = 4.f;
        [self.view addSubview:_activityIndicator];
    }
    return _activityIndicator;
}



@end
