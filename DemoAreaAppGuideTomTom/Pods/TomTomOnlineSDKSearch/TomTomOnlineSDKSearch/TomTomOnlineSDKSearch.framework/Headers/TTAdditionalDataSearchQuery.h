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
#import "TTGeometryDataSource.h"

/**
 Query Builder Additional Data Search
 */
@class TTAdditionalDataSearchQuery;

@interface TTAdditionalDataSearchQueryBuilder : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Create query builder with geometryDataSource

 @param geometryDataSource object type TTGeometryDataSource
 @return value of TTAdditionalDataSearchQueryBuilder
 */
+ (TTAdditionalDataSearchQueryBuilder * _Nonnull)createWithDataSource:(TTGeometryDataSource * _Nonnull)geometryDataSource;

/**
 Baseed on provided data builds query object

 @return return TTAdditionalDataSearchQuery
 */
- (TTAdditionalDataSearchQuery * _Nonnull)build;

@end

/**
 Additional Data Query
 */
@interface TTAdditionalDataSearchQuery : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end
