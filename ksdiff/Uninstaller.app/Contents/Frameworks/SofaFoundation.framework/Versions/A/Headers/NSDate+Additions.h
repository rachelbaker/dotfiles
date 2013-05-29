//
//  NSDate_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 02/02/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSDate (SFAdditions)
 */
@interface NSDate (SFAdditions)
- (NSInteger)second;
- (NSInteger)minute;
- (NSInteger)hour;
- (NSInteger)day;
- (NSInteger)week;
- (NSInteger)weekday;
- (NSInteger)month;
- (NSInteger)year;

- (NSComparisonResult)compareDay:(NSDate *)date;
- (BOOL)isEqualToDayOfDate:(NSDate *)date;

- (NSComparisonResult)compareWeek:(NSDate *)date;
- (BOOL)isEqualToWeekOfDate:(NSDate *)date;

- (NSComparisonResult)compareMonth:(NSDate *)date;
- (BOOL)isEqualToMonthOfDate:(NSDate *)date;

- (NSDate *)dateByAddingSeconds:(NSInteger)seconds;
- (NSDate *)dateByAddingMinutes:(NSInteger)minutes;
- (NSDate *)dateByAddingHours:(NSInteger)hours;
- (NSDate *)dateByAddingDays:(NSInteger)days;
- (NSDate *)dateByAddingWeeks:(NSInteger)weeks;
- (NSDate *)dateByAddingMonths:(NSInteger)months;
- (NSDate *)dateByAddingYears:(NSInteger)years;

- (NSInteger)differenceInMinutes:(NSDate *)date;
@end
