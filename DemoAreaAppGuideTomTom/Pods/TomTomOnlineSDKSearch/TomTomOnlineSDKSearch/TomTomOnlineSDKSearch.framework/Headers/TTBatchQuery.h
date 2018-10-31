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
#import "TTSearchQuery.h"
#import "TTReverseGeocoder.h"
#import "TTGeometrySearch.h"

@class TTBatchQuery;

/**
 Batch request query builder
 */
@interface TTBatchQueryBuilder: NSObject

-(instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Create query builder with TTSearchQuery
 
 @param query TTSearchQuery will be added to batch request.
 @return TTBatchQueryBuilder
 */
+ (TTBatchQueryBuilder * _Nonnull)createSearchQuery:(TTSearchQuery * _Nonnull)query;

/**
 Create query builder with TTReverseGeocoderQuery
 
 @param query TTReverseGeocoderQuery will be added to batch request.
 @return TTBatchQueryBuilder
 */
+ (TTBatchQueryBuilder * _Nonnull)createReverseGeocoderQuery:(TTReverseGeocoderQuery * _Nonnull)query;

/**
 Create query builder with TTGeometrySearchQuery
 
 @param query TTGeometrySearchQuery will be added to batch request.
 @return TTBatchQueryBuilder
 */
+ (TTBatchQueryBuilder * _Nonnull)createGeometryQuery:(TTGeometrySearchQuery * _Nonnull)query;

/**
 Adds TTSearchQuery to batch request

 @param query TTSearchQuery to be added
 @return TTBatchQueryBuilder
 */
- (TTBatchQueryBuilder * _Nonnull)addSearchQuery:(TTSearchQuery * _Nonnull)query;

/**
 Adds TTReverseGeocoderQuery to batch request
 
 @param query TTReverseGeocoderQuery to be added
 @return TTBatchQueryBuilder
 */
- (TTBatchQueryBuilder * _Nonnull)addReverseGeocoderQuery:(TTReverseGeocoderQuery * _Nonnull)query;

/**
 Adds TTGeometrySearchQuery to batch request
 
 @param query TTGeometrySearchQuery to be added
 @return TTBatchQueryBuilder
 */
- (TTBatchQueryBuilder * _Nonnull)addGeometryQuery:(TTGeometrySearchQuery * _Nonnull)query;

/**
 *Baseed on provided data builds query object
 *@return TTBatchQuery
 */
- (TTBatchQuery * _Nonnull)build;

@end

/**
 Batch query
 */
@interface TTBatchQuery : NSObject

-(instancetype _Nonnull)init NS_UNAVAILABLE;

@end
