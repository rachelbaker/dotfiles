//
//  NSCalendar_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 02/02/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSCalendar (SFAdditions)
 */
@interface NSCalendar (SFAdditions)
- (NSDate *)dateByAddingSeconds:(NSInteger)seconds toDate:(NSDate *)date;
- (NSDate *)dateByAddingMinutes:(NSInteger)minutes toDate:(NSDate *)date;
- (NSDate *)dateByAddingHours:(NSInteger)hours toDate:(NSDate *)date;
- (NSDate *)dateByAddingDays:(NSInteger)days toDate:(NSDate *)date;
- (NSDate *)dateByAddingWeeks:(NSInteger)weeks toDate:(NSDate *)date;
- (NSDate *)dateByAddingMonths:(NSInteger)months toDate:(NSDate *)date;
- (NSDate *)dateByAddingYears:(NSInteger)years toDate:(NSDate *)date;
@end
