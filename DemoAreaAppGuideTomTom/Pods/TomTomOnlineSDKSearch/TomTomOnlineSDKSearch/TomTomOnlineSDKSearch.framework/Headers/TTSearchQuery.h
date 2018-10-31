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
#import "TTSearchTypes.h"

typedef NS_OPTIONS(NSUInteger, TTExtendedPostalCodesIndexes) {
    TTExtendedPostalCodesIndexNone = 0,
    TTExtendedPostalCodesIndexAddr = 1 << 0,
    TTExtendedPostalCodesIndexGeo = 1 << 1,
    TTExtendedPostalCodesIndexPAD = 1 << 2,
    TTExtendedPostalCodesIndexPOI = 1 << 3,
    TTExtendedPostalCodesIndexStr = 1 << 4,
    TTExtendedPostalCodesIndexXStr = 1 << 5
} DEPRECATED_MSG_ATTRIBUTE("This enum is deprecated. Use TTSearchIndex");

@class TTSearchQuery;

/**
 *TTSearchQueryBuilder Search query
 */
@interface TTSearchQueryBuilder : NSObject
    
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 *Create query builder with term
 *
 *@param term Query to be searched.
 *@return TTSearchQueryBuilder
 */
+(TTSearchQueryBuilder* _Nonnull)createWithTerm:(NSString* _Nonnull)term;


/**
 *@param limit Maximum number of search results that will be returned by the search service.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withLimit:(NSUInteger)limit;


/**
 *@param offset Starting offset of the returned results within the full result set.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withOffset:(NSUInteger)offset;


/**
 *@param position Position where results should be biased.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withPosition:(CLLocationCoordinate2D)position;


/**
 *@param position Position for which the results should be biased.
 *@param radius If radius and location are set, the results will be constrained to the defined area.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withPosition:(CLLocationCoordinate2D)position withRadius:(int)radius;


/**
 *@param countrySet This will limit the search to the specified countries.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withCountrySet:(NSSet<NSString*>* _Nonnull)countrySet;


/**
 *@param idxSet Specifies which indexes to use for the search. The predefined indexes are: Addr (address range interpolation), Geo (Geographies), Str (streets).
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withIdxSet:(TTSearchIndex)idxSet;


/**
 *@param languageType Language
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withLanguage:(TTLanguage)languageType;


/**
 @param extendedPostalCodesIndexes extendedPostalCodesIndexes Indexes for which extended postal codes should be included in the results.
 @return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withExtendedPostalCodesFor:(TTSearchIndex)extendedPostalCodesIndexes;


/**
 *@param topLeft Top left corner of the bounding box.
 *@param bottomRight Bottom right corner of the bounding box.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withBoundingBoxTopLeft:(CLLocationCoordinate2D)topLeft
                             withBoundingBoxBottomRight:(CLLocationCoordinate2D)bottomRight;


/**
 *@param isTypeAhead If the "typeahead" flag is set, the query will be interpreted as a partial input and the search will enter predictive mode.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withTypeAhead:(BOOL)isTypeAhead;


/**
 *@param isCategory Indicates whether the query a category query.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withCategory:(BOOL)isCategory;


/**
 *@param minFuzzyLevel Minimum fuzziness level to be used.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withMinFuzzyLevel:(NSUInteger)minFuzzyLevel;


/**
 *@param maxFuzzyLevel Maximum fuzziness level to be used.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder* _Nonnull)withMaxFuzzyLevel:(NSUInteger)maxFuzzyLevel;
    
/**
 *Baseed on provided data builds query object
 *@return TTSearchQuery
 */
-(TTSearchQuery* _Nonnull)build;
    
@end


@interface TTSearchQuery : NSObject
    
- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end
