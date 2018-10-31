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
#import "TTAnnotation.h"
#import "TTCalloutView.h"
#import "TTOverlay.h"

@protocol TTAnnotationManager;
@class TTPolyline;
@class TTPolygon;
@class TTCircle;
/**
 TTAnnotationDelegate uses methods to annotation and overlay views to manage interactions with those views.
 */
@protocol TTAnnotationDelegate <NSObject>

@optional

/**
 Called when one of annotation on the map is selected

 @param manager TTAnnotationManager
 @param annotation TTAnnotation
 */
- (void)annotationManager:(id<TTAnnotationManager> _Nonnull)manager annotationSelected:(TTAnnotation * _Nonnull)annotation;

/**
 Called when selected annotation was deselected by selecting another
 or by deselecting all

 @param manager TTAnnotationManager
 @param annotation annotation that was deselected
 */
- (void)annotationManager:(id<TTAnnotationManager> _Nonnull)manager annotationDeselected:(TTAnnotation * _Nonnull)annotation;

/**
 Called when touch up event occurs on polyline

 @param manager TTAnnotationManager
 @param polyline polyline that was clicked
 */
- (void)annotationManager:(id<TTAnnotationManager> _Nonnull)manager touchUpPolyline:(TTPolyline *_Nonnull)polyline;

/**
 Called when touch up event occurs on polygon

 @param manager TTAnnotationManager
 @param polygon polygon that was clicked
 */
- (void)annotationManager:(id<TTAnnotationManager> _Nonnull)manager touchUpPolygon:(TTPolygon *_Nonnull)polygon;

/**
 Called when touch up event occurs on circle

 @param manager TTAnnotationManager
 @param circle circle that was clicked
 */
- (void)annotationManager:(id<TTAnnotationManager> _Nonnull)manager touchUpCircle:(TTCircle *_Nonnull)circle;

/**
 Called when one of annotation on the map becomes selected and callout is needed to display. By default map displays callout with coordinate.

 @param manager TTAnnotationManager
 @param selectedAnnotation selectedAnnotation that requires callout
 @return UIView<TTCalloutView> *
 */
- (UIView<TTCalloutView> *_Nonnull)annotationManager:(id<TTAnnotationManager> _Nonnull)manager viewForSelectedAnnotation:(TTAnnotation *_Nonnull)selectedAnnotation;

/**
 Called when the dragging state of an annotation changes.

 @param manager TTAnnotationManager
 @param annotation the annotation being dragged
 @param state current drag state for TTAnnotation.
 */
- (void)annotationManager:(id<TTAnnotationManager> _Nonnull)manager draggingAnnotation:(TTAnnotation *_Nonnull)annotation stateDrag:(TTAnnotationDragState)state;

#pragma mark - TTAnnotationDelegate (Deprecated)

/**
 Called when one of annotation on the map is selected

 @deprecated This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager annotationSelected:(TTAnnotation * _Nonnull)annotation'
 @param annotation TTAnnotation
 */
- (void)annotationSelected:(TTAnnotation * _Nonnull)annotation DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. '(void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager annotationSelected:(TTAnnotation * _Nonnull)annotation'");

/**
 Called when selected annotation was deselected by selecting another
 or by deselecting all

 @deprecated This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager annotationDeselected:(TTAnnotation * _Nonnull)annotation'
 @param annotation annotation that was deselected
 */
- (void)annotationDeselected:(TTAnnotation * _Nonnull)annotation DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager annotationDeselected:(TTAnnotation * _Nonnull)annotation'");

/**
 Called when touch up event occurs on polyline

 @deprecated This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager touchUpPolyline:(TTPolyline *_Nonnull)polyline'
 @param polyline polyline that was clicked
 */
- (void)touchUpPolyline:(TTPolyline *_Nonnull)polyline DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. '(- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager touchUpPolyline:(TTPolyline *_Nonnull)polyline'");

/**
 Called when touch up event occurs on polygon

 @deprecated This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager touchUpPolygon:(TTPolygon *_Nonnull)polygon'
 @param polygon polygon that was clicked
 */
- (void)touchUpPolygon:(TTPolygon *_Nonnull)polygon DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager touchUpPolygon:(TTPolygon *_Nonnull)polygon'");

/**
 Called when touch up event occurs on circle

 @deprecated This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager touchUpCircle:(TTCircle *_Nonnull)circle'
 @param circle circle that was clicked
 */
- (void)touchUpCircle:(TTCircle *_Nonnull)circle DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. '- (void)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager touchUpCircle:(TTCircle *_Nonnull)circle'");

/**
 Called when one of annotation on the map becomes selected and callout is needed to display. By default map displays callout with coordinate.

 @deprecated This method is deprecated. Use the new method-based API instead. '- (UIView<TTCalloutView> *_Nonnull)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager viewForSelectedAnnotation:(TTAnnotation *_Nonnull)selectedAnnotation'

 @param selectedAnnotation selectedAnnotation that requires callout
 @return UIView<TTCalloutView> *
 */
- (UIView<TTCalloutView> *_Nonnull)viewForSelectedAnnotation:(TTAnnotation *_Nonnull)selectedAnnotation DEPRECATED_MSG_ATTRIBUTE("This method is deprecated. Use the new method-based API instead. '- (UIView<TTCalloutView> *_Nonnull)annotationManager:(TTAnnotationManager * _Nonnull)annotationManager viewForSelectedAnnotation:(TTAnnotation *_Nonnull)selectedAnnotation'");

@end

/**
 TTAnnotationManager class to manage interactions with annotations.
 */
@protocol TTAnnotationManager <NSObject>

/**
 Register delegate to receive annotations releated callbacks.
 */
@property (nonatomic, weak) id <TTAnnotationDelegate> _Nullable delegate;

/**
 Contains array of all annotations that are attached to map.
 */
@property (nonatomic, strong, readonly) NSArray<TTAnnotation *> *_Nonnull annotations;

/**
 Contains array of all overlays that are attached to map.
 */
@property (nonatomic, strong, readonly) NSArray<TTOverlay *> * _Nonnull overlays;

#pragma mark - Clustering


/**
 * Turn on / off markers clustering.
 */
@property (nonatomic, assign) BOOL clustering;

/**
 * Turn on / off markers clustering and provide custom parameters to customize the algorithm.

 @param custeringEnabled custeringEnabled
 @param radius radius
 @param maxZoom maxZoom
 */
- (void)setClustering:(BOOL)custeringEnabled withRadius:(int)radius with:(int)maxZoom;

/**
 Display annotation on the map. If an annotation is already attached to map nothing happens. If you want to have two same annotations in one place you need to create a copy of given annotation.

 @param annotation TTAnnotation
 */
- (void)addAnnotation:(TTAnnotation * _Nonnull)annotation;

/**
 Remove given annotation from a map and set its ID to MARKER_ID_UNDEFINED.
 If an annotation is not attached to map, throws the exception.

 @param annotation TTAnnotation
 */
- (void)removeAnnotation:(TTAnnotation * _Nonnull)annotation;

/**
 Removes all annotations from the map.
 */
- (void)removeAllAnnotations;

/**
 Only one annotation on the map can be selected.
 Annotation can be selected by calling this method explicitly or by tapping on a marker on the map.
 You cant select annotation that has NO set of property selectable.

 @param annotation TTAnnotation
 */
- (void)selectAnnotation:(TTAnnotation * _Nonnull)annotation;

/**
 Deselect annotation if selected and remove callout if opened.
 */
- (void)deselectAnnotation;

/**
 Returns selected annotation if any otherwise nil is none is selected.
 */
@property (nonatomic, strong, readonly) TTAnnotation * _Nullable selectedAnnotation;

#pragma mark - Overlay

/**
 Adds the overlay object to the map.

 @param overlay An interface for associating content with a specific map region.
 */
- (void)addOverlay:(TTOverlay *_Nonnull)overlay;

/**
 Removes an overlay object from the map.

 @param overlay An interface for associating content with a specific map region.
 */
- (void)removeOverlay:(TTOverlay *_Nonnull)overlay;

/**
 Removes all overlays from the map.
 */
- (void)removeAllOverlays;

#pragma mark - Zoom

@end
