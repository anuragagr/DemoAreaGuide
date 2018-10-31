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

@class TTBatchSearch;
@class TTBatchResponse;
@class TTResponseError;
@class TTBatchQuery;

@protocol TTBatchSearchDelegate <NSObject>

@optional

/**
 Method responsible to handle batch search response when batch returns results. Within this callback user will obtain Response that can be visited by corresponding responses.

 @param batch TTBatchSearch
 @param response TTBatchResponse
 */
- (void)batch:(TTBatchSearch* _Nonnull)batch completedWithResponse:(TTBatchResponse* _Nonnull)response;

/**
 Method responsible to handle batch search response when search returns error. Within this callback user will obtain Throwable fail reason

 @param batch TTBatchSearch
 @param error TTResponseError
 */
- (void)batch:(TTBatchSearch* _Nonnull)batch failedWithError:(TTResponseError* _Nonnull)error;

@end

/**
 TomTom Batch Search API main object. Contains methods to use Tomtom’s batch search engine and provides support for both async calls.
 */
@interface TTBatchSearch : NSObject

/**
 Perform batch search with query
 
 @param query Object containing the data needed to perform batch search.
 */
- (void)batchSearchWithQuery:(TTBatchQuery* _Nonnull)query;

/**
 Perform batch search with query with block

 @param query Object containing the data needed to perform batch search.
 @param completionHandler CompletionHandler that informs the subscriber when a search response is available.
 */
- (void)batchSearchWithQuery:(TTBatchQuery* _Nonnull)query completionHandler:(void (^_Nonnull)(TTBatchResponse* _Nullable response, TTResponseError* _Nullable error))completionHandler;
- (void)cancel;

/**
 Delegate that informs the subscriber when batch search result is available.
 */
@property (nonatomic, weak) id<TTBatchSearchDelegate> _Nullable delegate;

@end
