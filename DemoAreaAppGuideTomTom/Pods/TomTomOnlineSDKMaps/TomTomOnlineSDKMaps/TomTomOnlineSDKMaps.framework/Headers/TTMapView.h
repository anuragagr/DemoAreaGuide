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

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>
#import "TTAnnotationManager.h"
#import "TTRouteManager.h"
#import "TTCameraPosition.h"
#import "TTTrafficTileStyle.h"
#import "TTRasterTileType.h"
#import "TTVectorTileType.h"

typedef void (^TTMapReadyCompletionBlock)(void);

@class TTMapView;


/**
 TTMapTilesType
 Enumeration Cases

 - TTMapTilesVector: TTMapTilesVector - Vector tiles.
 - TTMapTilesRaster: TTMapTilesRaster - Raster tiles.
 */
typedef NS_ENUM (NSInteger, TTMapTilesType) {
    TTMapTilesVector,
    TTMapTilesRaster
};

/**
 TTMapLayersType
 Enumeration Cases

 - TTMapLayersNone: TTMapLayersNone - No layers.
 - TTMapLayersHybrid: TTMapLayersHybrid - Hybrid layer (layers and road).
 */
typedef NS_ENUM(NSInteger, TTMapLayersType){
    TTMapLayersNone,
    TTMapLayersHybrid
};

/**
 TTMapTrafficType
 Enumeration Cases

  @deprecated This ns options is deprecated. Use the new method-based API instead. 'trafficFlowOn' and 'trafficIncidentsOn'
 
 - TTMapTrafficNone: TTMapTrafficNone - No traffic.
 - TTMapTrafficFlow: TTMapTrafficFlow - Only traffic flow.
 - TTMapTrafficIncidents: TTMapTrafficIncidents - Only traffic incidents.
 */
typedef DEPRECATED_MSG_ATTRIBUTE("This ns options is deprecated. Use the new method-based API instead. 'trafficFlowOn' and 'trafficIncidentsOn'") NS_ENUM(NSInteger, TTMapTrafficType){
    TTMapTrafficNone,
    TTMapTrafficFlow,
    TTMapTrafficIncidents
};

typedef NS_ENUM(NSInteger, TTTrafficIncidentsStyle) {
    TTTrafficIncidentsStyleRaster
};

/**
  Enumerate of TTMapTrafficTileType elements

 - TTMapTrafficTileTypeVector: vector traffic flow
 - TTMapTrafficTileTypeRaster: raster traffic flow
 */
typedef NS_ENUM(NSInteger, TTMapTrafficTileType) {
    TTMapTrafficTileTypeVector,
    TTMapTrafficTileTypeRaster
};

/**
 Enumerate of TTGeoView elements
 
 - TTGeoViewNone: Disabling the geopolitical view
 - TTGeoViewIL: Geopolitical view for Israel avable only on vector Tiles
 - TTGeoViewIN: Geopolitical view for India avable on raster and vector
 */
typedef NS_ENUM(NSInteger, TTGeoView) {
    TTGeoViewNone,
    TTGeoViewIL,
    TTGeoViewIN
};

/**
 Enumerate of TTOptionGesturesDisable

 - TTOptionGesturesDisableNone:
 - TTOptionGesturesDisableZoom: Disable zoom gestures on map
 - TTOptionGesturesDisableScroll: Disable scroll gestures on map
 - TTOptionGesturesDisablePinch: Disable pinch gestures on map
 - TTOptionGesturesDisableRotate: Disable rotate gestures on map
 */
typedef NS_OPTIONS(NSInteger, TTOptionGesturesDisable) {
    TTOptionGesturesDisableNone = 0,
    TTOptionGesturesDisableZoom = 1 << 0,
    TTOptionGesturesDisableScroll = 1 << 1,
    TTOptionGesturesDisableRotate = 1 << 2
};

/**
 * The `TTMapViewDelegate` protocol defines a set of optional methods that you can use to receive map-related update messages.
 * Because many map operations require the `TTMapView` class to load data asynchronously, the map view calls these methods to notify your application when specific operations complete.
 */
@protocol TTMapViewDelegate <NSObject>

@optional

/**
 Tells the delgate that the specified map view is ready to be used.

 @param mapView The map view.
 */
- (void)onMapReady:(TTMapView * _Nonnull)mapView;

/**
 Tells the delegate that the specified map view with pan gesture recognizer.

 @param mapView The map view.
 @param coordinate for panning.
 */
- (void)mapView:(TTMapView * _Nonnull)mapView didPanning:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that the specified map view with double tap gesture recognizer.

 @param mapView The map view.
 @param coordinate for a double tap.
 */
- (void)mapView:(TTMapView * _Nonnull)mapView didDoubleTap:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that the specified map view with single tap gesture recognizer.

 @param mapView The map view.
 @param coordinate for a single tap.
 */
- (void)mapView:(TTMapView * _Nonnull)mapView didSingleTap:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that the specified map view with long press gesture recognizer.

 @param mapView The map view.
 @param coordinate for a long press.
 */
- (void)mapView:(TTMapView * _Nonnull)mapView didLongPress:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that specified map view with rotate gesture recognizer.

 @param mapView The map view.
 @param angle in radians.
 */
- (void)mapView:(TTMapView * _Nonnull)mapView didRotate:(CGFloat)angle;

@end

/**
 * An `TTMapView` object provides an embeddable map interface.
 * You use this class as-is to display map information and to manipulate the map contents from your application.
 * You can center the map on a given coordinate, specify the size of the area you want to display and annotate the map with custom information.
 */
@interface TTMapView : UIView


/**
 Variable allow display a map with a custom style
 */
@property (nonatomic, assign, getter=isCustomStyle) BOOL customStyle;

/**
 * The `TTMapViewDelegate` protocol defines a set of optional methods that you can use to receive map-related update messages.
 */
@property (weak, nonatomic) _Nullable id<TTMapViewDelegate> delegate;

/**
 * TTAnnotationManager class to manage interactions with annotations.
 */
@property (nonatomic, strong, readonly) id <TTAnnotationManager> _Nonnull annotationManager;

/**
 * TTRouteManager class to manage interactions with drawing routes on map.
 */
@property (nonatomic, strong, readonly) id<TTRouteManager> _Nonnull routeManager;

/**
 Initializes and returns a TTMapView with the specified frame rectangle with default style.

 @param frame The frame rectangle for the view, measured in points.
 @return TTMapView
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame;

/**
 Initializes and returns a TTMapView with the specified frame rectangle.

 @param frame The frame rectangle for the view, measured in points.
 @param customStyleOn customStyleOn
 @return TTMapView
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame withCustomStyle:(BOOL)customStyleOn;

/**
 Initializes and returns an TTMapView initialized from data in a given unarchiver.

 @param aDecoder An unarchiver object.
 @return TTMapView
 */
- (instancetype _Nonnull)initWithCoder:(NSCoder * _Nonnull)aDecoder;


/**
 Completion block called when the map is ready to be used.

 @param completionBlock completionBlock
 */
- (void)onMapReadyCompletion:(TTMapReadyCompletionBlock _Nonnull)completionBlock;

/**
 * Returns current rotation of the map in degrees range from 0 to 360
 *
 * Allows also to set rotation degrees is in range 0 - 360 where 0 == 360 which is Nort up
 * Bigger values than 360 are also allowed. For 540 it will do 540 % 360 = 180
 */
@property (nonatomic, assign) double bearing;

/**
 * Determines if current location indicator/radius should be displayed on the map.
 * It works only if users allow application to use GPS fix and NSLocationWhenInUseUsageDescription and
 * location permissions are gained by calling requestLocationAuthorization method.
 */
@property (nonatomic, assign, getter=isShowsUserLocation) BOOL showsUserLocation;

/**
 * Returns current user coordinate location.
 * If the current location is not available, latitude and longitude returned by the method will be equal to 0.
 */
@property (nonatomic, readonly, getter=userLocation) CLLocationCoordinate2D userLocation;

/**
 Determines map view insets for functions like show route overview, center on, camera concept.
 A default set to 0.
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 Disable gestures on map using gesturesMask from NS_OPTIONS
 */
@property (nonatomic, assign,setter=setGestureMask:) TTOptionGesturesDisable disableGesturesMask;

/**
 Online Traffic tiles types are represented in enum. It is possible to enable morethan one option at the same time.
  @deprecated This property is deprecated. Use the new method-based API instead. 'trafficFlowOn' and 'trafficIncidentsOn'
 */
@property (nonatomic, assign) TTMapTrafficType trafficType DEPRECATED_MSG_ATTRIBUTE("This property is deprecated. Use the new method-based API instead. 'trafficFlowOn' and 'trafficIncidentsOn'");

/**
  Online Traffic tiles types are represented in TTTileType.
 */
@property (nonatomic, strong) TTTrafficTileStyle* _Nonnull trafficTileStyle;

/**
 Display traffic flow on the road.
 */
@property (nonatomic, assign) BOOL trafficFlowOn;
/**
 Display traffic incidents on the road.
 */
@property (nonatomic, assign) BOOL trafficIncidentsOn;

/**
 Set style of traffic incidents
 */
@property (nonatomic, assign) TTTrafficIncidentsStyle trafficIncidentsStyle;

/**
 Traffic flow tiles are available in two formats: vector (.pbf) and raster (.png). Vector tiles provide apossibility  for  visual  customization  and  better  visual  experience.  Therefore,  we  recommend  usingthe vector tiles for map and traffic display. Raster tiles are especially suitable for low performancedevices.
 
 Vector traffic flow tiles are used by default for traffic flow in Maps SDK. Vector traffic flow tiles areavailable  from  map  zoom  levels:  11  to  20.  Raster  traffic  flow  tiles  are  available  from  map  zoomlevels: 0 to 18. You can switch to raster traffic flow tiles by using the method:
 
 @deprecated This method is deprecated. Use the new method-based API instead 'trafficTileStyle'
 */
@property (nonatomic, assign) TTMapTrafficTileType trafficTile  DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead 'trafficTileStyle'");

/**
 * Center map on given coordinates
 @param coordinate location Coordinate to center map on.
 */
- (void)centerOnCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * Center map on given latitude and longitude.
 * Latitude and longitude is set in degrees minutes seconds format.
 @param latitude Latitude to center map on.
 @param longitude Longitude to center map on.
 */
- (void)centerOnLatitude:(double)latitude withLongitude:(double)longitude;

/**
 * Center map on given coordinates and with given zoom level.
 * When zoom level is out of range, the minimum zoom level will be set.
 @param coordinate Coordinate to center map on.
 @param zoom Map zoom level in range 0 - 18 where 0 is whole world and 18 highest zoom level.
 */
- (void)centerOnCoordinate:(CLLocationCoordinate2D)coordinate withZoom:(double)zoom;

/**
 * Center map on given latitude and longitude with a given zoom level.
 * When zoom level is out of range, the minimum zoom level will be set.
 * Latitude and longitude are set in degrees minutes seconds format.
 @param latitude Latitude to center map on.
 @param longitude Longitude to center map on.
 @param zoom Map zoom level in range 0 - 18 where 0 is whole world and 18 highest zoom level.
 */
- (void)centerOnLatitude:(double)latitude withLongitude:(double)longitude withZoom:(double)zoom;

/**
 * Coordinates of map center
 @return map center coordinate
 */
- (CLLocationCoordinate2D)centerCoordinate;

/**
 * The zoom in and out of the map.
 * Zoom levels are in range <18,0)
 * Where 0 is whole world.
 * 18 is the highest zoom level.
 @return zoom Map Level.
 */
- (double)zoom;

/**
 * Centers map to have all provided annotations in bounding box
 @param annotations annotations
 */
- (void)zoomToAnnotations:(NSArray<TTAnnotation *> * _Nonnull)annotations;

- (void)zoomToAllAnnotations;

/**
 * Centers map to have all provided coordiantesData in bounding box
 @param coordinatesData coordinatesData
 */
- (void)zoomToCoordinatesData:(id<TTCoordinatesData> _Nonnull)coordinatesData;

/**
 * Centers map to have all provided coordiantesData in bounding box
 @param coordinatesData coordinatesData
 */
- (void)zoomToCoordinatesDataCollection:(NSArray<id<TTCoordinatesData>> *_Nonnull)coordinatesData;

/**
 * Set 2D mode or 3D for a map.
 @param perspective true if 3D mode, false otherwise.
 */
- (void)setPerspective3D:(BOOL)perspective;

/**
 * Is perspective 3D active.
 @return BOOL true if a 3D mode is active, false otherwise.
 */
- (BOOL)isPerspective3D;

/**
 Rotate map to given degrees with given rotation center.
 Degrees is in range 0 - 360 where 0 == 360 which is Nort up
 Bigger values than 360 are also allowed. For 540 it will do 540 % 360 = 180

 @param degrees determines how to rotate map
 @param coordinate that takes as center of rotation
 */
- (void)setBearing:(double)degrees coordinate:(CLLocationCoordinate2D)coordinate;

/**
 The method for style to be used to render tiles.
 @param tiles TTMapTilesType visible for None, Vector or Raster type.
 */
- (void)setTilesType:(TTMapTilesType)tiles;

/**
 The method for style to be used to render layers.
 @param layers TTMapLayersType visible for None or Hybrid.
 */
- (void)setLayersType:(TTMapLayersType)layers;

/**
  The method for style to be used to render traffic tiles
 @param traffic TTMapTrafficType visible for None, Traffic or Incidents type.
 @deprecated This method is deprecated. Use the new method-based API instead. 'trafficFlowOn' and 'trafficIncidentsOn'
 */
- (void)setTrafficType:(TTMapTrafficType)traffic DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. 'trafficFlowOn' and 'trafficIncidentsOn'");

/**
 Get Current screen bounds
 @return TTLatLngBounds
 */
- (TTLatLngBounds)currentBounds;

/**
 The method for setting camera position
 @param cameraPosition object TTCameraPosition
 */
-(void)setCameraPosition:(TTCameraPosition* _Nonnull)cameraPosition;

/**
 Get Camera Position object.
 @return TTCameraPostion object present current state of camera.
 */
-(TTCameraPosition * _Nonnull)cameraPosition;

/**
 The method for setting geopolitical map view
 
 @param geoView enumerate of TTGeoView elements
 */
- (void)setGeopoliticalView:(TTGeoView)geoView;

/**
 Changes labels language displayed on map to given language.

 @param language enumerate of TTLanguage elements
 */
- (void)setMapLanguage:(TTLanguage) language;

/**
 Changes labels language displayed on map to unified.
 Labels in given contry will be displayed using local language.
 */
- (void)setUnifiedMapLanguage;


/**
 Path Style of the style currently displayed in the map.

 @param pathStyle If you set pathStyle to nil, the receiver will use the default style and this property will automatically be set to that path Style and load.


 */
- (void)setStylePath:(NSString* _Nullable)pathStyle;

/**
 Moving the map relative to the x, y axis

 @param offsetX Offset relative to the x axis
 @param offsetY Offset relative to the y axis
 */
-(void)movebyOffsetX:(double)offsetX offsetY:(double)offsetY;


/**
Obtains the minimal zoom level which can be set for the map.
 */
@property (nonatomic, assign)  double  minZoom;

/**
Obtains the maximum zoom level which can be set for the map.
 */
@property (nonatomic, assign)  double  maxZoom;

/**
 Obtains the maximum bounds which can be set for the map view port.
 */
@property (nonatomic, assign)  TTLatLngBounds maxBounds;

/**
 Obtains the default minimum and maximum zoom level which can be set for the map.
 */
- (void)setDefaultLimitZoom;

/**
 Obtains the default bounds which can be set for the map view port.
 */
- (void)setDefaultMaxBounds;

@end
