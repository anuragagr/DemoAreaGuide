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
#import "TTReachableRangeQuery.h"
#import "TTReachableRangeResponse.h"

@class TTReachableRange;

@protocol TTReachableRangeDelegate <NSObject>

/**
 The Calculate Reachable Range service calculates a set of locations that can be reached from the origin point. It optimizes for routes with a given route-type (e.g. fastest, eco, etc) but limits the range for the given budget and consumption parameters.
 
 The information returned is a polygon boundary in counterclockwise orientation and the precise polygon center (the result of map-matching the origin point).
 
 @param range Object type TTReachableRange.
 @param response Object type TTReachableRangeResponse.
 */
- (void)reachableRange:(TTReachableRange * _Nonnull)range completedWithResult:(TTReachableRangeResponse * _Nonnull)response;

/**
 Method responsible to handle reachable range errors. Within this callback user will obtain TTResponseError containing a Throwable fail reason
 
 @param range Object type TTReachableRange.
 @param responseError Object type TTResponseError.
 */
- (void)reachableRange:(TTReachableRange * _Nonnull)range completedWithResponseError:(TTResponseError * _Nonnull)responseError;
    
@end

/**
 TomTom Reachable Range API main object.
 */
@interface TTReachableRange : NSObject

/**
 Register delegate to receive callbacks with result or error response.
 */
@property (nonatomic, weak) id<TTReachableRangeDelegate> _Nullable delegate;

/**
 Perform request using completion handler.

 @param query TTReachableRangeQuery contains data needed to perform request.
 @param completionHandler CompletionHandler that informs the subscriber when a result is available.
 */
- (void)findReachableRange:(TTReachableRangeQuery * _Nonnull)query
         completionHandler:(void (^_Nonnull)(TTReachableRangeResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
 Perform request using completion handler.

 @param query TTReachableRangeQuery contains data needed to perform request.
 */
- (void)findReachableRangeWithQuery:(TTReachableRangeQuery * _Nonnull)query;

/**
 Cancels the current request.
 */
- (void)cancel;
    
@end
