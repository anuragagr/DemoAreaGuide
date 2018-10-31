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
#import "TTReachableRangeResult.h"
#import "TTReport.h"

@interface TTReachableRangeResponse : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Format version of response.
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull formatVersion;

/**
 Copyrights.
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull copyright;


/**
 Privacy policy.
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull privacyPolicy;

/**
 List of results. In most situations there is only one result that contains
 multiple boundries.
 */
@property (nonatomic, strong, readonly) TTReachableRangeResult* _Nonnull result;

/**
 Additional data related with request returned from the server.
 */
@property (nonatomic, strong, readonly) TTReport * _Nonnull report;

@end
