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
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>
#import "TTBatchRouteQuery.h"
#import "TTBatchRouteResponse.h"

@class TTBatchRoute;

/**
 Protocol for TTBatchRoute - TTBatchRouteResponseDelegate
 */
@protocol TTBatchRouteResponseDelegate <NSObject>

/**

 @param route - object TTBatchRoute
 @param response completed With TTBatchRouteResult
 */
- (void)batch:(TTBatchRoute * _Nonnull)route completedWithResponse:(TTBatchRouteResponse* _Nonnull)response;


/**

 @param route - object TTBatchRoute
 @param responseError - completed With Response TTResponseError
 */
- (void)batch:(TTBatchRoute * _Nonnull)route failedWithError:(TTResponseError * _Nonnull)responseError;

@end


/**
 *TomTom Route API main object. Contains methods to use Tomtom’s online route engine and provides support for both async and sync calls.
 */
@interface TTBatchRoute : NSObject

@property (nonatomic, weak) id<TTBatchRouteResponseDelegate> _Nullable delegate;

/**
 *Route with async callback
 *
 *@param query Object containing the data needed to perform a route query.
 */
- (void)batchRouteWithQuery:(TTBatchRouteQuery* _Nonnull)query;

- (void)batchRouteWithQuery:(TTBatchRouteQuery* _Nonnull)query completionHandler:(void (^_Nonnull)(TTBatchRouteResponse* _Nullable response, TTResponseError* _Nullable error))completionHandler;

/**
 *Cancels the current routing request
 */
- (void)cancel;

@end
