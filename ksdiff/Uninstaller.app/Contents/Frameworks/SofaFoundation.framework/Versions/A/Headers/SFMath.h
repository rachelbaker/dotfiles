//
//  SFMath.h
//  TextUITest
//
//  Created by Jonathan Dann on 21/09/2009.
//  Copyright 2009 Sofa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <ApplicationServices/ApplicationServices.h>

SOFA_FOUNDATION_EXPORT CGFloat SFAbs(CGFloat theValue);
SOFA_FOUNDATION_EXPORT CGFloat SFRoundToNearestHalfInteger(CGFloat theValue);
SOFA_FOUNDATION_EXPORT CGFloat SFRoundToNearestInteger(CGFloat theValue);
SOFA_FOUNDATION_EXPORT CGFloat SFCeil(CGFloat theValue);
SOFA_FOUNDATION_EXPORT CGFloat SFFloor(CGFloat theValue);
SOFA_FOUNDATION_EXPORT CGFloat SFTrunc(CGFloat theValue);
SOFA_FOUNDATION_EXPORT NSRange SFIntersectionRange(NSRange range1, NSRange range2, BOOL inclusive);
SOFA_FOUNDATION_EXPORT bool SFRectIsZeroOrNull(CGRect theRect);

NS_INLINE CGFloat SFConstrainFloat(CGFloat theProposedValue, CGFloat theMinValue, CGFloat theMaxValue) {
	CGFloat aConstrainedValue = theProposedValue;
	aConstrainedValue = MAX(aConstrainedValue, theMinValue);
	aConstrainedValue = MIN(aConstrainedValue, theMaxValue);
	return aConstrainedValue;
}
