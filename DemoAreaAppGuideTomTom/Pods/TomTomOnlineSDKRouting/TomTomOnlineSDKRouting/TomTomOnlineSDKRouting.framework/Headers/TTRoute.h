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
#import "TTFullRoute.h"
#import "TTRouteQuery.h"
#import "TTRouteResult.h"


@class TTRoute;

/**
 Protocol for TTRoute - TTRouteResponseDelegate
 */
@protocol TTRouteResponseDelegate <NSObject>

@optional
/**
 @param route - object TTRoute
 @param result completed With TTRouteResult
 */
- (void)route:(TTRoute * _Nonnull)route completedWithResult:(TTRouteResult * _Nonnull)result;


/**
 @param route - object TTRoute
 @param responseError - completed With Response TTResponseError
 */
- (void)route:(TTRoute * _Nonnull)route completedWithResponseError:(TTResponseError * _Nonnull)responseError;

@end


/**
 *TomTom Route API main object. Contains methods to use Tomtom’s online route engine and provides support for both async and sync calls.
 */
@interface TTRoute : NSObject

@property (nonatomic, weak) id<TTRouteResponseDelegate> _Nullable delegate;

/**
 *Route with async block
 *
 *@param query Object containing the data needed to perform a route query.
 *@param completionHandler CompletionHandler that informs the subscriber when a route result is available. It contains a TTRouteResult object.
 */
- (void)planRouteWithQuery:(TTRouteQuery * _Nonnull)query
      completionHandler:(void (^_Nonnull)(TTRouteResult * _Nullable result, TTResponseError * _Nullable error))completionHandler;

      /**
 *Route with async callback
 *
 *@param query Object containing the data needed to perform a route query.
 */
- (void)planRouteWithQuery:(TTRouteQuery* _Nonnull)query;

/**
 *Cancels the current routing request
 */
- (void)cancel;

@end
