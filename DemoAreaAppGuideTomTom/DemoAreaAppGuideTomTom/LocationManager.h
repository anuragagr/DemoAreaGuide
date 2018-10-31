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

extern CLLocationDegrees radiansToDegrees_(double radians);

extern double degreesToRadians_(CLLocationDegrees degrees);

#define radiansToDegrees(radians) radiansToDegrees_(radians)
#define degreesToRadians(degrees) degreesToRadians_(degrees)

@interface LocationManager : NSObject

@property (nonatomic, strong, readonly) CLLocation *location;
@property (nonatomic, strong, readonly) CLHeading *heading;
@property (nonatomic, assign, readonly) BOOL serviceStarted;
@property (nonatomic, assign, readonly) BOOL serviceEnabled;
@property (nonatomic, assign, readonly) CLAuthorizationStatus authorizationStatus;
@property (nonatomic, assign, readonly) BOOL canUseDeviceLocation;

+ (instancetype)sharedInstance;
- (void)startService;
- (void)stopService;
- (CLLocationDistance)distanceFromCurrentLocation:(CLLocationCoordinate2D)fromCoord;

@end
