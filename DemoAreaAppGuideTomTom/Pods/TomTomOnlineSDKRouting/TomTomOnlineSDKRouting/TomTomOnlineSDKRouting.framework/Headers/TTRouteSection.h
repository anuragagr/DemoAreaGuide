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
#import "TTTec.h"
/**
  A TTInstructionGroup contains section of route information between a requested start and end point.
 */
@interface TTRouteSection : NSObject

/**
 Index of the first point (offset 0) in the route this section applies to (only included for routeRepresentation polyline).
 */
@property (nonatomic, readonly, strong) NSNumber *startPointIndex;

/**
 Index of the last point (offset 0) in the route this section applies to (only included for routeRepresentation polyline).
 */
@property (nonatomic, readonly, strong) NSNumber *endPointIndex;

/**
 This attribute is either set to the value given to the request parameter
 travelMode, if this travel mode is possible, or to other which indicates that the given mode
 of transport is not possible in this section. This field can only be used within sections
 of type TRAVEL_MODE.
 */
@property (nonatomic, readonly, strong) NSString *travelMode;


/**
 Delay in seconds caused by the incident.
 */
@property (nonatomic, strong) NSNumber *delayInSeconds;

/**
 Type of the incident.
 */
@property (nonatomic, strong) NSNumber *effectiveSpeedInKmh;

/**
 The magnitude of delay caused by the incident.
 */
@property (nonatomic, strong) NSNumber *magnitudeOfDelay;

/**
 Specifies which of the section types is reported in the route response.
 */
@property (nonatomic, strong) NSString *sectionType;

/**
 Placeholder.
 */
@property (nonatomic, strong) NSString *simpleCategory;

/**
 Details of the traffic event.
 */
@property (nonatomic, strong) TTTec *tec;

@end
