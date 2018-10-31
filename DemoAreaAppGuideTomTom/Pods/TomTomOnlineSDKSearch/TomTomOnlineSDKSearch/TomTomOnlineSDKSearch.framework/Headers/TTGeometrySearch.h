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

@class TTGeometrySearchQuery;
@class TTGeometrySearchResponse;
@class TTResponseError;
@class TTGeometrySearch;

@protocol TTGeometrySearchDelegate <NSObject>

@optional
/**
 Method responsible to handle geometry search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTGeometrySearch.
 @param result Object type TTGeometrySearchResponse.
 @deprecated This method is deprecated, use completedWithResponse instead.
 */
-(void)search:(TTGeometrySearch* _Nonnull)search completedWithResult:(TTGeometrySearchResponse* _Nonnull)result DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use completedWithResponse instead.");

/**
 Method responsible to handle geometry search response when search returns response. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTGeometrySearch.
 @param response Object type TTGeometrySearchResponse.
 */
-(void)search:(TTGeometrySearch* _Nonnull)search completedWithResponse:(TTGeometrySearchResponse* _Nonnull)response;

/**
 Method responsible to geometry route search response when search returns error. Within this callback user will obtain TTResponseError containing a Throwable fail reason
 
 @param search Object type TTGeometrySearch.
 @param error object type TTResponseError.
 */
-(void)search:(TTGeometrySearch* _Nonnull)search failedWithError:(TTResponseError* _Nonnull)error;

@end

/**
 *TomTom Geometry Search API main object. Contains methods to use Tomtom’s online search engine and provides support for both async and sync calls.
 */
@interface TTGeometrySearch : NSObject

/**
 Delegate that informs the subscriber when a search result is available. It contains a TTSearchResult object.
 */
@property (nonatomic, weak) id<TTGeometrySearchDelegate> _Nullable delegate;

/**
 *Search with async callback
 *
 *@param query Object containing the data needed to perform a search.
 */
- (void)searchWithQuery:(TTGeometrySearchQuery* _Nonnull)query;

/**
 *Search with async callback
 *
 *@param query Object containing the data needed to perform a search.
 *@param delegate Delegate that informs the subscriber when a search result is available. It contains a TTSearchResult object.
 *@deprecated This method is deprecated, use searchWithQuery without passing delegate here instead.
 */
- (void)searchWithQuery:(TTGeometrySearchQuery* _Nonnull)query
      withAsyncDelegate:(id<TTGeometrySearchDelegate> _Nonnull)delegate DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use searchWithQuery without passing delegate here instead.");

/**
 *Search with async block
 *
 *@param query Object containing the data needed to perform a search.
 *@param completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTSearchResult object.
 */
- (void)searchWithQuery:(TTGeometrySearchQuery* _Nonnull)query
      completionHandler:(void (^_Nonnull)(TTGeometrySearchResponse* _Nullable response, TTResponseError* _Nullable error))completionHandler;

/**
 *Search with sync result
 *
 *@param query Object containing the data needed to perform a search.
 *@param error Error
 *@return return TTGeometrySearchResponse object.
 */
- (TTGeometrySearchResponse* _Nonnull)searchWithQuery:(TTGeometrySearchQuery*_Nonnull)query
                                                error:( TTResponseError*_Nonnull)error;

/**
 *Cancels the current search request
 */
- (void)cancel;

@end
