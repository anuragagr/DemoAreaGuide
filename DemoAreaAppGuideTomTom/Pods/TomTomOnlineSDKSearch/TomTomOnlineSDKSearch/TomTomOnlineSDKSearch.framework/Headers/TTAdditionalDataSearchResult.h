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
#import "TTADPGeoJsonObjectVisitor.h"


/**
 Class containing the result
 */
@interface TTAdditionalDataSearchResult : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Resoult Id
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull Id;

/**
 Description of error
 */
@property (nonatomic, strong, readonly) NSString * _Nullable error;

/**
 Method allows to visit geo json structure that was returned.

 @param visitor Object type TTADPGeoJsonObjectVisitor
 */
- (void)visitResult:(id<TTADPGeoJsonObjectVisitor> _Nonnull)visitor;

@end
