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
#import "TTTrafficUtils.h"


/**
 TTIncidentDetailsQuery represent request object for Incident Details.
 */
@interface TTIncidentDetailsQuery : NSObject

@end

@interface TTIncidentDetailsQueryBuilder : NSObject

- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 Builder of TTIncidentDetailsQueryBuilder object

 @param style The style that will be used to render the traffic tile in the Maps API. This will have an effect on the coordinates of traffic incidents in the reply.
 @param boudingBox The corners of the area to report on, expressed in the projection specified. These are two latitude-longitude pairs describing corners of the bounding box. First pair for lower left corner and second for upper right. All values should be separated by commas.
 @param zoom Zoom level. This will affect traffic incident coordinates and determine which incidents are included in clusters rather than reported separately.
 @param trafficModelID Number referencing traffic model. This can be obtained from the Viewport API. It is updated every minute, and is valid for two minutes before it times out. If the wrong Traffic Model ID is specified, the correct one will be returned by the interface.
 A value of -1 will always invoke the most recent traffic model
 @return TTIncidentDetailsQueryBuilder object
 */
+(TTIncidentDetailsQueryBuilder* _Nonnull)createWithStyle:(TTTrafficIncidentStyleType)style withBoundingBox:(TTLatLngBounds)boudingBox withZoom:(NSUInteger)zoom withTrafficModelID:(NSString* _Nonnull)trafficModelID;

/**
 Part of builder TTIncidentDetailsQueryBuilder object.

 @param language ISO 639-1 code for the output language. Affects the <c> (cause) and <d> (description) fields in the response.
 Supported languages are ar, ca, cs, da, de, el, en, en-GB, en-US, es, et, fi, fr, he, hu, id, in*, it, iw*, lt, lv, nb, nl, no, pl, pt, ro, ru, sk, sv, th, tr, zh. (* - deprecated) more details: https://developer.tomtom.com/online-traffic/online-traffic-documentation-online-traffic-incidents/traffic-incident-details
 When invalid language code is provided response is returned in English. When incident cause or description does not have translation, English description is returned.
 
 @return TTIncidentDetailsQueryBuilder object
 */
-(TTIncidentDetailsQueryBuilder* _Nonnull)withLanguage:(NSString *)language;

/**
 Part of builder TTIncidentDetailsQueryBuilder object.

 @param geometries The type of vector geometry added to incidents (returned in the <v> element of the response) original places incidents precisely on the road shifted moves the incident slightly (depending on zoom level) to indicate specific road lanes If this parameter is not used, the response will not contain a <v> element.
 
 @return TTIncidentDetailsQueryBuilder object
 */
-(TTIncidentDetailsQueryBuilder* _Nonnull)withGeometries:(TTTrafficGeometriesType)geometries;

/**
 Part of builder TTIncidentDetailsQueryBuilder object.

 @param expandCluster List all traffic incidents in a cluster separately.
 @return TTIncidentDetailsQueryBuilder object
 */
-(TTIncidentDetailsQueryBuilder* _Nonnull)withExpandCluster:(Boolean)expandCluster;

/**
 Part of builder TTIncidentDetailsQueryBuilder object.

 @param originalPosition Return the original position of the incident as well as the one shifted to the beginning of the traffic tube.
 @return TTIncidentDetailsQueryBuilder object
 */
-(TTIncidentDetailsQueryBuilder* _Nonnull)withOriginalPosition:(Boolean)originalPosition;
/**
 Build method.
 
 @return TTIncidentDetailsQuery object.
 */
-(TTIncidentDetailsQuery* _Nonnull)build;

@end

