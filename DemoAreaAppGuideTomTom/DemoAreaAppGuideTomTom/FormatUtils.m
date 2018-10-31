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

#import "FormatUtils.h"

@interface TimeDelay : NSObject {

@public
    NSString *value;
    NSString *unit;
    NSString *subValue;
    NSString *subUnit;
    NSString *combinedString;
}

@end

@implementation TimeDelay

- (id)initWithSeconds:(int)seconds {
    if (self = [super init])
    {
        if (seconds >= 3600)
        {
            int        hours = seconds / 3600;
            int        minutes = (seconds % 3600) / 60;

            value = [NSString stringWithFormat:@"%d", hours];
            unit = @"h";
            subValue = [NSString stringWithFormat:@"%d", minutes];
            subUnit = @"m";
        }
        else
        {
            int        minutes = seconds / 60;
            int     sec = (seconds % 60);

            value = [NSString stringWithFormat:@"%d", (minutes > 0 ? minutes : 1)];
            unit = @" min";
            subValue = [NSString stringWithFormat:@"%d", sec];
            subUnit = @" s";
        }

        if (subValue)
        {
            combinedString = [NSString stringWithFormat:@"%@%@ %@%@", value, unit, subValue, subUnit];
        }
        else
        {
            combinedString = [NSString stringWithFormat:@"%@%@", value, unit];
        }
    }

    return self;
}

@end

@interface TimeRemainingPieces : NSObject {
    
@public
    NSString *value;
    NSString *unit;
    NSString *subValue;
    NSString *subUnit;
    NSString *combinedString;
}

@end

@implementation TimeRemainingPieces

- (id)initWithSeconds:(int)seconds {
    if (self = [super init])
    {
        if (seconds >= 86400)
        {
            int		days = seconds / 86400;
            int		hours = (seconds % 86400) / 3600;
            
            value = [NSString stringWithFormat:@"%d", days];
            unit = @"d";
            subValue = [NSString stringWithFormat:@"%d", hours];
            subUnit = @"h";
        }
        else if (seconds >= 3600)
        {
            int		hours = seconds / 3600;
            int		minutes = (seconds % 3600) / 60;
            
            value = [NSString stringWithFormat:@"%d", hours];
            unit = @"h";
            subValue = [NSString stringWithFormat:@"%d", minutes];
            subUnit = @"m";
        }
        else
        {
            int		minutes = seconds / 60;

            value = [NSString stringWithFormat:@"%d", (minutes > 0 ? minutes : 1)];
            unit = @" min";
        }
        
        if (subValue)
        {
            combinedString = [NSString stringWithFormat:@"%@%@ %@%@", value, unit, subValue, subUnit];
        }
        else
        {
            combinedString = [NSString stringWithFormat:@"%@%@", value, unit];
        }
    }
    
    return self;
}

@end

@interface ArrivalTimePieces : NSObject {
    
@public
    NSString *timeString;
    NSRange	dataRange;
}

@end

@implementation ArrivalTimePieces

- (id)initWithSeconds:(int)seconds {
    if (self = [super init])
    {
        NSDate				*arrivalTime = [NSDate dateWithTimeIntervalSinceNow:seconds];
        NSDateFormatter		*formatter = [[NSDateFormatter alloc] init];
        
        [formatter setDateStyle:NSDateFormatterNoStyle];
        [formatter setTimeStyle:NSDateFormatterShortStyle];
        timeString = [formatter stringFromDate:arrivalTime];
        dataRange = [timeString rangeOfString:[formatter AMSymbol]];
        
        if (dataRange.location == NSNotFound)
        {
            dataRange = [timeString rangeOfString:[formatter PMSymbol]];
        }
        
        if (dataRange.location != NSNotFound)
        {
            dataRange = NSMakeRange(0, dataRange.location);
        }
    }
    
    return self;
}

@end

@interface DistancePieces : NSObject {
    
@public
    NSString *value;
    NSString *unit;
    NSString *combined;
}

@end

@implementation DistancePieces

- (id)initWithMeters:(int)meters imperial:(BOOL)imperial {
    if (self = [super init])
    {
        float	fValue = 0;
        int		iValue = 0;
        
        if (imperial)
        {
            float	feet = meters * 3.28084f;
            
            if (feet <= 500)
            {
                iValue = (int)ceilf(feet);
                unit = @"ft";
            }
            else
            {
                float	miles = feet / 5280.0f;
                
                fValue = miles;
                unit = @"mi";
            }
        }
        else
        {
            if (meters <= 500)
            {
                iValue = (meters > 0) ? meters : 1;
                unit = @"m";
            }
            else
            {
                float	km = meters / 1000.0f;
                
                fValue = km;
                unit = @"km";
            }
        }
        
        if (fValue != 0.0f)
        {
            static NSNumberFormatter	*formatter = nil;
            
            if (!formatter)
            {
                formatter = [[NSNumberFormatter alloc] init];
                [formatter setMaximumFractionDigits:1];
                [formatter setMinimumIntegerDigits:1];
                [formatter setUsesGroupingSeparator:YES];
                [formatter setGroupingSize:3];
            }
            
            value = [formatter stringFromNumber:[NSNumber numberWithFloat:fValue]];
        }
        else
        {
            value = [NSString stringWithFormat:@"%d", iValue];
        }
        
        combined = [NSString stringWithFormat:@"%@ %@", value, unit];
    }
    
    return self;
}

@end

@implementation FormatUtils

+ (NSString *)formatTimeRemaining:(int)seconds {
    TimeRemainingPieces		*pieces = [[TimeRemainingPieces alloc] initWithSeconds:seconds];
    
    return pieces->combinedString;
}

+ (NSString *)formatArrivalTime:(int)seconds {
    ArrivalTimePieces	*pieces = [[ArrivalTimePieces alloc] initWithSeconds:seconds];
    
    return pieces->timeString;
}

+ (NSString *)formatDistance:(int)meters imperial:(BOOL)imperial {
    DistancePieces	*pieces = [[DistancePieces alloc] initWithMeters:meters imperial:imperial];
    
    return pieces->combined;
}

+ (NSString *)formatTimeDelay:(int)seconds {
    TimeDelay        *pieces = [[TimeDelay alloc] initWithSeconds:seconds];

    return pieces->combinedString;
}

+ (NSAttributedString *)formatTimeRemaining:(UILabel *)label seconds:(int)seconds {
    NSMutableAttributedString	*result = nil;
    UIFont						*boldFont = [UIFont boldSystemFontOfSize:[label.font pointSize]];
    TimeRemainingPieces			*pieces = [[TimeRemainingPieces alloc] initWithSeconds:seconds];
    
    result = [[NSMutableAttributedString alloc] initWithString:pieces->combinedString];
    [result addAttribute:NSFontAttributeName value:boldFont range:NSMakeRange(0, [pieces->value length])];
    
    if (pieces->subValue)
    {
        [result addAttribute:NSFontAttributeName value:boldFont range:NSMakeRange([pieces->value length] + 2, [pieces->subValue length])];
    }
    
    return result;
}

+ (NSAttributedString *)formatArrivalTime:(UILabel *)label seconds:(int)seconds {
    NSMutableAttributedString	*result;
    ArrivalTimePieces			*pieces = [[ArrivalTimePieces alloc] initWithSeconds:seconds];
    
    result = [[NSMutableAttributedString alloc] initWithString:pieces->timeString];
    [result addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:[label.font pointSize]] range:pieces->dataRange];
    
    return result;
}

+ (NSAttributedString *)formatDistance:(UILabel *)label meters:(int)meters imperial:(BOOL)imperial {
    NSMutableAttributedString	*result = nil;
    DistancePieces				*pieces = [[DistancePieces alloc] initWithMeters:meters imperial:imperial];
    
    result = [[NSMutableAttributedString alloc] initWithString:pieces->combined];
    [result addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:[label.font pointSize]] range:NSMakeRange(0, [pieces->value length])];
    
    return result;
}

+ (NSAttributedString *)formatText:(UILabel *)label text:(NSString *)text {
    NSMutableAttributedString	*result = nil;
    UIFont						*boldFont = [UIFont boldSystemFontOfSize:[label.font pointSize]];
    
    result = [[NSMutableAttributedString alloc] initWithString:text];
    [result addAttribute:NSFontAttributeName value:boldFont range:NSMakeRange(0, [text length])];
    
    return result;
}

@end
