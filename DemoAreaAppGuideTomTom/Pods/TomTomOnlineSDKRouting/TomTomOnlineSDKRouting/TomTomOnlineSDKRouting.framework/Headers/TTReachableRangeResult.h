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
#import <CoreLocation/CoreLocation.h>
#import "TTReachableRangeResult.h"

@interface TTReachableRangeResult : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Location used as a center reachanble range for calculation.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D centerLocation;


/**
 Number of boundries in response.
 */
@property (nonatomic, assign, readonly) NSUInteger boundriesCount;


/**
 Returns CLLocationCoordinate2D boundry coordinate for given index.

 @param index NSUInteger cant be higher than boundriesCount - 1
 @return CLLocationCoordinate2D
 */
- (CLLocationCoordinate2D)boundryAt:(NSUInteger)index;

@end
