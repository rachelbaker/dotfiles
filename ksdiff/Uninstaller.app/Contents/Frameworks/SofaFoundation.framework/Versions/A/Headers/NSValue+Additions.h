//
//  NSValue+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 28/03/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSValue (SFAdditions)
 */
@interface NSValue (SFAdditions)

/** Compares the location of a given value (containing an NSRange) to the rangeValue.location of the receiver.
 @return An NSComparisonResult.
 @param value An NSValue containing and NSRange.
 */
- (NSComparisonResult)compareRangeValueLocation:(NSValue *)value;

/** Create an NSValue for the given CGRect.
 @return An instance of NSValue.
 @param rect A CGRect to wrap in an NSValue.
 */
- (id)initWithRect:(CGRect)rect;

/** Create an NSValue for the given NSRange.
 @return An instance of NSValue.
 @param range A NSRange to wrap in an NSValue.
 */
- (id)initWithRange:(NSRange)range;

/** Create an NSValue for the given CGSize.
 @return An instance of NSValue.
 @param size A CGSize to wrap in an NSValue.
 */
- (id)initWithSize:(CGSize)size;

/** Create an NSValue for the given CGPoint.
 @return An instance of NSValue.
 @param point A CGPoint to wrap in an NSValue.
 */
- (id)initWithPoint:(CGPoint)point;
@end
