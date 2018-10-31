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
#import "TTSupportedLanguages.h"

#define CLCOORDINATES_EQUAL( coord1, coord2 ) (coord1.latitude == coord2.latitude && coord1.longitude == coord2.longitude)

#define CLCOORDINATE_EPSILON 0.0005f
#define CLCOORDINATES_EQUAL_EPSILON( coord1, coord2 ) (fabs(coord1.latitude - coord2.latitude) < CLCOORDINATE_EPSILON && fabs(coord1.longitude - coord2.longitude) < CLCOORDINATE_EPSILON)


typedef struct TTLatLngBounds {
    CLLocationCoordinate2D seBounds;
    CLLocationCoordinate2D nwBounds;
} TTLatLngBounds;

NS_INLINE TTLatLngBounds TTLatLngBoundsMake(CLLocationCoordinate2D seBounds, CLLocationCoordinate2D nwBounds) {
    TTLatLngBounds bounds;
    bounds.seBounds = seBounds;
    bounds.nwBounds = nwBounds;
    return bounds;
}

@interface TTUtils : NSObject

+ (NSString * _Nonnull)languagePrefixForLanguageType:(TTLanguage)language;
+ (TTLanguage)languageForLocale:(NSLocale *_Nonnull)locale;
+ (CLLocationCoordinate2D)coordinateFromValue:(NSValue *_Nonnull)value;

@end
