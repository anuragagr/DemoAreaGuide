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
#import "TTFlowSegmentDataQuery.h"
#import "TTFlowSegmentDataResponse.h"


@class TTTrafficFlow;

@protocol TrafficFlowDelegate <NSObject>

@optional
/**
 Method responsible to handle Flow Segment Data response when search returns results. Within this callback user will obtain Response populated with Results.

 @param flowSegmentData Object type TTTrafficFlow.
 @param response Object type TTFlowSegmentDataResponse.
 */
- (void)flowSegmentData:(TTTrafficFlow* _Nonnull)flowSegmentData completedWithResponse:(TTFlowSegmentDataResponse * _Nonnull)response;


/**
  Method responsible to handle Flow Segment Data response when search returns error. Within this callback user will obtain TTResponseError containing a Throwable fail reason

 @param flowSegmentData Object type TTTrafficFlow.
 @param error Object type TTResponseError.
 */
- (void)flowSegmentData:(TTTrafficFlow* _Nonnull)flowSegmentData failedWithError:(TTResponseError* _Nonnull)error;
@end


/**
 TomTom Traffic Flow API main object. Contains methods to use Tomtom’s online traffic flow engine and provides support for both async and sync calls.
 */
@interface TTTrafficFlow : NSObject

/**
  Delegate that informs the subscriber when a traffic flow result is available. It contains a TrafficFlowDelegate object.
 */
@property id <TrafficFlowDelegate> _Nullable delegate;


/**
 FlowSegmentDataWithQuery with async callback

 @param query Object containing the data needed to perform a traffic flow.
 */
- (void)flowSegmentDataWithQuery:(TTFlowSegmentDataQuery* _Nonnull)query;

/**
 FlowSegmentDataWithQuery with async block

 @param query Object containing the data needed to perform a traffic flow.
 @param completionHandler CompletionHandler that informs the subscriber when a traffic flow result is available. It contains a TTFlowSegmentDataResponse object.
 */
- (void)flowSegmentDataWithQuery:(TTFlowSegmentDataQuery* _Nonnull)query
                    completionHandler:(void (^ _Nonnull)(TTFlowSegmentDataResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
  *Cancels the current search request.
 */
- (void)cancel;

@end
