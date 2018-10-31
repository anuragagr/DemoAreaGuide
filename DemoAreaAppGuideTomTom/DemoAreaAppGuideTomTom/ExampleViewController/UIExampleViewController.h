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

#import <UIKit/UIKit.h>
#import "UIConst.h"

@protocol UIExampleViewControllerDelegate <NSObject>

@optional
- (void)optionButtonTag:(NSInteger)tag index:(int)index;

@end

@interface UIExampleViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *navTitle;
@property (weak, nonatomic) IBOutlet UILabel *navSubtitle;

@property (weak, nonatomic) IBOutlet UIButton *locateMeButton;

@property (weak, nonatomic) IBOutlet UIView *optionsContainer;

@property (weak, nonatomic) IBOutlet UIButton *option1;
@property (weak, nonatomic) IBOutlet UIButton *option2;
@property (weak, nonatomic) IBOutlet UIButton *option3;
@property (nonatomic, assign) BOOL multiSelect;
@property (weak, nonatomic) id <UIExampleViewControllerDelegate> delegate;

@property (assign, nonatomic) BOOL showToastEnable;

- (void)createSegmentedControllWithTag:(NSInteger)tag options:(NSArray<NSString *> *)options multiSelect:(BOOL)multiselect select:(NSInteger)select;
- (void)deselectOptionIndexs:(NSArray *)indexs;
- (void)deselectAll;

- (void)buildHeader:(NSString*)TitleB and:(NSString*) SubtitleB;
- (void)setSubtitle:(NSString *)subtitle;

- (void)showToast:(NSString *)text withTimer:(BOOL)timerEnable;

@end
