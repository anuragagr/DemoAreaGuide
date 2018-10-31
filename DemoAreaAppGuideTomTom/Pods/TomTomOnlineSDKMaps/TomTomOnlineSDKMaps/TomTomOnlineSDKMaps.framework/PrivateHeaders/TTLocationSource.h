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
#import "TTPositionUpdate.h"

@protocol TTLocationSource <NSObject>

@required
/**
 * Is called when new location is found by the corresponding location source provider.
 @param coordinate new coordinate found by the location provider.
 @param bearing new bearing found by the location provider.
 @param radius new radius found by the location provider.
 @param accuracy new accuracy of the location data.
 */
- (void)onLocationChanged:(CLLocationCoordinate2D)coordinate withBearing:(double)bearing withRadius:(double)radius withAccuracy:(CLLocationAccuracy)accuracy;

/**
 * Activates the provider. The provider will notify the instances periodically,
 * until the user calls deactivate().
 */
- (void)activate;

/**
 * Deactivates this provider. The provider does not send any location notifications.
 */
- (void)deactivate;

@end
