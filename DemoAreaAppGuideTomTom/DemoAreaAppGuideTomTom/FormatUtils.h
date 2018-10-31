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
#import <UIKit/UIKit.h>

@interface FormatUtils : NSObject

+ (NSString *)formatTimeRemaining:(int)seconds;
+ (NSString *)formatArrivalTime:(int)seconds;
+ (NSString *)formatDistance:(int)meters imperial:(BOOL)imperial;
+ (NSString *)formatTimeDelay:(int)seconds;

+ (NSAttributedString *)formatTimeRemaining:(UILabel *)label seconds:(int)seconds;
+ (NSAttributedString *)formatArrivalTime:(UILabel *)label seconds:(int)seconds;
+ (NSAttributedString *)formatDistance:(UILabel *)label meters:(int)meters imperial:(BOOL)imperial;
+ (NSAttributedString *)formatText:(UILabel *)label text:(NSString *)text;

@end
