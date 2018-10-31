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

static NSDictionary * _Nonnull typeTTRaster;

/**
 Raster tile type enumeration

 - TTRasterTileRelative: Speed relative to free-flow, highlighting areas of congestion.
 - TTRasterTileAbsolute: Reflect the absolute speed.
 - TTRasterTileRelativeDelay: Relative speed values different from the ones for the freeflow.
 - TTRasterStyleReducedSensitivity: Reduced-sensitivity displays relative speeds but larger difference from freeflow (depending on FRC) is required for segment to change the color.
 */
typedef NS_ENUM (NSInteger, TTRasterStyle) {
    TTRasterStyleRelative,
    TTRasterStyleAbsolute,
    TTRasterStyleRelativeDelay,
    TTRasterStyleReducedSensitivity
};

/**
  Class that contains information about the type of Raster Tile
 */
@interface TTRasterTileType : TTTrafficTileStyle

/**
 Create object of TTRasterTileType type

 @param rasterStyle Vector style type enumeration.
 @return object TTRasterTileType.
 */
+ (TTRasterTileType* _Nonnull)setStyle:(TTRasterStyle)rasterStyle;
@end
