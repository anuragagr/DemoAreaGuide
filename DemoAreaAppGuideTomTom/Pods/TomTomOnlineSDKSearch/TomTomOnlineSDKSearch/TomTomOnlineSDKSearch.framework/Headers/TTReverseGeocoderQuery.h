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

__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeCountry;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeCountryCode;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeCountryCodeISO3;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeCountrySubdivision;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeCountrySubdivisionName;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeCountrySecondarySubdivision;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeMunicipality;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeMunicipalitySubdivision;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeStreet;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeStreetName;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeStreetNameAndNumber;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributePostalCode;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeBuildingNumber;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeStreetNumber;
__attribute__ ((deprecated))
extern NSString * _Nonnull const TTReverseGeocoderAttributeFreeformAddress;


@interface TTReverseGeocoderQuery : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end

@interface TTReverseGeocoderQueryBuilder : NSObject
    
- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 @param coordinate The map coordinate whose geographical information you want to retrieve.
 @return TTReverseGeocoderQueryBuilder
 */
+(TTReverseGeocoderQueryBuilder* _Nonnull)createWithCLLocationCoordinate2D:(CLLocationCoordinate2D)coordinate;


/**
 @param radius The maximum distance in meters from the specified position for the reverse geocoder to consider.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withRadius:(NSUInteger)radius;


/**
 @param languageType languageType
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withLanguage:(TTLanguage)languageType;


/**
 @param heading The directional heading of travel along a segment of roadway. 0 is North, 90 is East and so on. Values range from -360 to 360. can have up to one decimal place of precision.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withHeading:(NSUInteger)heading;


/**
 @param number Optional house number for the request. If this is used, the response may include the side of the street (Left/Right) and the offset position for that number.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withNumber:(NSString * _Nonnull)number;


/**
 @param returnSpeedLimit Return the posted speed limit (where available).
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withReturnSpeedLimit:(BOOL)returnSpeedLimit;


/**
 @param returnRoadUse Return the road use array. Only available for street-level reverse geocodes.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withReturnRoadUse:(BOOL)returnRoadUse;


/**
 @param tolerance tolerance
 @return TTReverseGeocoderQueryBuilder
 @deprecated No longer support by end point.
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withTolerance:(NSNumber * _Nonnull)tolerance DEPRECATED_MSG_ATTRIBUTE("No longer support by end point.");


/**
 @param returnMatchType returnMatchType
 @return TTReverseGeocoderQueryBuilder
 @deprecated No longer support by end point.
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withReturnMatchType:(BOOL)returnMatchType DEPRECATED_MSG_ATTRIBUTE("No longer support by end point.");


/**
 @param addressAttributes addressAttributes
 @return TTReverseGeocoderQueryBuilder
 @deprecated No longer support by end point.
 */
-(TTReverseGeocoderQueryBuilder* _Nonnull)withAddressAttributes:(NSArray<NSString *> * _Nonnull)addressAttributes DEPRECATED_MSG_ATTRIBUTE("No longer support by end point.");


/**
 @return TTReverseGeocoderQuery
 */
-(TTReverseGeocoderQuery* _Nonnull)build;

@end

