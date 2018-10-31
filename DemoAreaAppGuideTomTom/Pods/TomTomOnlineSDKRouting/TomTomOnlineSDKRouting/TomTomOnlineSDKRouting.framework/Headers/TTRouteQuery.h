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
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>
#import "TTCommonQueryBuilder.h"


/**
 Class TTRouteQuery contains parameters needed for build query.
 */
@interface TTRouteQuery : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;
    
@end


/**
 Class TTRouteQueryBuilder builds a query, using parameters.
 */

@class TTRouteQueryBuilder;

@interface TTRouteQueryBuilder : TTCommonQueryBuilder<TTRouteQueryBuilder *>

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 @param destPosition The map coordinate whose geographical information your destination position.
 @param origPosition The map coordinate whose geographical information your start position.
 @return TTRouteQueryBuilder
 */
+ (TTRouteQueryBuilder* _Nonnull) createWithDest:(CLLocationCoordinate2D) destPosition andOrig:(CLLocationCoordinate2D)origPosition;

/**
 @param instructionsType Guidance instructions will be returned
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withInstructionsType:(TTOptionInstructionsType)instructionsType;

/**
 @param language The language parameter determines the language of the guidance messages.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withLanguage:(TTLanguage)language;

/**
 @param arriveAt The date and time of arrival at the destination point.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withArriveAt:(NSDate* _Nonnull)arriveAt;

/**
 @param maxAlternatives Number of desired alternative routes to be calculated.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withMaxAlternatives:(NSUInteger)maxAlternatives;

/**
 @param isComputeBestOrder The maximum allowed number of waypoints is 50, reduced to 20
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withComputeBestOrder:(BOOL)isComputeBestOrder;

/**
 @param routeRepresentation Specifies the representation of the set of routes provided as response.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withRouteRepresentation:(NSString* _Nonnull)routeRepresentation;

/**
 @param computeTravelTimeFor Specifies whether to return additional travel times using different types of traffic information (none, historic, live) as well as the default best-estimate travel time.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withComputeTravelTimeFor:(NSString* _Nonnull)computeTravelTimeFor;

/**
 @param vehicleHeading The directional heading of the vehicle in degrees starting at true North and continuing in clockwise direction.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withVehicleHeading:(NSUInteger)vehicleHeading;

/**
 @param minDeviationDistance All alternative routes returned will follow the reference route from the origin point of the calculateRoute request for at least this number of meters. Can only be used when reconstructing a route. The minDeviationDistance parameter cannot be used in conjunction with arriveAt.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withMinDeviationDistance:(NSUInteger)minDeviationDistance;

/**
 @param minDeviationTime All alternative routes returned will follow the reference route from the origin point of the calculateRoute request for at least this number of seconds. Can only be used when reconstructing a route. The minDeviationTime parameter cannot be used in conjunction with arriveAt.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withMinDeviationTime:(NSUInteger)minDeviationTime;

/**
 @param sectionType Specifies which of the section types is reported in the route response.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withSectionType:(TTSectionType)sectionType;

/**
 @param supportingPoints A list of base route points to be used as input for route reconstruction.
 @return TTRouteQueryBuilder
 @deprecated This method is deprecated, use withSupportingPoints:count instead.
 */
- (TTRouteQueryBuilder* _Nonnull) withSupportingPoints:(NSMutableArray<NSValue*>* _Nonnull)supportingPoints DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use withSupportingPoints:count instead.");

/**
 @param supportingPoints A list of base route points to be used as input for route reconstruction.
 @return TTRouteQueryBuilder
 */
- (TTRouteQueryBuilder* _Nonnull) withSupportingPoints:(CLLocationCoordinate2D* _Nonnull)supportingPoints count:(NSUInteger)count;

/**
 @return TTRouteQuery
 */
- (TTRouteQuery* _Nonnull) build;

@end

