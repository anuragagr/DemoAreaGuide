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
#import "TTAlongRouteSearchResponse.h"
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>

@class TTAlongRouteSearchQuery;
@class TTAlongRouteSearch;
@class TTAlongRouteSearchResult;
@class TTResponseError;

@protocol TTAlongRouteSearchDelegate <NSObject>

@optional
/**
 Method responsible to handle along route search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTAlongRouteSearch.
 @param response Object type TTAlongRouteSearchResponse.
 @deprecated This method is deprecated, use completedWithResponse instead.
 */
-(void)search:(TTAlongRouteSearch* _Nonnull)search completedWithResult:(TTAlongRouteSearchResponse* _Nonnull)response DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use completedWithResponse instead.");

/**
 Method responsible to handle along route search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTAlongRouteSearch.
 @param response Object type TTAlongRouteSearchResponse.
 */
-(void)search:(TTAlongRouteSearch* _Nonnull)search completedWithResponse:(TTAlongRouteSearchResponse* _Nonnull)response;

/**
 Method responsible to handle along route search response when search returns error. Within this callback user will obtain Throwable fail reason
 
 @param search object type TTAlongRouteSearch.
 @param error object type TTResponseError.
 */
-(void)search:(TTAlongRouteSearch* _Nonnull)search failedWithError:(TTResponseError* _Nonnull)error;

@end

/**
 Performs along route search action based on provided query object and returns the result with usage of callback implementation.
 */
@interface TTAlongRouteSearch : NSObject

/**
 Delegate that informs the subscriber when a search result is available. It contains a TTAlongRouteSearch object.
 */
@property (nonatomic, weak) id<TTAlongRouteSearchDelegate> _Nullable delegate;

/**
 Performs along route search action based on provided query object and returns the result with usage of dlegate callback implementation.
 
 @param query The object which contains data necessary to execute search action
 @param delegate Delegate that informs the subscriber when a search result is available. It contains a TTAlongRouteSearch object.
 @deprecated This method is deprecated, use searchWithQuery without passing delegate here instead.
 */
- (void)searchWithQuery:(TTAlongRouteSearchQuery* _Nonnull)query
      withAsyncDelegate:(id<TTAlongRouteSearchDelegate> _Nonnull)delegate DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use searchWithQuery without passing delegate here instead.");

/**
 Performs along route search action based on provided query object and returns the result with usage of dlegate callback implementation.
 
 @param query The object which contains data necessary to execute search action
 */
- (void)searchWithQuery:(TTAlongRouteSearchQuery* _Nonnull)query;

/**
 Performs along route search action based on provided query object and returns the result with usage of completion handler callback implementation.
 
 @param query The object which contains data necessary to execute search action
 @param completionHandler completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTAlongRouteSearchResponse object or error if fails.
 */
- (void)searchWithQuery:(TTAlongRouteSearchQuery * _Nonnull)query
      completionHandler:(void (^_Nonnull)(TTAlongRouteSearchResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
 *Search with sync result
 *
 *@param query Object containing the data needed to perform a search.
 *@param error TTResponseError
 *@return return TTAlongRouteSearchResponse object.
 */
- (TTAlongRouteSearchResponse * _Nonnull)searchWithQuery:(TTAlongRouteSearchQuery * _Nonnull)query
                                                   error:(TTResponseError * _Nonnull)error;

/**
Cancels the current along route search request.
 */
- (void)cancel;

@end
