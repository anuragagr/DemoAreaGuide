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
#import "TTAddress.h"
#import "TTBoundingBox.h"
#import "TTEntryPoint.h"
#import "TTPoi.h"

@interface TTAlongRouteSearchResult : NSObject

/**
 The type of result.
 */
@property (nonatomic, readonly, strong) NSString* _Nonnull type;
/**
 The id of result.
 */
@property (nonatomic, readonly, strong) NSString* _Nonnull ID;
/**
 The score of result.
 */
@property (nonatomic, readonly, assign) double score;
/**
 The distance of result. -1 if unknown
 */
@property (nonatomic, readonly, assign) double distance;
/**
 The information of the result.
 */
@property (nonatomic, readonly, strong) NSString* _Nonnull info;
/**
 The Poi of the result.
 */
@property (nonatomic, readonly, strong) TTPoi* _Nullable poi;
/**
 The address of the result.
 */
@property (nonatomic, readonly, strong) TTAddress* _Nonnull address;
/**
 The position of the result.
 */
@property (nonatomic, readonly, assign)  CLLocationCoordinate2D position;
/**
 The view port of the result.
 */
@property (nonatomic, readonly, strong) TTBoundingBox* _Nonnull viewport;
/**
 The array of entry points of the result.
 */
@property (nonatomic, readonly, strong)  NSArray<TTEntryPoint *>* _Nullable entryPoints;
/**
 The detour time of the result.
 */
@property (nonatomic, readonly, assign)  int detourTime;

@end
