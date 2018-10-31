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
#import "TTSearchResponse.h"
#import "TTReverseGeocoderResponse.h"
#import "TTGeometrySearchResponse.h"


@protocol TTBatchVisistor <NSObject>

@optional

/**
 Called when batch returns TTSearchResponse

 @param response TTSearchResponse
 */
- (void)visitSearch:(TTSearchResponse* _Nonnull)response;

/**
 Called when batch returns TTGeometrySearchResponse
 
 @param response TTGeometrySearchResponse
 */
- (void)visitGeometrySearch:(TTGeometrySearchResponse* _Nonnull)response;

/**
 Called when batch returns TTReverseGeocoderResponse
 
 @param response TTReverseGeocoderResponse
 */
- (void)visitReverseGeocoderSearch:(TTReverseGeocoderResponse* _Nonnull)response;

@end

/**
 Visitable collection of batch search responses.
 */
@interface TTBatchResponse : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Method allows to visit results returned from batch search depends of their type.

 @param visitor id<TTBatchVisistor>
 */
- (void)visit:(id<TTBatchVisistor> _Nonnull)visitor;

/**
 Total number of requests sent to server
 */
@property (nonatomic, assign) NSUInteger totalRequests;

/**
 Number of successful requestes returned from server.
 */
@property (nonatomic, assign) NSUInteger totalSuccessfulRequests;

@end
