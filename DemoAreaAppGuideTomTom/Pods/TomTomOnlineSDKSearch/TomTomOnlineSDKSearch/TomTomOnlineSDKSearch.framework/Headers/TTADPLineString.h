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
#import "TTADPGeoJsonObject.h"
#import "TTADPPosition.h"


/**
A geometry type comprising a collection of LineStrings.
 */
@interface TTADPLineString : TTADPGeoJsonObject <TTCoordinatesData>
/**
Array of TTADPPosition objects.
 */
@property (nonatomic, strong, readonly) NSArray<TTADPPosition *> * _Nonnull points;

- (NSArray<NSValue *> *_Nonnull)coordinatesData;

- (NSUInteger)coordinatesCount;

@end
