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
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>

@class TTReverseGeocoderQuery;
@class TTReverseGeocoder;
@class TTReverseGeocoderResult;
@class TTReverseGeocoderResponse;
@class TTResponseError;

@protocol TTReverseGeocoderDelegate <NSObject>

@optional
/**
 Method responsible to handle reverse geocoder search response when search returns results. Within this callback user will obtain Response populated with Result.
 
 @param reverseGeocoder Object type TTReverseGeocoder.
 @param result Object type TTReverseGeocoderResponse.
 @deprecated This method is deprecated, use completedWithResponse instead.
 */
-(void)reverseGeocoder:(TTReverseGeocoder* _Nonnull)reverseGeocoder completedWithResult:(TTReverseGeocoderResponse* _Nonnull)result DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use completedWithResponse instead.");

/**
 Method responsible to handle reverse geocoder search response when search returns results. Within this callback user will obtain Response populated with Result.
 
 @param reverseGeocoder Object type TTReverseGeocoder.
 @param response Object type TTReverseGeocoderResponse.
 */
-(void)reverseGeocoder:(TTReverseGeocoder* _Nonnull)reverseGeocoder completedWithResponse:(TTReverseGeocoderResponse* _Nonnull)response;

/**
 Method responsible to handle reverse geocoder search response when search returns error. Within this callback user will obtain Throwable fail reason
 
 @param reverseGeocoder Object type TTReverseGeocoder.
 @param error Object type TTResponseError.
 */
-(void)reverseGeocoder:(TTReverseGeocoder* _Nonnull)reverseGeocoder failedWithError:(TTResponseError* _Nonnull)error;
@end


/**
 *TomTom Reverse Geocoder API main object. Contains methods to use Tomtom’s online search engine and provides support for both async and sync calls.
 */
@interface TTReverseGeocoder : NSObject

/**
 *Delegate that informs the subscriber when a search result is available. It contains a TTReverseGeocoderResponse object.
 */
@property (nonatomic, weak) id<TTReverseGeocoderDelegate> _Nullable delegate;

/**
 *Reverse geocoder with async callback
 *
 *@param query Object containing the data needed to perform a search.
 *@param delegate Delegate that informs the subscriber when a search result is available. It contains a TTReverseGeocoderResult object.
 *@deprecated This method is deprecated, use reverseGeocoderWithQuery without passing delegate here instead.
 */
- (void)reverseGeocoderWithQuery:(TTReverseGeocoderQuery* _Nonnull)query
      withAsyncDelegate:(id<TTReverseGeocoderDelegate> _Nonnull)delegate DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use reverseGeocoderWithQuery without passing delegate here instead.");

/**
 *Reverse geocoder with async callback
 *
 *@param query Object containing the data needed to perform a search.
 */
- (void)reverseGeocoderWithQuery:(TTReverseGeocoderQuery* _Nonnull)query;

/**
 *Reverse geocoder with async block
 *
 *@param query The object which contains data necessary to execute search action
 *@param completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTReverseGeocoderResult object or error if fails.
 @deprecated This method is deprecated, use completionHandle with TTReverseGeocoderResponse instead.
 */
- (void)reverseGeocoderWithQuery:(TTReverseGeocoderQuery * _Nonnull)query
               completionHandler:(void (^_Nonnull)(TTReverseGeocoderResult * _Nullable result, TTResponseError * _Nullable error))completionHandler DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use completionHandle with TTReverseGeocoderResponse instead.");

/**
 *Reverse geocoder with async block
 *
 *@param query The object which contains data necessary to execute search action
 *@param completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTReverseGeocoderResponse object or error if fails.
 */
- (void)reverseGeocoderWithQuery:(TTReverseGeocoderQuery * _Nonnull)query
                completionHandle:(void (^_Nonnull)(TTReverseGeocoderResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
 *Reverse geocoder with sync result
 *
 *@param query Object containing the data needed to perform a search.
 *@param error TTResponseError
 *@return return TTReverseGeocoderResult object.
 */
- (TTReverseGeocoderResult * _Nullable)reverseGeocoderWithQuery:(TTReverseGeocoderQuery * _Nonnull)query
                                                error:(TTResponseError * _Nullable)error;

/**
 *Cancels the current request
 */
- (void)cancel;

@end
