//
//  ViewController.m
//  FaceCertificationDemo
//
//  Created by MOMO on 2019/5/27.
//  Copyright © 2019 MOMO. All rights reserved.
//

#import "ViewController.h"
#import <MMFaceCertification/MNFCService.h>

@interface ViewController ()<UIImagePickerControllerDelegate, UINavigationControllerDelegate>

@property (nonatomic, assign) BOOL isMatchOne;
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0) {
        [self slienceDetect];
    } if (indexPath.row == 1) {
        [self interactiveDetect];
    } if (indexPath.row == 2) {
        self.isMatchOne = YES;
        [self presentImagePicker];
    } if (indexPath.row == 3) {
        self.isMatchOne = NO;
        [self presentImagePicker];
    }
}

- (void)slienceDetect {
    MNFCDetectionConfig *config = [[MNFCDetectionConfig alloc] init];
    config.detectionType = MNFCDetectionTypeSilent;
    config.resultCallBack = ^(NSString * _Nullable personId, MNFCDetectionError errorCode) {
        [self handleDetectionResult:personId errorCode:errorCode];
    };
    [MNFCService startCertificationWithConfig:config];
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
        message =[NSString stringWithFormat:@"错误码：%ld", errorCode];
    }
    [self presentResultAlertWithTitle:title message:message];
}

- (void)presentImagePicker {
    UIImagePickerController * imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.editing = YES;
    imagePicker.delegate = self;
    imagePicker.allowsEditing = YES;
    
    UIAlertController * alert = [UIAlertController alertControllerWithTitle:@"请选择打开方式" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    
    UIAlertAction * camera = [UIAlertAction actionWithTitle:@"相机" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        imagePicker.sourceType =  UIImagePickerControllerSourceTypeCamera;
        imagePicker.modalPresentationStyle = UIModalPresentationFullScreen;
        imagePicker.cameraCaptureMode = UIImagePickerControllerCameraCaptureModePhoto;
        [self presentViewController:imagePicker animated:YES completion:nil];
    }];
    
    UIAlertAction * photo = [UIAlertAction actionWithTitle:@"相册" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
        [self presentViewController:imagePicker animated:YES completion:nil];
    }];
    UIAlertAction * cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    
    [alert addAction:camera];
    [alert addAction:photo];
    [alert addAction:cancel];
    
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info {
    
    [picker dismissViewControllerAnimated:YES completion:nil];
    //获取到的图片
    UIImage * image = [info valueForKey:UIImagePickerControllerEditedImage];
    [self.activityIndicator startAnimating];
    if (self.isMatchOne) {
        // 图片对比
        [MNFCService comparePerson:@"1" image:image completionHandler:^(CGFloat score, MNFCDetectionError errorCode) {
            [self.activityIndicator stopAnimating];
            NSString *title = nil;
            NSString *message = nil;
            if (!errorCode) {
                title = @"检测成功";
                message =[NSString stringWithFormat:@"相似度为：%f", score];
            } else {
                title = @"检测失败";
                message =[NSString stringWithFormat:@"错误码：%ld", errorCode];
            }
            [self presentResultAlertWithTitle:title message:message];
        }];
    } else {
        // 图片搜索
        [MNFCService searchPersonsInSet:@"1" threshold:0.43 count:10 image:image completionHandler:^(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode) {
            [self.activityIndicator stopAnimating];
            NSString *title = nil;
            NSString *message = nil;
            if (!errorCode) {
                title = @"检测成功";
                message =[NSString stringWithFormat:@"符合相似度的一共有%lu个", (unsigned long)matchPersons.count];
            } else {
                title = @"检测失败";
                message =[NSString stringWithFormat:@"错误码：%ld", errorCode];
            }
            [self presentResultAlertWithTitle:title message:message];
        }];
    }
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
