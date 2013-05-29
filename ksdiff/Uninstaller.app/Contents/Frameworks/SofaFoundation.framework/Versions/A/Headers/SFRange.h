//
//  SFRange.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 20/07/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

SOFA_FOUNDATION_EXPORT const NSRange SFZeroRange;
SOFA_FOUNDATION_EXPORT const NSRange SFNotFoundRange;
SOFA_FOUNDATION_EXPORT NSString *SFNSStringFromCFRange(CFRange theRange);
SOFA_FOUNDATION_EXPORT BOOL SFEqualCFRanges(CFRange theRange1, CFRange theRange2);

NS_INLINE BOOL SFRangeIsSubrangeOfRange(NSRange theRange, NSRange thePotentialEnclosingRange) {
	return (NSLocationInRange(theRange.location, thePotentialEnclosingRange) && NSMaxRange(theRange) <= NSMaxRange(thePotentialEnclosingRange));
}

NS_INLINE BOOL SFRangeIntersectsRange(NSRange theRange, NSRange theOtherRange) {
	return (NSLocationInRange(theRange.location, theOtherRange) || NSLocationInRange(theOtherRange.location, theRange));
}

NS_INLINE NSRange SFOffsetRange(NSRange theRange, NSInteger theLocationOffset) {
	NSCParameterAssert((NSInteger)theRange.location + theLocationOffset >= 0);
	NSInteger aLocation = ((NSInteger)theRange.location + theLocationOffset);
	theRange.location = (aLocation > 0) ? (NSUInteger)aLocation : 0;
	return theRange;
}

NS_INLINE NSRange SFExtendRange(NSRange theRange, NSInteger theRangeExtension) {
	NSCParameterAssert((NSInteger)theRange.length + theRangeExtension >= 0);
	NSInteger aLength = ((NSInteger)theRange.length + theRangeExtension);
	theRange.length = (aLength > 0) ? (NSUInteger)aLength : 0;
	return theRange;
}

NS_INLINE CFRange SFNSRangeToCFRange(NSRange theRange) {
	CFIndex aLocation = (theRange.location == NSNotFound) ? kCFNotFound : (CFIndex)theRange.location;
	return CFRangeMake(aLocation, (CFIndex)theRange.length);
}

NS_INLINE NSRange SFNSRangeFromCFRange(CFRange theRange) {
	NSUInteger aLocation = (theRange.location <= kCFNotFound) ? NSNotFound : (NSUInteger)(MAX(0, theRange.location));
	return NSMakeRange(aLocation, (NSUInteger)MAX(0, theRange.length));
}

NS_INLINE CFIndex SFCFRangeMax(CFRange theRange) {
	return (theRange.location + theRange.length);
}
