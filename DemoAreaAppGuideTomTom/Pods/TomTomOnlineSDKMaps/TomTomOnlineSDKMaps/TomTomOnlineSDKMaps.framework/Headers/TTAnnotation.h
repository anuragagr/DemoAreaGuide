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
#import <UIKit/UIKit.h>
#import "TTAnnotationImage.h"

/**
 TTAnnotationAnchor
 */
typedef NS_ENUM(NSInteger, TTAnnotationAnchor) {
    TTAnnotationAnchorCenter,
    TTAnnotationAnchorLeft,
    TTAnnotationAnchorRight,
    TTAnnotationAnchorTop,
    TTAnnotationAnchorBottom,
    TTAnnotationAnchorTopLeft,
    TTAnnotationAnchorTopRight,
    TTAnnotationAnchorBottomLeft,
    TTAnnotationAnchorBottomRight
};

typedef NS_ENUM(NSInteger, TTAnnotationType) {
    TTAnnotationTypeFocal,
    TTAnnotationTypeDecal
};

typedef NS_ENUM(NSUInteger, TTAnnotationDragState) {
    TTAnnotationViewDragStateIdle,
    TTAnnotationViewDragStateStarting,
    TTAnnotationViewDragStateDragging
};

extern int const ANNOTATION_ID_UNDEFINED;

/**
 * The TTAnnotation class is used to provide annotation-related information to a map view.
 * To use this class, you adopt it in any custom objects that store or represent annotation data.
 * Annotation objects do not provide the visual representation of the annotation but typically coordinate.
 **/
@interface TTAnnotation : NSObject

/**
 @deprecated This method is deprecated, use defaultAnnotationImage instead.
 
 Returns new instance of an image that is used by SDK as default annotation representation.
 @return UIImage
 */
+ (UIImage* _Nonnull)defaultImage DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use defaultAnnotationImage instead.");

/**
 Returns new instance of an image that is used by SDK as default annotation representation.
 @return TTAnnotationImage
 */
+ (TTAnnotationImage *_Nonnull)defaultAnnotationImage;

/**
 Creates annotation placed on given location with default image
 @param coordinate coordinate of annotation
 @return TTAnnotation
 */
+ (TTAnnotation* _Nonnull)annotationWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Creates annotation placed on given location with default image
 The anchor allows specifying which point of an annotation image is attached to the map.
 The annotation will rotate around this anchoring point when rotating the map.

 @param coordinate coordinate of annotation
 @param anchor anchor determines how to attach image to coordinate
 @param type type determines how annotation is draw when rotating map
 @return TTAnnotation
 */
+ (TTAnnotation* _Nonnull)annotationWithCoordinate:(CLLocationCoordinate2D)coordinate
                                    anchor:(TTAnnotationAnchor)anchor
                                      type:(TTAnnotationType)type;

/**
 @deprecated This method is deprecated, use initWithCoordinate and annotationImage instead.
 
 Creates annotation placed on given location with provided image and anchor.
 When you add a custom image for annotation you are forced to give it a tag.
 Tags are used to as keys in a map where images are stored. That saves a lot of
 memory when you want to add the same image for multiple annotations.
 The anchor allows specifying which point of an annotation image is attached to the map.
 The annotation will rotate around this anchoring point when rotating the map.

 @param coordinate coordinate of annotation
 @param image image representation of annotation
 @param tag tag for image to optimize memory usage
 @param anchor anchor determines how to attach image to coordinate
 @param type type determines how annotation is draw when rotating map
 @return TTAnnotation

 */
+ (TTAnnotation* _Nonnull)annotationWithCoordinate:(CLLocationCoordinate2D)coordinate
                                     image:(UIImage* _Nonnull)image
                                       tag:(NSString* _Nonnull)tag
                                    anchor:(TTAnnotationAnchor)anchor
                                      type:(TTAnnotationType)type DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use initWithCoordinate and annotationImage instead.");

/**
 Creates annotation placed on given location with provided image and anchor.
 The anchor allows specifying which point of an annotation image is attached to the map.
 The annotation will rotate around this anchoring point when rotating the map.

 @param coordinate coordinate of annotation
 @param image image representation of annotation
 @param anchor anchor determines how to attach image to coordinate
 @param type type determines how annotation is draw when rotating map
 @return TTAnnotation
 */
+ (TTAnnotation * _Nonnull)annotationWithCoordinate:(CLLocationCoordinate2D)coordinate
                           annotationImage:(TTAnnotationImage* _Nonnull)image
                                    anchor:(TTAnnotationAnchor)anchor
                                      type:(TTAnnotationType)type;

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Creates annotation placed on given location with default image
 @param coordinate coordinate of annotation
 */
- (instancetype _Nonnull)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Creates annotation placed on given location with default image
 The anchor allows specifying which point of an annotation image is attached to the map.
 The annotation will rotate around this anchoring point when rotating the map.

 @param coordinate coordinate of annotation
 @param anchor anchor determines how to attach image to coordinate
 @param type type determines how annotation is draw when rotating map
 */
- (instancetype _Nonnull)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                            anchor:(TTAnnotationAnchor)anchor
                              type:(TTAnnotationType)type;

/**
 @deprecated This method is deprecated, use initWithCoordinate and annotationImage instead.
 
 Creates annotation placed on given location with provided image and anchor.
 When you add a custom image for annotation you are forced to give it a tag.
 Tags are used to as keys in a map where images are stored. That saves a lot of
 memory when you want to add the same image for multiple annotations.
 The anchor allows specifying which point of an annotation image is attached to the map.
 The annotation will rotate around this anchoring point when rotating the map.

 @param coordinate coordinate of annotation
 @param image image representation of annotation
 @param tag tag for image to optimize memory usage
 @param anchor anchor determines how to attach image to coordinate
 @param type type determines how annotation is draw when rotating map
 */
- (instancetype _Nonnull)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                             image:(UIImage * _Nonnull)image
                               tag:(NSString * _Nonnull)tag
                            anchor:(TTAnnotationAnchor)anchor
                              type:(TTAnnotationType)type DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use initWithCoordinate and annotationImage instead.");



/**
 Creates annotation placed on given location with provided image and anchor.
 When you add a custom image for annotation you are forced to give it a tag.
 Tags are used to as keys in a map where images are stored. That saves a lot of
 memory when you want to add the same image for multiple annotations.
 The anchor allows specifying which point of an annotation image is attached to the map.
 The annotation will rotate around this anchoring point when rotating the map.

 @param coordinate coordinate of annotation
 @param image image representation of annotation
 @param anchor anchor determines how to attach image to coordinate
 @param type type determines how annotation is draw when rotating map
 */
- (instancetype _Nonnull)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                                      annotationImage:(TTAnnotationImage * _Nonnull)image
                                     anchor:(TTAnnotationAnchor)anchor
                                       type:(TTAnnotationType)type;

/**
 Location of annotation. Latitude between -90 - 90 and longitude -180 - 180
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/**
 Determines how an image of is attached to coordinates. E.g. Bottom will take center width,
 bottom height of the image and attach it to annotation location.
 */
@property (nonatomic, assign, readonly) TTAnnotationAnchor anchor;

/**
  Determines how an image of annotations behaves when map rotates.
 */
@property (nonatomic, assign, readonly) TTAnnotationType type;

/**
 Determines if annotation can be selected either by manager select call or tapping on the map.
 By default annotations are selectable.
 */
@property (nonatomic, assign) BOOL selectable;

/**
 Determines if an annotation is selected.
 */
@property (nonatomic, assign, readonly) BOOL isSelected;

/**
 Determines if can display callout or not when selected.
 */
@property (nonatomic, assign) BOOL canShowCallout;

/**
 NSString value that you can use to identify annotation object on your map.
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull annotationTag;

/**
 Indicates whether annotation should clustered or not. If not, annotation will be skipped from clustering procedure when it is enabled.
 */
@property (nonatomic, assign) BOOL shouldCluster;

/**
 Indicates whether annotation is draggable.
 */
@property (nonatomic, assign) BOOL isDraggable;

/**
 The current drag state of TTAnnotation.
 */
@property (nonatomic, assign, readonly) TTAnnotationDragState dragState;

@end