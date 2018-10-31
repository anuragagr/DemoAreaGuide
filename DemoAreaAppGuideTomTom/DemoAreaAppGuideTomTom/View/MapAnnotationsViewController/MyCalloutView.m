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

#import "MyCalloutView.h"

@implementation MyCalloutView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if(self) {
        [self comonInit];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if(self){
        [self comonInit];
    }
    return self;
}

- (void)comonInit {
    self.backgroundColor = [UIColor whiteColor];
    self.layer.shadowColor = [[UIColor blackColor] CGColor];
    self.layer.opacity = 1;
    self.layer.shadowOffset = CGSizeMake(2, 2);
    self.layer.shadowOpacity = 1;
}

@end
