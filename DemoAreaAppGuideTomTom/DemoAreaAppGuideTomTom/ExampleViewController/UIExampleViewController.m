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

#import "UIExampleViewController.h"
#import "UIExampleViewController+SegmentedControl.h"
#import "UIView+Toast.h"
#import "HeaderView.h"
#import "DemoAreaAppGuideTomTom-Swift.h"

@interface UIExampleViewController ()

@property (nonatomic) UIView *toast;
@property (nonatomic, strong) NSTimer * toastTimer;

@property (nonatomic, weak) HeaderView *headerView;

@end

@implementation UIExampleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIImage *menuImage = [[UIImage imageNamed:@"BtnPixelDot"] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    UIBarButtonItem *optionsItem = [[UIBarButtonItem alloc] initWithImage:menuImage
                                                                    style:UIBarButtonItemStylePlain
                                                                   target:self.navigationController
                                                                   action:@selector(popViewControllerAnimated:)];
    self.navigationItem.leftBarButtonItem = optionsItem;
    [self setSegmentHidden:YES];
    self.showToastEnable = NO;
}

#pragma mark - Buttons
- (void)clearSegmentedControll {
    [self setSegmentHidden:YES];
}

- (void)createSegmentedControllWithTag:(NSInteger)tag options:(NSArray<NSString *> *)options multiSelect:(BOOL)multiselect select:(NSInteger)select {
    self.multiSelect = multiselect;
    [self setSegmentTag:tag];
    [self createSegments:options];
    [self deselectAll];
    if(select >= 0) {
        [self selectSegment:select selected:YES];
    }
}

#pragma mark - Option Buttton
- (IBAction)option1Changed:(UIButton *)sender {
    [self optionChangedButton:sender Index:2];
}

- (IBAction)option2Changed:(UIButton *)sender {
    [self optionChangedButton:sender Index:1];
}

- (IBAction)option3Chnaged:(UIButton *)sender {
    [self optionChangedButton:sender Index:0];
}

- (void)optionChangedButton:(UIButton *)button Index:(int)index {
    if(self.multiSelect) {
        [self toogleSelectSegment:index];
    } else {
        [self selectSegment:index selected:YES];
    }

    if ([self.delegate respondsToSelector:@selector(optionButtonTag:index:)]) {
        [self.delegate optionButtonTag:button.tag index:index];
    }
}

- (void)deselectOptionIndexs:(NSArray *)indexs {
    for(NSNumber *idx in indexs) {
        switch (idx.integerValue){
            case 0:
                self.option1.selected = false;
                break;
            case 1:
                self.option2.selected = false;
                break;
            case 2:
                self.option3.selected = false;
                break;
            default:
                break;
        }
    }

}

#pragma mark - Show Toast

- (void)showToast:(NSString *)text withTimer:(BOOL)timerEnable {
    if (self.showToastEnable) {
        
        if (self.toastTimer != nil) {
            [self.toastTimer invalidate];
        }
        
        NSTimeInterval interval = 1.5;
        if (timerEnable) {
            self.toastTimer = [NSTimer scheduledTimerWithTimeInterval: interval
                                                               target: self
                                                             selector: @selector(hideToast)
                                                             userInfo: nil
                                                              repeats: NO];
        }

        CSToastStyle *style = [self csToastStyle];
        [self hideToast];
        self.toast = [self.view toastViewForMessage:text title:nil image:nil style:style];
        [CSToastManager setSharedStyle:style];
        [CSToastManager setTapToDismissEnabled:YES];
        [CSToastManager setQueueEnabled:NO];
        [self.view showToast:self.toast duration:60.0 position:CSToastPositionBottom completion:nil];
    }
}

- (CSToastStyle *)csToastStyle {
    CSToastStyle *style = [[CSToastStyle alloc] initWithDefaultStyle];
    style.backgroundColor = [UIColor whiteColor];
    style.cornerRadius = 0.0;
    style.messageColor = [UIColor blackColor];
    style.displayShadow = YES;
    style.shadowOffset = CGSizeZero;
    style.shadowOpacity = 0.3;
    return style;
}

- (void)hideToast {
    [self.toast hideToast:self.toast];
    self.toast = nil;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

#pragma mark - Header View
- (void)buildHeader:(NSString*)TitleB and:(NSString*) SubtitleB{
    HeaderView *headerView = [[HeaderView alloc] init];
    self.headerView = headerView;
    self.headerView.title.text = TitleB;
    self.headerView.subtitle.text = SubtitleB;
    self.navigationItem.titleView = self.headerView;
    [self updateHeaderViewLayout];
}

- (void)updateHeaderViewLayout {
    CGFloat _width = CGRectGetWidth(self.view.frame);
    CGFloat _height = 40.0;
    [self.navigationItem.titleView removeConstraints:[self.navigationItem.titleView constraints]];

    NSLayoutConstraint *height = [NSLayoutConstraint constraintWithItem:self.navigationItem.titleView attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1 constant:_height];
    NSLayoutConstraint *width = [NSLayoutConstraint constraintWithItem:self.navigationItem.titleView attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1 constant:_width];

    [self.navigationItem.titleView addConstraints:@[height, width]];
    [self.navigationItem.titleView setFrame:CGRectMake(0, 0, _width, _height)];
    [self.navigationController.navigationBar layoutIfNeeded];
}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];
    [coordinator animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        self.navigationItem.titleView = self.headerView;
        [self updateHeaderViewLayout];
        self.headerView.hidden = YES;
    } completion:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        [self updateHeaderViewLayout];
        self.headerView.hidden = NO;
    }];
}

- (void)setSubtitle:(NSString *)subtitle {
    self.headerView.subtitle.text = subtitle;
    
}

@end
