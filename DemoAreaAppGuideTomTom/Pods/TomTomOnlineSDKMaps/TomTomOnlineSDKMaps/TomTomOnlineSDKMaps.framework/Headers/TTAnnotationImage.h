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

@interface TTAnnotationImage : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Init TTAnnotationImage class with GIF image by name

 @param name of image
 @return TTAnnotationImage class
 */
+ (TTAnnotationImage * _Nullable)createGIFWithName:(NSString* _Nonnull)name;

/**
  Init TTAnnotationImage class with PNG image by name

 @param name of image
 @return TTAnnotationImage class
 */
+ (TTAnnotationImage * _Nullable)createPNGWithName:(NSString* _Nonnull)name;


/**
 Init TTAnnotationImage class with GIF image by name and bundle

 @param bundle containing image
 @param name of image
 @return TTAnnotationImage class
 */
+ (TTAnnotationImage * _Nullable)createGIFWithBundle:(NSBundle* _Nonnull)bundle withName:(NSString* _Nonnull)name;

/**
 Init TTAnnotationImage class with PNG image by name and bundle
 
 @param bundle containing image
 @param name of image
 @return TTAnnotationImage class
 */
+ (TTAnnotationImage * _Nullable)createPNGWithBundle:(NSBundle* _Nonnull)bundle withName:(NSString* _Nonnull)name;

@end
