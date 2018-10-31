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
#import "TTTrafficUtils.h"

@interface TTTrafficDetailBase : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Returns the ID of the traffic incident.
 */
@property (nonatomic, strong, readonly) NSString* _Nonnull ID;

/**
 Returns the point where an icon of the cluster or raw incident should be drawn. This is affected by traffic
 style, zoom level and road type.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D adjustPosition;

/**
 Returns the icon category associated with this incident.
 */
@property (nonatomic, assign, readonly) TTTrafficDetailsCategoryIcon iconCategory;

/**
 Returns magnitude of delay associated with incident.
 */
@property (nonatomic, assign, readonly) TTTrafficDetailsMagnitude magnitude;

/**
 Returns lenght.
 */
@property (nonatomic, assign, readonly) NSUInteger length;

@end
