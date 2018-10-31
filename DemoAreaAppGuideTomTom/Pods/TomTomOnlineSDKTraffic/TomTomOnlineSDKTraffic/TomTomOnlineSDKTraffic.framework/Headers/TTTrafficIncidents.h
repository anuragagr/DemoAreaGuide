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
#import "TTIncidentDetailsQuery.h"
#import "TTIncidentDetailsResponse.h"

@class TTTrafficIncidents;
@protocol TTTrafficIncidentsDelegate <NSObject>

@optional
/**
 Method responsible to handle Traffic Incidents response when search returns results. Within this callback user will obtain Response populated with Results.

 @param trafficIncidents Object type TTTrafficIncidents.
 @param response Object type TTIncidentDetailsResponse.
 */
- (void)incidentDetails:(TTTrafficIncidents* _Nonnull)trafficIncidents completedWithResponse:(TTIncidentDetailsResponse * _Nonnull)response;

/**
 Method responsible to handle Traffic Incidents response when search returns error. Within this callback user will obtain TTResponseError containing a Throwable fail reason

 @param trafficIncidents Object type TTTrafficIncidents.
 @param error Object type TTResponseError.
 */
- (void)incidentDetails:(TTTrafficIncidents* _Nonnull)trafficIncidents failedWithError:(TTResponseError* _Nonnull)error;

@end

/**
 TomTom Traffic Incidents API main object. Contains methods to use Tomtom’s online traffic incidents engine and provides support for both async and sync calls.
 */
@interface TTTrafficIncidents : NSObject

/**
 Delegate that informs the subscriber when a traffic flow result is available. It contains a TTTrafficIncidentsDelegate object.
 */
@property id <TTTrafficIncidentsDelegate> _Nullable delegate;

/**
 IncidentDetailsWithQuery with async callback

 @param query Object containing the data needed to perform a traffic incidetns.
 */
- (void)incidentDetailsWithQuery:(TTIncidentDetailsQuery* _Nonnull)query;

/**
 IncidentDetailsWithQuery with async block

 @param query Object containing the data needed to perform a traffic incidents.
 @param completionHandler CompletionHandler that informs the subscriber when a traffic incidents result is available. It contains a TTIncidentDetailsResponse object.
 */
- (void)incidentDetailsWithQuery:(TTIncidentDetailsQuery* _Nonnull)query
               completionHandler:(void (^ _Nonnull)(TTIncidentDetailsResponse * _Nullable response, TTResponseError * _Nullable error))completionHandler;

/**
 *Cancels the current search request.
 */
- (void)cancel;
@end
