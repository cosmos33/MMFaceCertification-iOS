//
//  MatchViewController.m
//  FaceCertifactionDemo
//
//  Created by MOMO on 2019/5/27.
//  Copyright © 2019 MOMO. All rights reserved.
//

#import "MatchViewController.h"
#import <MMFaceCertification/MNFCService.h>

@interface MatchViewController () <UIImagePickerControllerDelegate, UINavigationControllerDelegate>

@property (weak, nonatomic) IBOutlet UITextField *personIdTF;
@property (weak, nonatomic) IBOutlet UITextField *imageURLTF;

@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

@end

@implementation MatchViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)urlMatchAction:(id)sender {
    NSString *urlStr = self.imageURLTF.text;
    NSString *personId = self.personIdTF.text ? : @"";
    [self.activityIndicator startAnimating];
    [MNFCService comparePerson:personId imageURL:urlStr completionHandler:^(MNCompareResult * _Nullable compareResult, MNFCDetectionError errorCode) {
        [self.activityIndicator stopAnimating];
        [self handleDetectionResult:compareResult errorCode:errorCode];
    }];
}

- (IBAction)cameraMatchAction:(id)sender {
    UIImagePickerController * imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.editing = YES;
    imagePicker.delegate = self;
    imagePicker.allowsEditing = YES;
    imagePicker.sourceType =  UIImagePickerControllerSourceTypeCamera;
    imagePicker.modalPresentationStyle = UIModalPresentationFullScreen;
    imagePicker.cameraCaptureMode = UIImagePickerControllerCameraCaptureModePhoto;
    [self presentViewController:imagePicker animated:YES completion:nil];
}

- (IBAction)photoMatchAction:(id)sender {
    UIImagePickerController * imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.editing = YES;
    imagePicker.delegate = self;
    imagePicker.allowsEditing = YES;
    imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    [self presentViewController:imagePicker animated:YES completion:nil];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info {
    
    [picker dismissViewControllerAnimated:YES completion:nil];
    //获取到的图片
    UIImage * image = [info valueForKey:UIImagePickerControllerEditedImage];
    if (!image) {
        image = [info valueForKey:UIImagePickerControllerOriginalImage];
    }
    NSString *personId = self.personIdTF.text ? : @"";
    [self.activityIndicator startAnimating];
    [MNFCService comparePerson:personId image:image completionHandler:^(MNCompareResult * _Nullable compareResult, MNFCDetectionError errorCode) {
        [self.activityIndicator stopAnimating];
        [self handleDetectionResult:compareResult errorCode:errorCode];
    }];
}

- (void)handleDetectionResult:(MNCompareResult *)compareResult errorCode:(MNFCDetectionError)errorCode {
    NSString *title = @"检测结果";
    NSString *message = [NSString stringWithFormat:@"错误码：%ld\n相似度：%lf\n颜值：%lf\n质量：%ld", (long)errorCode, compareResult.score, compareResult.beautyScore, compareResult.qualityCode];
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

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

@end
