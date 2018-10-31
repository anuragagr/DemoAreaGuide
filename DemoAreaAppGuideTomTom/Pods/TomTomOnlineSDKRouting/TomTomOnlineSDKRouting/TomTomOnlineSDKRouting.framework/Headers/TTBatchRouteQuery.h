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
#import "TTCommonQueryBuilder.h"
#import "TTRouteQuery.h"

/**
 Class TTBatchRouteQuery contains parameters needed for build query.
 */
@interface TTBatchRouteQuery : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;
    
@end

/**
 Class TTBatchRouteQueryBuilder builds a query, using parameters.
 */
@class TTBatchRouteQueryBuilder;

@interface TTBatchRouteQueryBuilder : TTCommonQueryBuilder<TTBatchRouteQueryBuilder *>

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Create query builder with TTRouteQuery

 @param query TTRouteQuery will be added to batch request.
 @return TTBatchRouteQueryBuilder
 */
+ (TTBatchRouteQueryBuilder* _Nonnull)createRouteQuery:(TTRouteQuery* _Nonnull)query;

/**
 Adds TTRouteQuery to batch request

 @param query TTRouteQuery to be added
 @return TTBatchRouteQueryBuilder
 */
- (TTBatchRouteQueryBuilder* _Nonnull)addRouteQuery:(TTRouteQuery* _Nonnull)query;

/**
 @return TTBatchRouteQuery
 */
- (TTBatchRouteQuery* _Nonnull) build;

@end

