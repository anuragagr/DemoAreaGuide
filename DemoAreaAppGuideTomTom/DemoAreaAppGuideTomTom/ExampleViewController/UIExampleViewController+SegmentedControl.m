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

#import "UIExampleViewController+SegmentedControl.h"

@interface UIExampleViewController()

@end

@implementation UIExampleViewController (SegmentedControl)

- (void)setSegmentHidden:(BOOL)segmentHidden {
    self.option1.hidden = self.option2.hidden = self.option3.hidden = segmentHidden;
    [self.optionsContainer setHidden:segmentHidden];

}

- (void)setSegmentTag:(NSInteger)tag {
    self.option1.tag = self.option2.tag = self.option3.tag = tag;
}

- (void)createSegments:(NSArray<NSString *> *)segments {
    
    [self.optionsContainer setHidden:NO];
    
    switch (segments.count) {
        case 3:
        {
            [self.option1 setTitle:segments[2] forState:UIControlStateNormal];
            [self.option1 setHidden:NO];
        }
        case 2:
        {
            [self.option2 setTitle:segments[1] forState:UIControlStateNormal];
            [self.option2 setHidden:NO];
        }
        case 1:
        {
            [self.option3 setTitle:segments[0] forState:UIControlStateNormal];
            [self.option3 setHidden:NO];
        }
        default:
            break;
    }
}

- (void)selectSegment:(NSInteger)index selected:(BOOL)selected {
    if(!self.multiSelect) {
        [self deselectAll];
    }
    switch (index) {
        case 0:
            self.option3.selected = selected;
            break;
        case 1:
            self.option2.selected = selected;
            break;
        case 2:
            self.option1.selected = selected;
            break;
    }
}

- (void)toogleSelectSegment:(NSInteger)index {
    switch (index) {
        case 0:
            self.option3.selected = !self.option3.selected;
            break;
        case 1:
            self.option2.selected = !self.option2.selected;
            break;
        case 2:
            self.option1.selected = !self.option1.selected;
            break;
    }
}

- (void)deselectAll {
    self.option1.selected = false;
    self.option2.selected = false;
    self.option3.selected = false;
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

- (NSArray *)selectedItems {
    NSMutableArray *array = [NSMutableArray array];
    if(self.option3.selected) [array addObject:[NSNumber numberWithInteger:0]];
    if(self.option2.selected) [array addObject:[NSNumber numberWithInteger:1]];
    if(self.option1.selected) [array addObject:[NSNumber numberWithInteger:2]];
    return [array copy];
}

@end
