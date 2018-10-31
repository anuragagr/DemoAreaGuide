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

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>
#import "TTSearchShape.h"
#import "TTSearchTypes.h"


@interface TTGeometrySearchQuery : NSObject

@end

@interface TTGeometrySearchQueryBuilder : NSObject

+ (TTGeometrySearchQueryBuilder* _Nonnull)createWithTerm:(NSString * _Nonnull)term searchShapes:(NSArray<TTSearchShape*>* _Nonnull)shapes;
- (TTGeometrySearchQueryBuilder* _Nonnull)withLimit:(NSUInteger)limit;
- (TTGeometrySearchQueryBuilder* _Nonnull)withLanguage:(TTLanguage)language;
- (TTGeometrySearchQueryBuilder* _Nonnull)withExtendedPostalCodeFor:(TTSearchIndex)index;
- (TTGeometrySearchQueryBuilder* _Nonnull)withIdxSet:(TTSearchIndex)index;
- (TTGeometrySearchQuery* _Nonnull)build;

@end
