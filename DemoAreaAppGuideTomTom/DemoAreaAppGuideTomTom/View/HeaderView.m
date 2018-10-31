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

#import "HeaderView.h"


@implementation HeaderView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if(self) {
        [self setupViews];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if(self) {
        [self setupViews];
    }
    return self;
}

- (void)setFrame:(CGRect)frame {
    frame = CGRectMake(0, 0, CGRectGetWidth(frame), CGRectGetHeight(frame));
    [super setFrame:frame];
}

- (void)setCenter:(CGPoint)center {
    center = CGPointMake((CGRectGetWidth(self.frame) * 0.5), center.y);
    [super setCenter:center];
}

- (void)setupViews {
    self.userInteractionEnabled = NO;
    UIView *view = [[[NSBundle mainBundle] loadNibNamed:@"HeaderView" owner:self options:nil] firstObject];
    view.frame = self.bounds;
    [view setBackgroundColor:[UIColor clearColor]];
    [self setBackgroundColor:[UIColor clearColor]];
    [self addSubview:view];
}

@end
