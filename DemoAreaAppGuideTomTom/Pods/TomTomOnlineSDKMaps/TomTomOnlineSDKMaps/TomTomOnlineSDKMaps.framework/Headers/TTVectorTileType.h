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
#import "TTTrafficTileStyle.h"

static NSDictionary * _Nonnull typeTTVector;

/**
Vector tile type enumeration

 - TTVectorTileRelative: Speed relative to free-flow, highlighting areas of congestion.
 - TTVectorTileAbsolute: Reflect the absolute speed.
 - TTVectorTileRelativeDelay: Relative speed values different from the ones for the freeflow.
 */
typedef NS_ENUM (NSInteger, TTVectorStyle) {
    TTVectorStyleRelative,
    TTVectorStyleAbsolute,
    TTVectorStyleRelativeDelay
};

/**
 Class that contains information about the type of Vector Tile
 */
@interface TTVectorTileType : TTTrafficTileStyle

/**
 Create object of TTVectorTileType type
 
 @param vectorTile Vector tile type enumeration.
 @return object TTVectorTileType.
 */
+ (TTVectorTileType* _Nonnull)setStyle:(TTVectorStyle)vectorTile;

@end
