# MMFaceCertification-iOS

## INTRODUCE

利用人脸比对以及人脸搜索技术，为企业提供用户真人认证的解决方案。真人认证的应用场景非常广泛，例如在线交友的身份验证、直播平台的主播认证、金融业务中的身份验证等等。

## 接入环境

iOS版本：9.0+

## 接入指南

### Cocoapods接入

* 在工程Podfile文件中添加如下代码：

```
pod 'MMFaceCertification'
```

* 在终端窗口项目根目录中运行以下命令：

```
 $ pod install
```

* 向**Info.plist**文件中添加相机权限

```
<plist version="1.0">
<dict>
    ...
    <key>NSCameraUsageDescription</key>
    <string>真人认证需要使用相机</string>
    ...
</dict>
</plist>
```

### 设置AppId

将下列代码添加到**AppDelegate**类中，这会在应用启动时将AppId注册进SDK，并完成SDK的环境初始化

```
#import <MMFaceCertification/MNFCService.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [MNFCService configAppId:<YourAPPId>];
    return YES;
}
```

## 使用认证功能

认证功能可以对用户进行真人认证，认证成功后会获得personId

### 设置控制器配置MNFCDetectionConfig

| 参数 | 说明 |
| :--- | :--- |
| detectionType | **MNFCDetectionType:** 检测模式，分为交互式和静默式，默认为交互式 |
| motionDetectionCount | **NSUInteger:** 指定交互式扫脸模式下交互动作的数量，默认为4 |
| resultCallBack | **Block:** 处理认证结果的回调 |

### 开启认证界面控制器

```
[MNFCService startCertificationWithConfig:config];
```

## 图片匹配

图片匹配功能可以对图片中的人物进行识别，获得与指定personId的相似度分值

```
 // 图片识别接口
 [MNFCService comparePerson:personId image:image completionHandler:^(CGFloat score, MNFCDetectionError errorCode) {
        //获得相似度分值
 }];
 // 图片URL识别接口
 [MNFCService comparePerson:personId imageURL:imageURL completionHandler:^(float score, MNFCDetectionError errorCode) {
        //获得相似度分值
 }];
```

## 图片搜索

图片搜索功能可以对图片中的人物进行识别，搜索获得指定集合中满足指定相似度的前N个personId

```
// 图片搜索
[MNFCService searchPersonsInSet:setId       // 集合Id
                      threshold:threshold   // 相似度阈值 0.0~1.0                  
                          count:count       // 查询结果最大数量, 即topN
                          image:image       // 图片
              completionHandler:^(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode) {

}];

// 图片URL搜索
[MNFCService searchPersonsInSet:setId       // 集合Id
                      threshold:threshold   // 相似度阈值 0.0~1.0
                          count:count       // 查询结果最大数量, 即topN
                       imageURL:imageURL    // 图片URL
              completionHandler:^(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode) {

}];

// 人脸Id搜索
[MNFCService searchPersonsInSet:setId       // 集合Id
                      threshold:threshold   // 相似度阈值 0.0~1.0
                          count:count       // 查询结果最大数量, 即topN
                       personId:personId    // 人脸Id
              completionHandler:^(NSArray<MNMatchResult *> * _Nullable matchPersons, MNFCDetectionError errorCode) {

}];
```
