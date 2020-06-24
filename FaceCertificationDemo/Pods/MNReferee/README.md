# MNReferee

## INTRODUCE

简易动态域名服务

## 接入环境

iOS版本：9.0+

## 使用指南

```

    // 业务层最原始的请求
    NSString *originUrl = _textfield.text;
    // 通过HTTPDNS获取IP成功，进行URL替换和HOST头设置
    NSURLComponents *com = [[NSURLComponents alloc] initWithString:originUrl];
    NSString *host = com.host;
    NSString *usedIp = [MNRefereeService getIPbyHost:host];
    com.host = usedIp;
    // 使用解析后的ip生成新的请求使用的url
    NSURL *newURL = com.URL;
    
    // 模拟发起请求(业务层针对自己的请求模块)
    NSURLSessionConfiguration * config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config delegate:nil delegateQueue:[NSOperationQueue mainQueue]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:newURL];
    request.timeoutInterval = 10;
    
    // 设置Hosts请求头
    if ([usedIp isEqualToString:host]) {
        [request setValue:host forHTTPHeaderField:@"Host"];
    }
    NSURLSessionDataTask * dataTask =  [session dataTaskWithRequest:request completionHandler:^(NSData * __nullable data, NSURLResponse * __nullable response, NSError * __nullable error) {
        if (error) {
            // 请求失败。告知MNReferee
            [MNRefereeService requestFailedForDomain:host andFailedDomain:usedIp andFailedPort:0];
        }else{
	     // 请求成功。告知MNReferee
            [MNRefereeService requestSucceedForDomain:host andSucceedDomain:usedIp andSuccessedPort:0];
        }
        
    }];
    [dataTask resume];

```

## Author

zhu.xi, zhu.xi@immomo.com

## License

MNReferee is available under the MIT license. See the LICENSE file for more info.
