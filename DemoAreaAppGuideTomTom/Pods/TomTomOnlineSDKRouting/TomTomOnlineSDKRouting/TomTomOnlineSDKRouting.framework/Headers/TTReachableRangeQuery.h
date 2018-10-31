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
#import "TTCommonQueryBuilder.h"
#import "TTReachableRangeQuery.h"

/**
 TTReachableRangeQuery represent request object for Reachable Range.
 */
@interface TTReachableRangeQuery : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end

@class TTReachableRangeQueryBuilder;

/**
 TTReachableRangeQueryBuilder is responsible for building TTReachableRangeQuery request objects.
 */
@interface TTReachableRangeQueryBuilder : TTCommonQueryBuilder<TTReachableRangeQueryBuilder *>

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Point from which the range calculation should start.

 @param coordinate CLLocationCoordinate2D
 @return TTReachableRangeQueryBuilder
 */
+ (TTReachableRangeQueryBuilder* _Nonnull)createWithCenterLocation:(CLLocationCoordinate2D)coordinate;

/**
 Fuel budget in liters that determines maximal range which can be travelled using the specified Combustion Consumption Model.

 @param fuelBudgetInLiters float
 @return TTReachableRangeQueryBuilder
 */
- (TTReachableRangeQueryBuilder* _Nonnull)withFuelBudgetInLiters:(float)fuelBudgetInLiters;

/**
 Electric energy budget in kilowatt hours (kWh) that determines maximal range which can be travelled using the specified Electric Consumption Model.

 @param energyBudgetInKWh float
 @return TTReachableRangeQueryBuilder
 */
- (TTReachableRangeQueryBuilder* _Nonnull)withEnergyBudgetInKWh:(float)energyBudgetInKWh;

/**
 Time budget in seconds that determines maximal range which can be travelled using driving time. The consumption parameters will only affect eco-routes and thereby indirectly the driving time.

 @param timeBudgetInSeconds float
 @return TTReachableRangeQueryBuilder
 */
- (TTReachableRangeQueryBuilder* _Nonnull)withTimeBudgetInSeconds:(float)timeBudgetInSeconds;


/**
 Based on provided data builds query object

 @return TTReachableRangeQuery
 */
- (TTReachableRangeQuery* _Nonnull)build;

@end
