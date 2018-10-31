/**
 * Copyright (c) 2017 TomTom N.V. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom N.V. and its subsidiaries and may be used
 * for internal evaluation purposes or commercial use strictly subject to separate licensee
 * agreement between you and TomTom. If you are the licensee, you are only permitted to use
 * this Software in accordance with the terms of your license agreement. If you are not the
 * licensee then you are not authorised to use this software in any manner and should
 * immediately return it to TomTom N.V.
 */

#import "ProgressUtil.h"

@implementation ProgressUtil

- (instancetype)initWithViewController:(UIViewController *)viewcontroller
                                 title:(NSString *)title
                              subtitle:(NSString *)subtitle {
    if (self = [super init]) {
        self.vcontroller = viewcontroller;
        self.ptitle = title;
        self.psubtitle = subtitle;
    }
    return self;
}

- (UIAlertController *)createAlertController {
    return [UIAlertController alertControllerWithTitle:self.ptitle
                                               message:self.psubtitle
                                        preferredStyle:UIAlertControllerStyleAlert];
}

- (void)displayProgressWithAction:(void (^)(void))callback {
    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:YES];
    UIAlertController *progress = [self createAlertController];
    [progress addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:NO];
        callback();
    }]];
    
    UIViewController *customVC     = [[UIViewController alloc] init];
    UIActivityIndicatorView* spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    [spinner startAnimating];
    [customVC.view addSubview:spinner];
    
    [customVC.view addConstraint:[NSLayoutConstraint
                                  constraintWithItem: spinner
                                  attribute:NSLayoutAttributeCenterX
                                  relatedBy:NSLayoutRelationEqual
                                  toItem:customVC.view
                                  attribute:NSLayoutAttributeCenterX
                                  multiplier:1.0f
                                  constant:0.0f]];
    
    
    [customVC.view addConstraint:[NSLayoutConstraint
                                  constraintWithItem: spinner
                                  attribute:NSLayoutAttributeCenterY
                                  relatedBy:NSLayoutRelationEqual
                                  toItem:customVC.view
                                  attribute:NSLayoutAttributeCenterY
                                  multiplier:1.0f
                                  constant:0.0f]];
    
    
    [progress setValue:customVC forKey:@"contentViewController"];
    [self.vcontroller presentViewController:progress animated:YES completion:nil];
    self.progress = progress;
}

- (void)cancelProgress {
    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:NO];
    [self.progress dismissViewControllerAnimated:YES completion:nil];
}

@end
