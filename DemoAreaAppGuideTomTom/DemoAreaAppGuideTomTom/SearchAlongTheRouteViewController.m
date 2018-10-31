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

#import "SearchAlongTheRouteViewController.h"
#import <TomTomOnlineSDKMapsUIExtensions/TomTomOnlineSDKMapsUIExtensions.h>
#import <TomTomOnlineSDKRouting/TomTomOnlineSDKRouting.h>
#import <TomTomOnlineSDKMaps/TomTomOnlineSDKMaps.h>
#import <TomTomOnlineSDKSearch/TomTomOnlineSDKSearch.h>
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>
#import "ProgressUtil.h"
#import "Locations.h"
#import "OverlayDrawing.h"
#import "MyCalloutView.h"
#import "LocationManager.h"

#define ARC4RANDOM_MAX 0x100000000
#define TOPPADDING 30
#define LEFTPADDING 15

@interface SearchAlongTheRouteViewController () <UIPageViewControllerDelegate,TTAnnotationDelegate,TTMapViewDelegate, TTRouteDelegate,TTRouteResponseDelegate,TTAlongRouteSearchDelegate>

@property (nonatomic, weak) IBOutlet TTMapView *mapView;
@property (weak, nonatomic) IBOutlet TTControlView *controlView;
@property (nonatomic, assign) SearchAlongMode mode;
@property TTRoute* routePlanner;
@property TTRouteQuery *query;
@property TTAlongRouteSearch *alongRouteSearch;
@property TTRouteResult *resoultRoute;
@property (nonatomic, strong) ProgressUtil *progress;
@property (nonatomic) LocationManager *locationManager;
@end


@implementation SearchAlongTheRouteViewController
@synthesize destinationLocation;
- (void)route:(TTRoute *)route completedWithResult:(TTRouteResult *)result{
    [self.progress cancelProgress];
    [self.mapView.routeManager removeAllRoutes];
    
    BOOL markAsActive = YES;
    self.resoultRoute = result;
    for(TTFullRoute *fullRoute in result.routes) {
        TTMapRoute *mapRoute = [TTMapRoute routeWithCoordinatesData:fullRoute imageStart:[UIImage imageNamed:@"ic_map_route_departure"] imageEnd:[UIImage imageNamed:@"ic_map_route_destination"]];
        mapRoute.extraData = fullRoute.summary;
        [self.mapView.routeManager addRoute:mapRoute];
        if(markAsActive){
            mapRoute.active = YES;
            markAsActive = NO;
        }
        
    }
    [self displayRouteOverview];
}

- (void)route:(TTRoute *)route completedWithResponseError:(TTResponseError *)responseError {
    
}

- (void)displayRouteOverview {
    UIEdgeInsets insets = UIEdgeInsetsMake(TOPPADDING * UIScreen.mainScreen.scale,
                                           LEFTPADDING * UIScreen.mainScreen.scale,
                                           self.mapView.frame.size.height - self.optionsContainer.frame.origin.y +
                                           10 * UIScreen.mainScreen.scale,
                                           10 * UIScreen.mainScreen.scale);
    
    self.mapView.contentInset = insets;
    [self.mapView.routeManager showAllRoutesOverview];
}

-(void)search:(TTAlongRouteSearch *)search completedWithResponse:(TTAlongRouteSearchResponse *)response {
    for (TTAlongRouteSearchResult *result in response.results){
        TTAnnotation *annotation = [TTAnnotation annotationWithCoordinate:result.position];
        annotation.selectable = YES;
        NSLog(@"result %@", response.results);
        [self.mapView.annotationManager addAnnotation:annotation];
    }
}

- (void)search:(TTAlongRouteSearch *)search failedWithError:(TTResponseError *)error {
    [self showToast:[NSString stringWithFormat:@"Error: %@", [error.userInfo objectForKey:@"description"]] withTimer:NO];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    if(!self.locationManager.serviceEnabled) {
        self.locationManager = [LocationManager sharedInstance];
        [self.locationManager startService];
    }
   // [[self navigationController] setNavigationBarHidden:NO animated:NO];
    self.delegate = self;
    [self setShowToastEnable:true];
    self.mapView.showsUserLocation = YES;
    self.controlView.mapView = self.mapView;
    [self.controlView initDefaultCompassButton];
    [self.controlView initDefaultCenterButton];
    self.controlView.topLayoutConstraintCompassButton.constant = TopLayoutConstraintCompass;
    self.controlView.bottomLayoutConstraintCenterButton.constant = BottomLayoutConstraintCenterCustom;
    [self displayRouteOverview];
    self.routePlanner = [[TTRoute alloc] init];
    self.routePlanner.delegate = self;
    self.alongRouteSearch = [[TTAlongRouteSearch alloc] init];
    self.alongRouteSearch.delegate = self;
    self.delegate = self;
    self.routePlanner.delegate = self;
    self.mapView.annotationManager.delegate = self;
    self.mapView.delegate = self;
    self.mapView.showsUserLocation = YES;
    self.mapView.routeManager.delegate = self;
    
    [self buildHeader:@"Search along the route" and:@"Mumabi to Hyderbad"];
    [self createSegmentedControllWithTag:SearchAlongTheRoute options:@[@"Places", @"Restaurants", @"Traffic"] multiSelect:YES select:-1];
    printf("location %f",self.locationManager.location.coordinate.latitude);
//    _currentLocationCoordinate = [self.locationManager.location.coordinate];
//    if (CLLocationCoordinate2DIsValid(*(_currentLocationCoordinate))) {
//        NSLog(@"Coordinate valid");
//    } else {
//        NSLog(@"Coordinate invalid");
//    }
   // if(self.locationManager.location)
    self.query = [[TTRouteQueryBuilder createWithDest:destinationLocation.coordinate andOrig:self.locationManager.location.coordinate] build];
    [self.routePlanner planRouteWithQuery:self.query];
    
}

- (void)optionButtonTag:(NSInteger)tag index:(int)index {
    [self.mapView.annotationManager removeAllAnnotations];
    NSLog(@"index %d", index);
    NSString *term;
    switch (index) {
        case 0:
            term = @"PLACES";
            break;
        case 1:
            term = @"RESTAURANTS";
            break;
        case 2:
            term = @"TRAFFIC";
            break;
        default:
            break;
    }
    TTAlongRouteSearchQuery *alongRouteSearchQuery = [[[[TTAlongRouteSearchQueryBuilder alloc] initWithTerm:term withRoute:self.resoultRoute.routes.firstObject withMaxDetourTime:900] withLimit:10] build];
    
    [self.alongRouteSearch searchWithQuery:alongRouteSearchQuery];
    [self showToast:[NSString stringWithFormat:@"Fetching the %@",term] withTimer:NO];

}

@end

