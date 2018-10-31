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

/**
 TTFlowSegmentDataQuery represent request object for Segment Data.
 */
@interface TTFlowSegmentDataQuery : NSObject

- (instancetype _Nullable)init NS_UNAVAILABLE;

@end

@interface TTFlowSegmentDataQueryBuilder : NSObject

/**
  Builder of TTFlowSegmentDataQueryBuilder object

 @param style The type of flow data to be displayed on the tile.
 @param zoom Zoom level. This will affect traffic incident coordinates to present both road sides separately.
 @param point Coordinate of the point close to the road segment. They have to be comma-separated and calculated using EPSG4326 projection.
 @return TTFlowSegmentDataQueryBuilder object
 */
+ (TTFlowSegmentDataQueryBuilder* _Nonnull)createWithStyle:(TTTrafficStyleType)style withZoom:(NSUInteger)zoom withCoordiante:(CLLocationCoordinate2D)coordiante;

/**
  Part of builder TTFlowSegmentDataQueryBuilder object.

 @param unit Unit of speed.
 @return TTFlowSegmentDataQueryBuilder
 */
- (TTFlowSegmentDataQueryBuilder* _Nonnull)withUnit:(TTTrafficUnitType)unit;

/**
 Part of builder TTFlowSegmentDataQueryBuilder object.

 @param thickness Segment width multiplier.
 @return TTFlowSegmentDataQueryBuilder
 */
- (TTFlowSegmentDataQueryBuilder* _Nonnull)withThickness:(NSNumber* _Nonnull)thickness;

/**
 Part of builder TTFlowSegmentDataQueryBuilder object.

 @param openLr Should response include OpenLR code?
 @return TTFlowSegmentDataQueryBuilder
 */
- (TTFlowSegmentDataQueryBuilder* _Nonnull)withOpenLr:(BOOL)openLr;

/**
 Build method.
 
 @return TTFlowSegmentDataQuery object.
 */
- (TTFlowSegmentDataQuery* _Nonnull)build;

@end

