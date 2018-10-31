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
#import "TTADPGeoJsonObject.h"
#import "TTADPLineString.h"

/*
A  Geometry type comprising one or more LineStrings. The
exterior ring represents the outer edges of a polygon and is a
LineStrings of at least four Positions in counterclockwise
order. The interior rings (0 or more) - LineStrings of at least four
Positions in clockwise order - define holes in the polygon. In all
cases the first and the last position in a LineString contain identical
values.
 */
@interface TTADPPolygon : TTADPGeoJsonObject

/**
Object of TTADPLineString.
 */
@property (nonatomic, strong, readonly) TTADPLineString * _Nonnull exteriorRing;

/**
Array of TTADPLineString objects.
 */
@property (nonatomic, strong, readonly) NSArray<TTADPLineString *> * _Nonnull interiorRings;

@end