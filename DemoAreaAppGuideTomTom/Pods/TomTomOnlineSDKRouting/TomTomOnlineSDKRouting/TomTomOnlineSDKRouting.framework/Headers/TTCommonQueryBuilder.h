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
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>


/**
 TTLocationCircle struct of circle with a center point and a radius (in meters).
 */
typedef struct TTLocationCircle{
    CLLocationCoordinate2D centerPoint;
    double meters;
} TTLocationCircle;

/**
 Returns a TTLocationCircle struct at the given center point and a radius
 
 @param centerPoint center point type CLLocationCoordinate2D
 @param meters circle radius in meters
 @return TTLocationCircle
 */
NS_INLINE TTLocationCircle TTLocationCircleMake(CLLocationCoordinate2D centerPoint, double meters) {
    TTLocationCircle circle;
    circle.centerPoint = centerPoint;
    circle.meters = meters;
    return circle;
}

/**
 Specifies the speed-dependent component of consumption.
 */
typedef struct TTSpeedConsumption{
    int speed;
    double consumption;
}TTSpeedConsumption;


/**
 Specifies the speed-dependent component of consumption.
 
 @param speed current speed
 @param consumption current consumption
 @return TTSpeedConsumption
 */
NS_INLINE TTSpeedConsumption TTSpeedConsumptionMake(int speed, double consumption){
    TTSpeedConsumption speedConsumption;
    speedConsumption.speed = speed;
    speedConsumption.consumption = consumption;
    return speedConsumption;
};


typedef NS_ENUM(NSInteger, TTOptionTypeRoute) {
    TTOptionTypeRouteNone,
    TTOptionTypeRouteFastest,
    TTOptionTypeRouteShortest,
    TTOptionTypeRouteEco,
    TTOptionTypeRouteThrilling
};

typedef NS_OPTIONS(NSInteger, TTOptionTypeAvoid){
    TTOptionTypeAvoidNone = 0,
    TTOptionTypeAvoidTollRoads = 1 << 0,
    TTOptionTypeAvoidMotorways = 1 << 1,
    TTOptionTypeAvoidFerries = 1 << 2,
    TTOptionTypeAvoidUnpavedRoads = 1 << 3,
    TTOptionTypeAvoidCarpools = 1 << 4,
    TTOptionTypeAvoidAalreadyUsedRoads = 1 << 5
};

typedef NS_ENUM(NSInteger, TTOptionInstructionsType) {
    TTOptionInstructionsTypeNone,
    TTOptionInstructionsTypeCoded,
    TTOptionInstructionsTypeText,
    TTOptionInstructionsTypeTagged
};

typedef NS_ENUM(NSInteger, TTOptionTravelMode) {
    TTOptionTravelModeNone,
    TTOptionTravelModeCar,
    TTOptionTravelModeTruck,
    TTOptionTravelModeTaxi,
    TTOptionTravelModeBus,
    TTOptionTravelModeVan,
    TTOptionTravelModeMotorCycle,
    TTOptionTravelModeBicycle,
    TTOptionTravelModePedestrian
};

typedef NS_ENUM(NSInteger, TTOptionVehicleEngineType) {
    TTOptionVehicleEngineTypeNone,
    TTOptionVehicleEngineTypeCombustion,
    TTOptionVehicleEngineTypeElectric
};

typedef NS_ENUM(NSInteger, TTOptionVehicleLoadType) {
    TTOptionVehicleLoadTypeNone,
    TTOptionVehicleLoadTypeUSHazmatClass1,
    TTOptionVehicleLoadTypeUSHazmatClass2,
    TTOptionVehicleLoadTypeUSHazmatClass3,
    TTOptionVehicleLoadTypeUSHazmatClass4,
    TTOptionVehicleLoadTypeUSHazmatClass5,
    TTOptionVehicleLoadTypeUSHazmatClass6,
    TTOptionVehicleLoadTypeUSHazmatClass7,
    TTOptionVehicleLoadTypeUSHazmatClass8,
    TTOptionVehicleLoadTypeUSHazmatClass9,
    TTOptionVehicleLoadTypeOtherHazmatExplosive,
    TTOptionVehicleLoadTypeOtherHazmatGeneral,
    TTOptionVehicleLoadTypeOtherHazmatHarmfulToWater
};

typedef NS_ENUM(NSInteger, TTOptionHilliness) {
    TTOptionHillinessNone,
    TTOptionHillinessLow,
    TTOptionHillinessNormal,
    TTOptionHillinessHigh
};

typedef NS_ENUM(NSInteger, TTOptionWindingness) {
    TTOptionWindingnessNone,
    TTOptionWindingnessLow,
    TTOptionWindingnessNormal,
    TTOptionWindingnessHigh
};

typedef NS_ENUM(NSInteger, TTSectionType) {
    TTSectionTypeNone,
    TTSectionTypeCarTrain,
    TTSectionTypeCountry,
    TTSectionTypeFerry,
    TTSectionTypeMotorway,
    TTSectionTypePedestrian,
    TTSectionTypeTollRoad,
    TTSectionTypeTollVignette,
    TTSectionTypeTraffic,
    TTSectionTypeTravelMode,
    TTSectionTypeTunnel
};


@interface TTCommonQueryBuilder<__covariant ObjectType> : NSObject

/**
 @param wayPoints The arrray of map coordinate whose geographical information your way points
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withWayPoints:(CLLocationCoordinate2D* _Nonnull)wayPoints count:(NSUInteger)count;
    
/**
 @param wayPoints The arrray of map coordinate whose geographical information your way points
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withWayPoints:(NSArray<NSValue *>* _Nonnull)wayPoints;
    
/**
 circle with a center point and a radius (in meters). The radius must be a positive integer with the maximum value of 20050000. Note that larger integer values will not be rejected but lowered to the maximum value.
 */
- (ObjectType _Nonnull) withCircles:(TTLocationCircle* _Nonnull)circles withCount:(NSUInteger)count;
    
/**
 @param routeType The map coordinate whose geographical information your destination position.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withRouteType:(TTOptionTypeRoute)routeType;
    
/**
 @param isTraffic Do consider all available traffic information during routing
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withTraffic:(BOOL)isTraffic;
    
/**
 @param avoidType Specifies something that the route calculation should try to avoid when determining the route. Can be specified multiple times.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withAvoidType:(TTOptionTypeAvoid)avoidType;
    
/**
 @param departAt The date and time of departure from the origin point.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withDepartAt:(NSDate* _Nonnull)departAt;

/**
 @param travelMode The mode of travel for the requested route.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withTravelMode:(TTOptionTravelMode)travelMode;

/**
 @param vehicleEngineType Engine type of the vehicle. When a detailed Consumption Model is specified, it must be consistent with the value of vehicleEngineType.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleEngineType:(TTOptionVehicleEngineType)vehicleEngineType;
    
/**
 @param vehicleMaxSpeed Maximum speed of the vehicle in km/hour.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleMaxSpeed:(NSUInteger)vehicleMaxSpeed;
    
/**
 @param vehicleWeight Weight of the vehicle in kilograms.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleWeight:(NSUInteger)vehicleWeight;
    
/**
 @param vehicleAxleWeight Weight per axle of the vehicle in kg
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleAxleWeight:(NSUInteger)vehicleAxleWeight;
    
/**
 @param vehicleLength Length of the vehicle in meters.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleLength:(double)vehicleLength;
    
/**
 @param vehicleWidth Width of the vehicle in meters.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleWidth:(double)vehicleWidth;
    
/**
 @param vehicleHeight Height of the vehicle in meters.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleHeight:(double)vehicleHeight;
    
/**
 @param isVehicleCommercial Vehicle is used for commercial purposes and thus may not be allowed to drive on some roads.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleCommercial:(BOOL)isVehicleCommercial;
    
/**
 @param vehicleLoadType Types of cargo that may be classified as hazardous materials and restricted from some roads.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withVehicleLoadType:(TTOptionVehicleLoadType)vehicleLoadType;

/**
 @param hilliness Degree of hilliness for thrilling route.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withHilliness:(TTOptionHilliness)hilliness;
    
/**
 @param windingness Level of turns for thrilling route.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withWindingness:(TTOptionWindingness)windingness;
    
/**
 @param report Specifies which data should be reported for diagnosis purposes.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withReport:(NSString* _Nonnull)report;
    
/**
 @param currentFuelInLiters Specifies the current supply of fuel in liters.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withCurrentFuelInLiters:(double)currentFuelInLiters;
    
/**
 @param auxiliaryPowerInLitersPerHour Specifies the amount of fuel consumed for sustaining auxiliary systems of the vehicle, in liters per hour. It can be used to specify consumption due to devices and systems such as AC systems, radio, heating, etc.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withCurrentAuxiliaryPowerInLitersPerHour:(double)auxiliaryPowerInLitersPerHour;
    
/**
 @param fuelEnergyDensityInMJoulesPerLiter Specifies the amount of chemical energy stored in one liter of fuel in megajoules (MJ). It is used in conjunction with the *Efficiency parameters for conversions between saved or consumed energy and fuel. For example, energy density is 34.2 MJ/l for gasoline, and 35.8 MJ/l for Diesel fuel.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withFuelEnergyDensityInMJoulesPerLiter:(double)fuelEnergyDensityInMJoulesPerLiter;
    
/**
 @param accelerationEfficiency Specifies the efficiency of converting chemical energy stored in fuel to kinetic energy when the vehicle accelerates (i.e. KineticEnergyGained/ChemicalEnergyConsumed). ChemicalEnergyConsumed is obtained by converting consumed fuel to chemical energy using fuelEnergyDensityInMJoulesPerLiter.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withAccelerationEfficiency:(double)accelerationEfficiency;
    
/**
 @param decelerationEfficiency Specifies the efficiency of converting kinetic energy to saved (not consumed) fuel when the vehicle decelerates (i.e. ChemicalEnergySaved/KineticEnergyLost). ChemicalEnergySaved is obtained by converting saved (not consumed) fuel to energy using fuelEnergyDensityInMJoulesPerLiter.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withDecelerationEfficiency:(double)decelerationEfficiency;
    
/**
 @param uphillEfficiency Specifies the efficiency of converting kinetic energy to saved (not consumed) fuel when the vehicle decelerates (i.e. ChemicalEnergySaved/KineticEnergyLost). ChemicalEnergySaved is obtained by converting saved (not consumed) fuel to energy using fuelEnergyDensityInMJoulesPerLiter.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withUphillEfficiency:(double)uphillEfficiency;
    
/**
 @param downhillEfficiency Specifies the efficiency of converting potential energy to saved (not consumed) fuel when the vehicle loses elevation (i.e. ChemicalEnergySaved/PotentialEnergyLost). ChemicalEnergySaved is obtained by converting saved (not consumed) fuel to energy using fuelEnergyDensityInMJoulesPerLiter.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withDownhillEfficiency:(double)downhillEfficiency;
    
/**
 @param currentChargeInkWh Specifies the current electric energy supply in kilowatt hours (kWh).
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withCurrentChargeInkWh:(double)currentChargeInkWh;
    
/**
 @param maxChargeInkWh Specifies the maximum electric energy supply in kilowatt hours (kWh) that may be stored in the vehicle's battery.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withMaxChargeInkWh:(double)maxChargeInkWh;
    
/**
 @param auxiliaryPowerInkW Specifies the maximum electric energy supply in kilowatt hours (kWh) that may be stored in the vehicle's battery.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withAuxiliaryPowerInkW:(double)auxiliaryPowerInkW;
    
/**
 @param avoidVignettes List of 3-character ISO 3166-1 alpha-3 country codes of countries in which all toll roads with vignettes are to be avoided.
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withAvoidVignettes:(NSMutableArray<NSString*>* _Nonnull)avoidVignettes;
    
/**
 @param speedConsumptionInLitersPairs Specifies the speed-dependent component of consumption. Provided as an unordered list of speed/consumption-rate in liters pairs.
 @param count Count of elements TTSpeedConsumption
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withSpeedConsumptionInLitersPairs:(TTSpeedConsumption* _Nonnull)speedConsumptionInLitersPairs count:(NSUInteger)count;
    
/**
 @param speedConsumptionInkWhPairs Specifies the speed-dependent component of consumption. Provided as an unordered list of speed/consumption-rate in kWh pairs.
 @param count Count of elements TTSpeedConsumption
 @return TTRouteQueryBuilder
 */
- (ObjectType _Nonnull) withSpeedConsumptionInkWhPairs:(TTSpeedConsumption* _Nonnull)speedConsumptionInkWhPairs count:(NSUInteger)count;

@end
