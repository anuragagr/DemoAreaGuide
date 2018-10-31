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

typedef NS_ENUM(NSInteger, TTTrafficStyleType) {
    TTTrafficStyleTypeAbsolute = 0,
    TTTrafficStyleTypeRelative,
    TTTrafficStyleTypeRelativeDelay
};

typedef NS_ENUM(NSInteger, TTTrafficIncidentStyleType) {
    TTTrafficIncidentStyleTypeS1 = 0,
    TTTrafficIncidentStyleTypeS2,
    TTTrafficIncidentStyleTypeS3,
    TTTrafficIncidentStyleTypeNight
};

typedef NS_ENUM(NSInteger, TTTrafficFormatType) {
    TTTrafficFormatTypeXml,
    TTTrafficFormatTypeJson,
    TTTrafficFormatTypeJsonp
};

typedef NS_ENUM(NSInteger, TTTrafficUnitType) {
    TTTrafficUnitTypeKMPH = 1,
    TTTrafficUnitTypeMPH
};

typedef NS_ENUM(NSInteger, TTTrafficGeometriesType) {
    TTTrafficGeometriesTypeOriginal,
    TTTrafficGeometriesTypeShifted
};

typedef NS_ENUM(NSInteger, TTTrafficDetailsCategoryIcon) {
    TTTrafficDetailsCategoryIconUnknown = 0,
    TTTrafficDetailsCategoryIconAccident,
    TTTrafficDetailsCategoryIconFog,
    TTTrafficDetailsCategoryIconDangerConditions,
    TTTrafficDetailsCategoryIconRain,
    TTTrafficDetailsCategoryIconIce,
    TTTrafficDetailsCategoryIconJam,
    TTTrafficDetailsCategoryIconLaneClosed,
    TTTrafficDetailsCategoryIconRoadClosed,
    TTTrafficDetailsCategoryIconRoadWorks,
    TTTrafficDetailsCategoryIconWind,
    TTTrafficDetailsCategoryIconFlooding,
    TTTrafficDetailsCategoryIconDetour,
    TTTrafficDetailsCategoryIconCluster
};

typedef NS_ENUM(NSInteger, TTTrafficDetailsMagnitude) {
    TTTrafficDetailsMagnitudeUnknown = 0,
    TTTrafficDetailsMagnitudeMinor,
    TTTrafficDetailsMagnitudeModerate,
    TTTrafficDetailsMagnitudeMajor,
    TTTrafficDetailsMagnitudeUndefined
};


@interface TTTrafficUtils : NSObject

@end
