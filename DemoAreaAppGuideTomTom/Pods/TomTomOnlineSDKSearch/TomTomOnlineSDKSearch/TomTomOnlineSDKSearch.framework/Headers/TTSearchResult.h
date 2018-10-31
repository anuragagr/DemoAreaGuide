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
#import "TTAddress.h"
#import "TTBoundingBox.h"
#import "TTPoi.h"
#import "TTEntryPoint.h"
#import "TTAddressRanges.h"
#import "TTAdditionalDataSources.h"

@interface TTSearchResult : NSObject

/**
 * The id of result.
 */
@property (nonatomic, readonly, strong) NSString * _Nonnull identifier;
/**
 * The type of result (should always be "POI").
 */
@property (nonatomic, readonly, strong) NSString * _Nonnull type;
/**
 * The score of the result.
 */
@property (nonatomic, readonly, assign) double score;
/**
 * Detailed address of the result.
 */
@property (nonatomic, readonly, strong) TTAddress * _Nonnull address;
/**
 * The geographical position of the POI.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D position;
/**
 * The viewport.
 */
@property (nonatomic, readonly, strong) TTBoundingBox * _Nonnull viewport;
/**
 * The distance from the route provided in the request.
 */
@property (nonatomic, readonly, assign) double distance;
/**
 * Additional info.
 */
@property (nonatomic, readonly, strong) NSString * _Nonnull info;
/**
 * (Only for results of type "Geography") Type of the entity (one of "County", "CountrySubdivision",
 * "CountrySecondarySubdivision", "CountryTeritarySubdivision", "Municipality", "MunicipalitySubdivision",
 * "Neighbourhood", "PostalCodeArea").
 */
@property (nonatomic, readonly, strong) NSString * _Nullable entityType;
/**
 * Information about the POI.
 */
@property (nonatomic, readonly, strong) TTPoi * _Nullable poi;
/**
 * An rectangle into which a shape of an administrative area is inscribed in.
 * Available only for results where result type is equal to "Geography" and municipality information is not present.
 */
@property (nonatomic, readonly, strong) TTBoundingBox * _Nullable boundingbox;
/**
 * A list of entrances to the POI.
 */
@property (nonatomic, readonly, strong) NSArray<TTEntryPoint *> * _Nullable entryPoints;
/**
 * Address ranges on a street segment. Available only for results where result type is equal to "Address Range".
 */
@property (nonatomic, readonly, strong) TTAddressRanges * _Nullable addressRanges;
/**
 * Additional data sources related with result.
 */
@property (nonatomic, readonly, strong) TTAdditionalDataSources * _Nullable additionalDataSources;

@end
