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

@interface UIExampleViewController (SegmentedControl)

- (void)setSegmentHidden:(BOOL)segmentHidden;
- (void)setSegmentTag:(NSInteger)tag;

- (void)createSegments:(NSArray<NSString *> *)segments;
- (void)selectSegment:(NSInteger)index selected:(BOOL)selected;

- (void)toogleSelectSegment:(NSInteger)index;
- (void)deselectAll;
- (void)deselectOptionIndexs:(NSArray *)indexs;
- (NSArray *)selectedItems;

@end
