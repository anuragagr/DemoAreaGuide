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
#import "TTTrafficDetailBase.h"

@interface TTTrafficDetail : TTTrafficDetailBase

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Gets the point representing the actual position of the incident.
 Only present if requested othervise kCLLocationCoordinate2DInvalid
 */
@property (nonatomic,readonly) CLLocationCoordinate2D originalPosition;

/**
 Gets cause of the incident, where available, in the language requested.
 */
@property (nonatomic,readonly) NSString* _Nonnull cause;

/**
 Gets description of the incident in the language requested.
 */
@property (nonatomic,readonly) NSString* _Nonnull desc;

/**
 Gets the name of the intersection or location where the traffic due to the incident starts.
 */
@property (nonatomic,readonly) NSString* _Nonnull from;

/**
 Gets the name of the intersection or location where the traffic due to the incident ends.
 */
@property (nonatomic,readonly) NSString* _Nonnull to;

/**
 Gets the delay caused by the incident in seconds (except in road closures).
 Delay is optional if not available then returns -1
 */
@property (nonatomic,readonly) NSInteger delay;

/**
 Gets the road number(s) affected by the incident.
 */
@property (nonatomic,readonly) NSArray<NSString*>* _Nonnull affectedRoadNumbers;

/**
 Gets a vector representing the geometry of the incident. Not available for clusters and incidents that do not have a shape/length.
 */
@property (nonatomic,readonly) NSArray<NSValue*>* _Nonnull geometry;

@end
