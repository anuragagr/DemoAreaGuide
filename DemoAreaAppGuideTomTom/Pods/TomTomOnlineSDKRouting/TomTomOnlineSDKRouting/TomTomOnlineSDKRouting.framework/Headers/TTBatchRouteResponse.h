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
#import "TTRouteResult.h"

@protocol TTBatchRouteVisistor <NSObject>

@optional

/**
 Called when batch returns TTRouteResult

 @param response TTRouteResult
 */
- (void)visitRoute:(TTRouteResult* _Nonnull)response;

@end

/**
 Visitable collection of batch route responses.
 */
@interface TTBatchRouteResponse : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Method allows to visit results returned from batch route depends of their type.

 @param visitor id<TTBatchRouteVisistor>
 */
- (void)visit:(id<TTBatchRouteVisistor> _Nonnull)visitor;

/**
 Total number of requests sent to server
 */
@property (nonatomic, assign) NSUInteger totalRequests;

/**
 Number of successful requestes returned from server.
 */
@property (nonatomic, assign) NSUInteger totalSuccessfulRequests;

@end
