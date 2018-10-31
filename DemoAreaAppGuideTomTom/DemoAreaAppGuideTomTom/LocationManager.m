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

#import "LocationManager.h"
#import "Locations.h"

@interface LocationManager () <CLLocationManagerDelegate>

@property (nonatomic) CLLocationManager *locationManager;
@property (nonatomic) BOOL serviceStarted;
@property (nonatomic, strong, readwrite) CLLocation *location;

@end

@implementation LocationManager

CLLocationDegrees radiansToDegrees_(double radians){
    return radians * 180.0 / M_PI;
}

double degreesToRadians_(CLLocationDegrees degrees){
    return degrees / 180.0 * M_PI;
}

+ (instancetype)sharedInstance {
    static dispatch_once_t p = 0;
    __strong static id _sharedObject = nil;
    
    dispatch_once(&p, ^{
        _sharedObject = [[self alloc] init];
    });
    
    return _sharedObject;
}

- (instancetype)init {
    if (self = [super init]) {
        self.locationManager = [CLLocationManager new];
        self.locationManager.delegate = self;
        self.locationManager.desiredAccuracy = kCLLocationAccuracyBest;
        self.locationManager.distanceFilter = kCLDistanceFilterNone;
    }
    
    return self;
}

#pragma mark Public methods

- (CLLocationDistance)distanceFromCurrentLocation:(CLLocationCoordinate2D)fromCoord {
    if(self.location) {
        CLLocation *location = [[CLLocation alloc] initWithLatitude:fromCoord.latitude longitude:fromCoord.longitude];
        CLLocationDistance distance = [self.location distanceFromLocation:location];
        return distance;
    } else {
        return NAN;
    }
}

- (void)startService {
    if (!self.serviceStarted)
    {
        [self startUpdatingLocation];
        self.serviceStarted = YES;
    }
}

- (void)stopService {
    if (self.serviceStarted)
    {
        [self stopUpdatingLocation];
        self.serviceStarted = NO;
    }
}

- (CLLocation *)location {
    if(_location) {
        return _location;
    } else {
        return [[CLLocation alloc] initWithLatitude:COORDINATE_AMSTERDAM.latitude longitude:COORDINATE_AMSTERDAM.longitude];
    }
}

- (BOOL)serviceEnabled {
    return [CLLocationManager locationServicesEnabled];
}

- (CLAuthorizationStatus)authorizationStatus {
    return [CLLocationManager authorizationStatus];
}

- (BOOL)canUseDeviceLocation {
    if(self.serviceEnabled) {
        return !(self.authorizationStatus == kCLAuthorizationStatusNotDetermined ||
                 self.authorizationStatus == kCLAuthorizationStatusRestricted ||
                 self.authorizationStatus == kCLAuthorizationStatusDenied);
    } else {
        return false;
    }
}


#pragma mark Private methods

- (void)startUpdatingLocation {
    
    if ([self.locationManager respondsToSelector:@selector(requestWhenInUseAuthorization)]) {
        [self.locationManager requestWhenInUseAuthorization];
    }
    
    [self.locationManager startUpdatingLocation];
    [self.locationManager startUpdatingHeading];
}

- (void)stopUpdatingLocation {
    
    [self.locationManager stopUpdatingLocation];
    [self.locationManager stopUpdatingHeading];
}

#pragma mark - CLLocationManager delegate

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if ([self serviceEnabled]) {
        [self startUpdatingLocation];
    } else {
        [self stopUpdatingLocation];
    }
}

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations {
    // If it's a relatively recent event, turn off updates to save power.
    CLLocation *location = [locations lastObject];
    NSDate *eventDate = location.timestamp;
    NSTimeInterval howRecent = [eventDate timeIntervalSinceNow];
    if (fabs(howRecent) < 15.0)
    {
        // If the event is recent, do something with it.
        //NSLog(@"latitude %+.6f, longitude %+.6f", location.coordinate.latitude, location.coordinate.longitude);
    }
    
    self.location = location;
}

- (void)locationManager:(CLLocationManager *)manager didUpdateHeading:(CLHeading *)newHeading {
    _heading = newHeading;
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error {
    NSLog(@"Location manager did fail with error: %@", [error localizedDescription]);
}

@end
