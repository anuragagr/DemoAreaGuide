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
#import <CoreLocation/CoreLocation.h>

@class TTMapView;

@interface TTTrackingObject : NSObject

- (instancetype _Nonnull)initWithMapView:(TTMapView * _Nonnull)mapView
                 withActiveLocationImage:(UIImage * _Nonnull)imageActive
               withInactiveLocationImage:(UIImage * _Nonnull)imageInactive;

- (void)setHidden:(BOOL)hidden;
- (BOOL)isHidden;

- (void)setLocation:(CLLocationCoordinate2D)coordinate withRadius:(double)radius withAccuracy:(double)accuracy isDimmed:(BOOL)isDimmed;

@end
