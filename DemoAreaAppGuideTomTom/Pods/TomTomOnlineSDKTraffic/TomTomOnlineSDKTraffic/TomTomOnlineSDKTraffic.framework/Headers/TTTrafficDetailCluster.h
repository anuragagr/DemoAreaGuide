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
#import "TTTrafficDetailBase.h"
#import "TTTrafficDetail.h"
#import "TTTrafficUtils.h"

@interface TTTrafficDetailCluster : TTTrafficDetailBase

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Gets a bounding box encompassing all incidents in this cluster.
 */
@property (nonatomic, readonly) TTLatLngBounds bounds;

/**
 Gets a collection of incidents that constitute this cluster.
 */
@property (nonatomic, readonly) NSArray<TTTrafficDetail *>* _Nonnull details;

@end
