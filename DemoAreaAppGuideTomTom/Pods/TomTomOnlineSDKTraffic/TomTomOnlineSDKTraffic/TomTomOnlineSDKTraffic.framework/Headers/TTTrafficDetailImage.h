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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TTTrafficDetailBase.h"

@interface TTTrafficDetailImage : NSObject

+ (TTTrafficDetailImage* _Nonnull)createWithTraffic:(TTTrafficDetailBase* _Nonnull)detail;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithTraffic:(TTTrafficDetailBase* _Nonnull)detail;


/**
 Gets small size of image.
 */
@property (nonatomic, strong, readonly) UIImage* _Nonnull small;

/**
 Gets medium size of image.
 */
@property (nonatomic, strong, readonly) UIImage* _Nonnull medium;

/**
 Gets large size of image.
 */
@property (nonatomic, strong, readonly) UIImage* _Nonnull large;

@end
