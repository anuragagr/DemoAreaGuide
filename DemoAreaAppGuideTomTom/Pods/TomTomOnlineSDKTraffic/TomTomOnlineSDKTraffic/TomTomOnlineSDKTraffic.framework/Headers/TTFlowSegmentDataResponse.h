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

@interface TTFlowSegmentDataResponse : NSObject

/**
  Gets the current average speed  at the selected point.
 */
@property (nonatomic,readonly) NSInteger currentSpeed;

/**
 Gets the free flow speed expected under ideal conditions, expressed in the units requested.
 */
@property (nonatomic,readonly) NSInteger freeFlowSpeed;

/**
 Gets current travel time in seconds based on fused real-time measurements between the defined locations in the specified direction.
 */
@property (nonatomic,readonly) double currentTravelTime;

/**
 Gets the free flow speed expected under ideal conditions, expressed in the units requested.
 */
@property (nonatomic,readonly) double freeFlowTravelTime;

/**
 Gets the confidence is a measure of the quality of the provided travel time and speed.
 */
@property (nonatomic,readonly) double confidence;

/**
 Gets the ratio between live and the historical data used to provide the response. Is equal null returns -1.
 */
@property (nonatomic,readonly) double realtimeRatio;

/**
 Gets OpenLR code for segment.
 */
@property (nonatomic,readonly) NSString* _Nonnull openLR;

/**
 Gets array of coordinates. Includes the coordinates describing the shape of the segment. 
 */
@property (nonatomic,readonly) NSMutableArray<NSValue*> * _Nonnull coordinates;


@end
