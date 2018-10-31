
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>


/**
 Base class defining route that can be added to the map.
 */
@interface TTMapRoute : NSObject <TTRouteData, TTCoordinatesData>

- (instancetype _Nonnull )init NS_UNAVAILABLE;


/**
 @deprecated This method is deprecated, use routeWithCoordinatesData instead.
 */
+ (TTMapRoute *_Nonnull)routeWithRouteData:(id<TTRouteData> _Nonnull)routeData DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use routeWithCoordinatesData instead.");
/**
 @deprecated This method is deprecated, use routeWithCoordinatesData instead.
 */
+ (TTMapRoute *_Nonnull)routeWithRouteData:(id<TTRouteData> _Nonnull)routeData
                        imageStart:(UIImage * _Nullable)imageStart
                          imageEnd:(UIImage * _Nullable)imageEnd DEPRECATED_MSG_ATTRIBUTE("This method is deprecated, use routeWithCoordinatesData instead.");

+ (TTMapRoute *_Nonnull)routeWithCoordinatesData:(id<TTCoordinatesData> _Nonnull)coordinatesData;
+ (TTMapRoute *_Nonnull)routeWithCoordinatesData:(id<TTCoordinatesData> _Nonnull)coordinatesData
                                      imageStart:(UIImage * _Nullable)imageStart
                                        imageEnd:(UIImage * _Nullable)imageEnd;

+ (TTMapRoute *_Nonnull)routeWithCoordinates:(CLLocationCoordinate2D *_Nonnull)coordinates
                                       count:(NSUInteger)count;
+ (TTMapRoute *_Nonnull)routeWithCoordinates:(CLLocationCoordinate2D *_Nonnull)coordinates
                                       count:(NSUInteger)count
                                  imageStart:(UIImage * _Nullable)imageStart
                                    imageEnd:(UIImage * _Nullable)imageEnd;

/**
 Determines which style load present route.
 */
@property (nonatomic, assign, getter=isActive) BOOL active;

/**
 This property can be used to associate any kind of data with a route.
 */
@property (nonatomic, strong) NSObject * _Nullable extraData;

- (NSArray<NSValue *> *_Nonnull)fullRoute;

- (NSArray<NSValue *> * _Nonnull)coordinatesData;

- (NSUInteger)coordinatesCount;

/**
 Returns default icon for route departure

 @return UIImage
 */
+ (UIImage* _Nonnull)defaultImageDeparture;

/**
 Returns default icon for route destination
 
 @return UIImage
 */
+ (UIImage* _Nonnull)defaultImageDestination;

@end
