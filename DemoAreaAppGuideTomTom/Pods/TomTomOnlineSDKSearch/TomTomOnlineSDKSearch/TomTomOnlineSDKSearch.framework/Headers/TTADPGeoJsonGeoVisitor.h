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
#import "TTADPPosition.h"
#import "TTADPLineString.h"
#import "TTADPMultiPoint.h"
#import "TTADPMultiLineString.h"
#import "TTADPPolygon.h"
#import "TTADPMultiPolygon.h"

@class TTADPGeometryCollection;

@protocol TTADPGeoJsonGeoVisitor <NSObject>

@optional

/**
 Calls one of method depense contain of position date

 @param position Object type TTADPPosition
 */
- (void)visitPosition:(TTADPPosition * _Nonnull)position;

/**
 Calls one of method depense contain of lineString date

 @param lineString Object type TTADPLineString
 */
- (void)visitLineString:(TTADPLineString * _Nonnull)lineString;

/**
 Calls one of method depense contain of multiPoint date

 @param multiPoint Object type TTADPMultiPoint
 */
- (void)visitMultiPoint:(TTADPMultiPoint * _Nonnull)multiPoint;

/**
 Calls one of method depense contain of multiLineString date

 @param multiLineString Object type TTADPMultiLineString
 */
- (void)visitMultiLineString:(TTADPMultiLineString * _Nonnull)multiLineString;

/**
 Calls one of method depense contain of polygon date

 @param polygon Object type TTADPPolygon
 */
- (void)visitPolygon:(TTADPPolygon * _Nonnull)polygon;

/**
 Calls one of method depense contain of polygon date

 @param multiPolygon Object type TTADPMultiPolygon
 */
- (void)visitMultiPolygon:(TTADPMultiPolygon * _Nonnull)multiPolygon;

/**
 Calls one of method depense contain of polygon date

 @param geometryCollection Object type TTADPGeometryCollection
 */
- (void)visitGeometryCollection:(TTADPGeometryCollection * _Nonnull)geometryCollection;

@end
