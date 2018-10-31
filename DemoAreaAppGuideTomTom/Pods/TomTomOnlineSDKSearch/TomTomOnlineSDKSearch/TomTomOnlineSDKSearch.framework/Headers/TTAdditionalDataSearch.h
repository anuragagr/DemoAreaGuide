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
#import "TTAdditionalDataSearchResponse.h"
#import "TTAdditionalDataSearchQuery.h"

@class TTAdditionalDataSearch;

@protocol TTAdditionalDataSearchDelegate <NSObject>
/**
 Method responsible to handle search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param additionalDataSearch Object type TTAdditionalDataSearch.
 @param response Object type TTAdditionalDataSearchResponse.
 */
-(void)additionalDataSearch:(TTAdditionalDataSearch* _Nonnull)additionalDataSearch completedWithResponse:(TTAdditionalDataSearchResponse * _Nonnull)response;
/**
 Method responsible to geometry route search response when search returns error. Within this callback user will obtain AdditionalDataSearchError containing a Throwable fail reason
 
 @param additionalDataSearch Object type TTAdditionalDataSearch.
 @param error Object type TTResponseError.
 */
-(void)additionalDataSearch:(TTAdditionalDataSearch* _Nonnull)additionalDataSearch failedWithError:(TTResponseError* _Nonnull)error;
@end

/**
 *TomTom AdditionalDataSearch API main object. Contains methods to use Tomtom’s online search engine and provides support for both async and sync calls.
 */
@interface TTAdditionalDataSearch : NSObject

/**
 Delegate that informs the subscriber when a search result is available. It contains a TTAdditionalDataSearchResult object.
 */
@property (nonatomic, weak) id <TTAdditionalDataSearchDelegate> _Nullable delegate;

/**
 *AdditionalDataSearch with async callback
 *
 *@param query Object containing the data needed to perform a search.
 */
- (void)additionalDataSearchWithQuery:(TTAdditionalDataSearchQuery* _Nonnull)query;

/**
 *AdditionalDataSearch with async block
 *
 *@param query Object containing the data needed to perform a search.
 *@param completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTAdditionalDataSearchResult object.
 */
- (void)additionalDataSearchWithQuery:(TTAdditionalDataSearchQuery * _Nonnull)query
      completionHandler:(void (^ _Nonnull)(TTAdditionalDataSearchResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
 *Cancels the current search request.
 */
- (void)cancel;

@end
