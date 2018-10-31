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

#import "MapAnnotationsViewController.h"
#import <TomTomOnlineSDKMapsUIExtensions/TomTomOnlineSDKMapsUIExtensions.h>
#import "Locations.h"
#import "OverlayDrawing.h"
#import "MyCalloutView.h"

#define ARC4RANDOM_MAX 0x100000000

@interface MapAnnotationsViewController () <UIExampleViewControllerDelegate, TTAnnotationDelegate>

@property (nonatomic, weak) IBOutlet TTMapView *mapView;
@property (weak, nonatomic) IBOutlet TTControlView *controlView;
@property (nonatomic, assign) MapAnnotationMode mode;

@property (nonatomic, strong) TTAnnotation *simpleOfficeAnnotation;
@property (nonatomic, strong) TTAnnotation *customOfficeAnnotation;

@end


@implementation MapAnnotationsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.delegate = self;
    [self setShowToastEnable:true];
    self.mapView.showsUserLocation = YES;
    self.controlView.mapView = self.mapView;
    [self.controlView initDefaultCompassButton];
    [self.controlView initDefaultCenterButton];
    self.controlView.topLayoutConstraintCompassButton.constant = TopLayoutConstraintCompass;
    self.controlView.bottomLayoutConstraintCenterButton.constant = BottomLayoutConstraintCenterCustom;

    self.mapView.annotationManager.delegate = self;

    switch (_mode) {
        case MapAnnotationMarkers:
            [self buildHeader:@"Markers" and:@"Amsterdam"];
            [self createSegmentedControllWithTag:MapAnnotationMarkers options:@[@"Simple", @"Decal"] multiSelect:NO select:-1];
            [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
            break;
        case MapAnnotationAdvencedMarkers:
            [self buildHeader:@"Advenced Markers" and:@"Amsterdam"];
            [self createSegmentedControllWithTag:MapAnnotationAdvencedMarkers options:@[@"Animated", @"Draggable"] multiSelect:NO select:-1];
            [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
            break;
        case MapAnnotationShapes:
            [self buildHeader:@"Shapes" and:@"Amsterdam"];
            [self createSegmentedControllWithTag:MapAnnotationShapes options:@[@"Polygon", @"Polyline", @"Circle"] multiSelect:NO select:-1];
            [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
            break;
            
        case MapAnnotationBalloons:
            [self buildHeader:@"Balloons" and:@"Amsterdam"];
            [self createSegmentedControllWithTag:MapAnnotationBalloons options:@[@"Simple", @"Custom"] multiSelect:NO select:-1];
            [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
            break;

        case MapAnnotationMarkersClustering:
            [self buildHeader:@"Markers clustering" and:@"Amsterdam"];
            [self createSegmentedControllWithTag:MapAnnotationMarkersClustering options:@[] multiSelect:NO select:-1];
            [self.mapView.annotationManager setClustering:YES];
            [self addRandomMarkers];
            [self.mapView zoomToAllAnnotations];
            break;
    }
}

- (void)setMapAnnotationsMode:(MapAnnotationMode)mode {
    self.mode = mode;
}

- (void)addSimpleMarkers {
    for(int i = 0; i < 5; i++) {
        CLLocationCoordinate2D coordinate = [self makeRandomCoordinateForCenteroid:COORDINATE_AMSTERDAM];
        TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:coordinate];
        [self.mapView.annotationManager addAnnotation:annotation];
    }
}

- (void)addAnimatedMarkers {
    for(int i = 0; i < 5; i++) {
        CLLocationCoordinate2D coordinate = [self makeRandomCoordinateForCenteroid:COORDINATE_AMSTERDAM];
        TTAnnotationImage *annotationGif = [[TTAnnotationImage init] createGIFWithName:@"gif_annotation"];
        TTAnnotation *annotation = [[TTAnnotation alloc] initWithCoordinate:coordinate annotationImage:annotationGif anchor:TTAnnotationAnchorCenter type:TTAnnotationTypeFocal];
        [self.mapView.annotationManager addAnnotation:annotation];
    }
}

- (void)addDecalMarkers {
    for(int i = 0; i < 5; i++) {
        CLLocationCoordinate2D coordinate = [self makeRandomCoordinateForCenteroid:COORDINATE_AMSTERDAM];
        UIImage *image = [UIImage imageNamed:@"Favourite"];
        TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:coordinate image:image tag:@"favourite" anchor:TTAnnotationAnchorBottom type:TTAnnotationTypeDecal];
        [self.mapView.annotationManager addAnnotation:annotation];
    }
}

- (void)addDraggableMarkers {
    for(int i = 0; i < 5; i++) {
        CLLocationCoordinate2D coordinate = [self makeRandomCoordinateForCenteroid:COORDINATE_AMSTERDAM];
        TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:coordinate];
        annotation.isDraggable = true;
        [self.mapView.annotationManager addAnnotation:annotation];
    }
}

- (void)addRandomMarkers {
    for(int i = 0; i < 90; i++) {
        CLLocationCoordinate2D coordinate = [self makeRandomCoordinateForCenteroid:COORDINATE_AMSTERDAM];
        TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:coordinate];
        [self.mapView.annotationManager addAnnotation:annotation];
    }
    for(int i = 0; i < 150; i++) {
        CLLocationCoordinate2D coordinate = [self makeRandomCoordinateForCenteroid:COORDINATE_ROTTERDAM];
        TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:coordinate];
        [annotation setShouldCluster:YES];
        [self.mapView.annotationManager addAnnotation:annotation];
    }
}

- (CLLocationCoordinate2D)makeRandomCoordinateForCenteroid:(CLLocationCoordinate2D)center {
    float latitude = (float) [self randFloatBetween:center.latitude - 0.1 and:center.latitude + 0.1];
    float longitude = (float) [self randFloatBetween:center.longitude - 0.1 and:center.longitude + 0.1];
    return CLLocationCoordinate2DMake(latitude, longitude);
}

- (float)randFloatBetween:(float)low and:(float)high {
    return ((float)arc4random() / ARC4RANDOM_MAX * (high - low)) + low;
}

- (void)optionButtonTag:(NSInteger)tag index:(int)index {
    if(index < 0) {
        return;
    }
    self.mode = (MapAnnotationMode)tag;
    switch (tag) {
        case MapAnnotationMarkers:
            [self resultMapAnnotationMarkes:index];
            break;
        case MapAnnotationAdvencedMarkers:
            [self resultMapAnnotationAdvancedMarkes:index];
            break;
        case MapAnnotationShapes:
            [self resultMapAnnotationShapes:index];
            break;
            
        case MapAnnotationBalloons:
            [self resultMapAnnotationBalloons:index];
            break;

        default:
            break;
    }
}

#pragma mark - Result Map Annotation Balloons
- (void)resultMapAnnotationBalloons:(NSInteger)index {
    [self.mapView.annotationManager removeAllAnnotations];
    
    TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:COORDINATE_AMSTERDAM_TOMTOM];

    switch(index) {
        case 0:
        {
            self.simpleOfficeAnnotation = annotation;
            break;
        }
        case 1:
        {
            self.customOfficeAnnotation = annotation;
            break;
        }
        default:
            break;
    }
    
    [self.mapView.annotationManager addAnnotation:annotation];
    [self.mapView.annotationManager selectAnnotation:annotation];
}

#pragma mark - Result Map Annotation Markers
- (void)resultMapAnnotationMarkes:(NSInteger)index {
    [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
    [self.mapView.annotationManager removeAllAnnotations];
    switch (index) {
        default:
        case 0:
            self.mapView.bearing = 0;
            [self addSimpleMarkers];
            break;
            
        case 1:
            self.mapView.bearing = 180;
            [self addDecalMarkers];
            break;
    }
}

#pragma mark - Result Map Annotation Advanced Markers
- (void)resultMapAnnotationAdvancedMarkes:(NSInteger)index {
    [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
    [self.mapView.annotationManager removeAllAnnotations];
    switch (index) {
        default:
        case 0:
            self.mapView.bearing = 0;
            [self addAnimatedMarkers];
            break;
            
        case 1:
            self.mapView.bearing = 0;
            [self addDraggableMarkers];
            break;
    }
}


#pragma mark - Result Map Annotation Shapes
- (void)resultMapAnnotationShapes:(NSInteger)index {
    // Generate a fairly random-looking polygon of latitudes/longitudes centered around where the user
    // long-pressed.
    const int               MAP_ZOOM = 10;
    static const int		POLYLINE_POINTS = 24;
    const float				POLYLINE_RADIUS = 128.0f / (1 << MAP_ZOOM);
    const float				DEGREES_PER_POINT = 360.0f / POLYLINE_POINTS;
    const float				CENTER_SPACE_RATIO = 0.8f;
    CLLocationCoordinate2D	coordinates[POLYLINE_POINTS];
    CLLocationCoordinate2D	centroid = COORDINATE_AMSTERDAM;

    for (int i = 0; i < POLYLINE_POINTS; i++)
    {

        const float	dist = POLYLINE_RADIUS * CENTER_SPACE_RATIO + POLYLINE_RADIUS * (1.0f - CENTER_SPACE_RATIO) * randomRatio();
        const float	angle = i * DEGREES_PER_POINT + randomRatio() * DEGREES_PER_POINT;
        const float	y = sinf(deg2rad(angle)) * dist;
        const float	x = cosf(deg2rad(angle)) * dist;

        coordinates[i] = centroid;
        coordinates[i].latitude += y;
        coordinates[i].longitude += x;

        if (i == (POLYLINE_POINTS - 1)) {
            coordinates[i] = centroid;
            coordinates[i].latitude = coordinates[0].latitude;
            coordinates[i].longitude = coordinates[0].longitude;
        }

    }

    [self.mapView centerOnCoordinate:COORDINATE_AMSTERDAM withZoom:10];
    [self.mapView.annotationManager removeAllOverlays];
    UIColor *color = [UIColor colorWithRed:randomRatio()
                                      green:randomRatio()
                                       blue:randomRatio()
                                      alpha:randomRatio() * 0.5f + 0.5f];

    switch (index) {
        case 0: // Polygon
        {
            TTPolygon *polygon = [TTPolygon polygonWithCoordinates:coordinates count:POLYLINE_POINTS opacity:1.0 color:color colorOutline:color];
            [self.mapView.annotationManager addOverlay:polygon];

        }
            break;
        case 1: // Polyline
        {
            TTPolyline *polyline = [TTPolyline polylineWithCoordinates:coordinates count:(NSUInteger) (POLYLINE_POINTS / 1.5) opacity:(float) 1.0 width:(float) 8.0 color:color];
            [self.mapView.annotationManager addOverlay:polyline];
        }
            break;
        case 2: // Circle
        {
            TTCircle *circle = [TTCircle circleWithCenterCoordinate:centroid radius:5000 width:10.0 color:color fill:true colorOutlet:[UIColor redColor]];
            [self.mapView.annotationManager addOverlay:circle];
        }
            break;
        
        default:
            break;
    }

}

- (void)annotationManager:(id<TTAnnotationManager>)annotationManager annotationSelected:(TTAnnotation *)annotation {
    //handle annotation selected event
}

- (UIView<TTCalloutView> *_Nonnull)annotationManager:(id<TTAnnotationManager>)annotationManager viewForSelectedAnnotation:(TTAnnotation *)selectedAnnotation {
    if(self.simpleOfficeAnnotation && [selectedAnnotation isEqual:self.simpleOfficeAnnotation]) {
        return [[TTCalloutViewSimple alloc] initWithText:@"Welcome to TomTom"];
    } else if(self.customOfficeAnnotation && [selectedAnnotation isEqual:self.customOfficeAnnotation]) {
        MyCalloutView<TTCalloutView> *callout = [[[NSBundle mainBundle] loadNibNamed:@"MyCalloutView" owner:self options:nil] firstObject];
        return callout;
    } else {
        return [[TTCalloutViewSimple alloc] initWithAnnotation:selectedAnnotation];
    }
}

- (void)annotationManager:(id<TTAnnotationManager>)annotationManager touchUpPolyline:(TTPolyline *)polyline {
    [self showToast:[NSString stringWithFormat:@"Polyline clicked"] withTimer:YES];
}

- (void)annotationManager:(id<TTAnnotationManager>)annotationManager touchUpPolygon:(TTPolygon *)polygon {
    [self showToast:[NSString stringWithFormat:@"Polygon clicked"] withTimer:YES];
}

- (void)annotationManager:(id<TTAnnotationManager>)annotationManager touchUpCircle:(TTCircle *)circle {
    [self showToast:[NSString stringWithFormat:@"Circle clicked"] withTimer:YES];
}

- (void)annotationManager:(id<TTAnnotationManager>)manager draggingAnnotation:(TTAnnotation *)annotation stateDrag:(TTAnnotationDragState)state {

    NSString *msg = @"";
    switch (state) {
        case TTAnnotationViewDragStateIdle:
            msg = @"State: TTAnnotationViewDragStateIdle";
            break;

        case TTAnnotationViewDragStateDragging:
            msg = @"State: TTAnnotationViewDragStateDragging";
            break;

        case TTAnnotationViewDragStateStarting:
            msg = @"State: TTAnnotationViewDragStateStarting";
            break;

        default:
            break;
    }

    [self showToast:msg withTimer:NO];
}

@end
