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

@class TTSearchQuery;
@class TTSearch;
@class TTSearchResult;
@class TTSearchResponse;
@class TTResponseError;

@protocol TTSearchDelegate <NSObject>

@optional
/**
 Method responsible to handle search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTSearch.
 @param result Object type NSArray<TTSearchResult>.
 @deprecated This method is deprecated, use completedWithResponse instead.
 */
-(void)search:(TTSearch* _Nonnull)search completedWithResult:(NSArray<TTSearchResult*>* _Nonnull)result DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use completedWithResponse instead.");

/**
 Method responsible to handle search response when search returns response. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTSearch.
 @param response Object type TTSearchResponse.
 */
-(void)search:(TTSearch* _Nonnull)search completedWithResponse:(TTSearchResponse* _Nonnull)response;

/**
 Method responsible to handle search response when search returns error. Within this callback user will obtain Throwable fail reason
 
 @param search Object type TTSearch.
 @param error Object type TTResponseError.
 */
-(void)search:(TTSearch* _Nonnull)search failedWithError:(TTResponseError* _Nonnull)error;
@end

/**
 *TomTom Search API main object. Contains methods to use Tomtom’s online search engine and provides support for both async and sync calls.
 */
@interface TTSearch : NSObject

/**
 *Delegate that informs the subscriber when a search result is available. It contains a TTSearchResponse object.
 */
@property (nonatomic, weak) id<TTSearchDelegate> _Nullable delegate;

/**
 *Search with async callback
 *
 *@param query Object containing the data needed to perform a search.
 *@param delegate Delegate that informs the subscriber when a search result is available. It contains a TTSearchResult object
 * or error if fails.
 *
 */
- (void)searchWithQuery:(TTSearchQuery* _Nonnull)query
      withAsyncDelegate:(id<TTSearchDelegate> _Nonnull)delegate DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use searchWithQuery without passing delegate here instead.");

/**
 *Search with async callback
 *
 *@param query Object containing the data needed to perform a search.
 */
- (void)searchWithQuery:(TTSearchQuery* _Nonnull)query;

/**
 *Search with async block
 *
 *@param query Object containing the data needed to perform a search.
 *@param completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTSearchResult objects or error if fails.
 *@deprecated This method is deprecated, use completionHandle with TTSearchResponse instead.
 */
- (void)searchWithQuery:(TTSearchQuery * _Nonnull)query
      completionHandler:(void (^ _Nonnull)(NSArray<TTSearchResult *> * _Nullable result, TTResponseError * _Nullable error))completionHandler DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use completionHandle with TTSearchResponse instead.");

/**
 *Search with async block
 *
 *@param query Object containing the data needed to perform a search.
 *@param completionHandler CompletionHandler that informs the subscriber when a search response is available. It contains a TTSearchResponse object.
 */
- (void)searchWithQuery:(TTSearchQuery * _Nonnull)query
       completionHandle:(void (^ _Nonnull)(TTSearchResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
 *Cancels the current search request.
 */
- (void)cancel;

@end
