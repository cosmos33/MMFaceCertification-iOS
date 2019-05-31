//
//  SearchViewController.m
//  FaceCertifactionDemo
//
//  Created by MOMO on 2019/5/28.
//  Copyright © 2019 MOMO. All rights reserved.
//

#import "SearchViewController.h"
#import <MMFaceCertification/MNFCService.h>

@interface SearchViewController ()<UIImagePickerControllerDelegate, UINavigationControllerDelegate>

@property (weak, nonatomic) IBOutlet UITextField *setIdTF;
@property (weak, nonatomic) IBOutlet UITextField *imageURLTF;
@property (weak, nonatomic) IBOutlet UITextView *resultTextView;

@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

@end

@implementation SearchViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)urlSearchAction:(id)sender {
    NSString *urlStr = self.imageURLTF.text;
    NSString *setId = self.setIdTF.text ? : @"";
    [self.activityIndicator startAnimating];
    [MNFCService searchPersonsInSet:setId threshold:0.43 count:10 imageURL:urlStr completionHandler:^(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode) {
        [self.activityIndicator stopAnimating];
        [self handleDetectionResult:matchPersons errorCode:errorCode];
    }];
}

- (IBAction)cameraSearchAction:(id)sender {
    UIImagePickerController * imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.editing = YES;
    imagePicker.delegate = self;
    imagePicker.allowsEditing = YES;
    imagePicker.sourceType =  UIImagePickerControllerSourceTypeCamera;
    imagePicker.modalPresentationStyle = UIModalPresentationFullScreen;
    imagePicker.cameraCaptureMode = UIImagePickerControllerCameraCaptureModePhoto;
    [self presentViewController:imagePicker animated:YES completion:nil];
}

- (IBAction)photoSearchAction:(id)sender {
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
     NSString *setId = self.setIdTF.text ? : @"";
    [self.activityIndicator startAnimating];
    [MNFCService searchPersonsInSet:setId threshold:0.2 count:10 image:image completionHandler:^(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode) {
        [self.activityIndicator stopAnimating];
        [self handleDetectionResult:matchPersons errorCode:errorCode];
    }];
}

- (void)handleDetectionResult:(NSArray<MNMatchResult *> *)matchPersons errorCode:(MNFCDetectionError)errorCode {
    NSMutableString *message = [NSMutableString string];
    if (errorCode) {
        [message appendFormat:@"错误码：%ld\n", errorCode];
    }
    if (matchPersons.count) {
        for (MNMatchResult * p in matchPersons) {
            [message appendFormat:@"personId %@\n sorce %lf\n\n", p.personId, p.score];
        }
    }
    self.resultTextView.text = message;
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
