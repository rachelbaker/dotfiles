//
//  SFGeometry.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 21/07/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

//	CGRect functions apdapted from KDGeometry.h (Amber Framework)
//  Created by Keith Duncan on 12/06/2007.
//  Copyright 2007 Keith Duncan. All rights reserved.


#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/SFMath.h>

#pragma mark -
#pragma mark CGRect

NS_INLINE CGPoint SFRectCenter(CGRect theRect) {
	return CGPointMake(CGRectGetMidX(theRect), CGRectGetMidY(theRect));	
}

NS_INLINE CGRect SFRectWithPointAndSize(CGPoint thePoint, CGSize theSize) {
	return CGRectMake(thePoint.x, thePoint.y, theSize.width, theSize.height);
}

NS_INLINE CGRect SFRectWithSize(CGSize theSize) {
	return CGRectMake(0.0, 0.0, theSize.width, theSize.height);
}

NS_INLINE CGRect SFRectFromCenterPoint(CGPoint thePoint, CGSize theSize) {
    return CGRectMake(thePoint.x - theSize.width / 2.0, thePoint.y - theSize.height / 2.0, theSize.width, theSize.height);	
}

NS_INLINE CGRect SFSquareFromCenterPoint(CGPoint thePoint, CGFloat theSide) {
	return SFRectFromCenterPoint(thePoint, CGSizeMake(theSide, theSide));
}

NS_INLINE CGRect SFSizeCenteredInRect(CGSize theSize, CGRect theFrame) {
	return CGRectInset(theFrame, (CGRectGetWidth(theFrame) - theSize.width) / 2.0, (CGRectGetHeight(theFrame) - theSize.height) / 2.0);
}

NS_INLINE CGRect SFSquareCenteredInRect(CGFloat theSquareSize, CGRect theFrame) {
	return CGRectInset(theFrame, (CGRectGetWidth(theFrame) - theSquareSize) / 2.0, (CGRectGetHeight(theFrame) - theSquareSize) / 2.0);
}

NS_INLINE CGRect SFRectFromPoints(CGPoint theStartPoint, CGPoint theEndPoint) {
	CGFloat x, y, width, height;
	if (theStartPoint.x < theEndPoint.x) {
		x = theStartPoint.x;
		width = theEndPoint.x-theStartPoint.x;
	} else {
		x = theEndPoint.x;
		width = theStartPoint.x - theEndPoint.x;
	}
	
	if (theStartPoint.y < theEndPoint.y) {
		y = theStartPoint.y; 
		height = theEndPoint.y - theStartPoint.y;
	} else {
		y = theEndPoint.y;
		height = theStartPoint.y - theEndPoint.y;
	}
	return CGRectMake(x, y, width, height);
}

NS_INLINE CGRect SFRectArrayUnion(CGRect *array, NSUInteger theLength) {
	if (theLength == 0)
		return CGRectNull;
	CGRect aUnionRect = array[0];
	for (NSUInteger anIndex = 1 ; anIndex < theLength ; anIndex++)
		aUnionRect = CGRectUnion(aUnionRect, array[anIndex]);
	return aUnionRect;
}

struct SFPadding {
	CGFloat minX;
	CGFloat maxX;
	CGFloat minY;
	CGFloat maxY;
};
typedef struct SFPadding SFPadding;

SOFA_FOUNDATION_EXPORT const SFPadding SFPaddingZero;

NS_INLINE SFPadding SFPaddingMake(CGFloat theMinX, CGFloat theMaxX, CGFloat theMinY, CGFloat theMaxY) {
	SFPadding aPadding;
	aPadding.minX = theMinX;
	aPadding.maxX = theMaxX;
	aPadding.minY = theMinY;
	aPadding.maxY = theMaxY;
	return aPadding;
} 

NS_INLINE CGRect SFRectApplyPadding(CGRect theRect, SFPadding thePadding) {
	CGRect aPaddedRect = theRect;
	aPaddedRect.origin.x += thePadding.minX;
	aPaddedRect.size.width -= (thePadding.minX + thePadding.maxX);
	aPaddedRect.origin.y += thePadding.minY;
	aPaddedRect.size.height -= (thePadding.minY + thePadding.maxY);
	return aPaddedRect;
}

enum {
	SFCartesianDimensionX = 1 << 0,
	SFCartesianDimensionY = 1 << 1
};
typedef NSUInteger SFCartesianDimension;

NS_INLINE BOOL SFRectContainsRectInDimension(CGRect theRect, CGRect theOtherRect, SFCartesianDimension theDimensionMask) {
	if (	(theDimensionMask & SFCartesianDimensionX) > 0
		&&	(theDimensionMask & SFCartesianDimensionY) > 0)
		return CGRectContainsRect(theRect, theOtherRect);
	BOOL aContainsRect = NO;
	if ((theDimensionMask & SFCartesianDimensionX) > 0)
		aContainsRect = (CGRectGetMinX(theRect) <= CGRectGetMinX(theOtherRect) && CGRectGetMaxX(theOtherRect) <= CGRectGetMaxX(theRect));
	if ((theDimensionMask & SFCartesianDimensionY) > 0)
		aContainsRect = (CGRectGetMinY(theRect) <= CGRectGetMinY(theOtherRect) && CGRectGetMaxY(theOtherRect) <= CGRectGetMaxY(theRect));
	return aContainsRect;
}

NS_INLINE BOOL SFRectContainsPointInDimension(CGRect theRect, CGPoint thePoint, SFCartesianDimension theDimensionMask) {
	if (	(theDimensionMask & SFCartesianDimensionX) > 0
		&&	(theDimensionMask & SFCartesianDimensionY) > 0)
		return CGRectContainsPoint(theRect, thePoint);
	BOOL aContainsPoint = NO;
	if ((theDimensionMask & SFCartesianDimensionX) > 0)
		aContainsPoint = (CGRectGetMinX(theRect) <= thePoint.x && thePoint.x <= CGRectGetMaxX(theRect));
	if ((theDimensionMask & SFCartesianDimensionY) > 0)
		aContainsPoint = (CGRectGetMinY(theRect) <= thePoint.y && thePoint.y <= CGRectGetMaxY(theRect));
	return aContainsPoint;
}

NS_INLINE BOOL SFRectContainsOrdinateInDimension(CGRect theRect, CGFloat theOrdinate, SFCartesianDimension theDimension) {
	BOOL aContainsOrdinate = NO;
	if (theDimension == SFCartesianDimensionX)
		aContainsOrdinate = (CGRectGetMinX(theRect) <= theOrdinate && theOrdinate <= CGRectGetMaxX(theRect));
	if (theDimension == SFCartesianDimensionY)
		aContainsOrdinate = (CGRectGetMinY(theRect) <= theOrdinate && theOrdinate <= CGRectGetMaxY(theRect));
	return aContainsOrdinate;
}

NS_INLINE CGPoint SFConstrainPointToRectInDimension(CGPoint theProposedPoint, CGRect theRect, SFCartesianDimension theDimensionMask) {
	CGPoint aConstrainedPoint = theProposedPoint;
	if ((theDimensionMask & SFCartesianDimensionX) > 0)
		aConstrainedPoint.x = SFConstrainFloat(aConstrainedPoint.x, CGRectGetMinX(theRect), CGRectGetMaxX(theRect));
	if ((theDimensionMask & SFCartesianDimensionY) > 0)
		aConstrainedPoint.y = SFConstrainFloat(aConstrainedPoint.y, CGRectGetMinY(theRect), CGRectGetMaxY(theRect));
	return aConstrainedPoint;
}

NS_INLINE CGPoint SFConstrainPointToRect(CGPoint theProposedPoint, CGRect theRect) {
	return SFConstrainPointToRectInDimension(theProposedPoint, theRect, (SFCartesianDimensionX|SFCartesianDimensionY));
}

NS_INLINE CGRect SFRectFitToRectInDimension(CGRect theRect, CGRect theTargetRect, SFCartesianDimension theDimensionMask) {
	CGRect aFittedRect = theRect;
	if ((theDimensionMask & SFCartesianDimensionX) > 0) {
		aFittedRect.origin.x = CGRectGetMinX(theTargetRect);
		aFittedRect.size.width = CGRectGetWidth(theTargetRect);
	}
	if ((theDimensionMask & SFCartesianDimensionY) > 0) {
		aFittedRect.origin.y = CGRectGetMinY(theTargetRect);
		aFittedRect.size.height = CGRectGetHeight(theTargetRect);
	}
	return aFittedRect;
}

enum {
	SFMinXEdge = 1 << 0,
	SFMaxXEdge = 1 << 1,
	SFMinYEdge = 1 << 2,
	SFMaxYEdge = 1 << 3
};
typedef NSUInteger SFRectEdge;

#pragma mark -
#pragma mark CGSize

NS_INLINE CGSize SFConstrainSize(CGSize theProposedSize, CGSize theMinSize, CGSize theMaxSize) {
	CGSize aConstrainedSize = theProposedSize;
	aConstrainedSize.width = SFConstrainFloat(aConstrainedSize.width, theMinSize.width, theMaxSize.width);
	aConstrainedSize.height = SFConstrainFloat(aConstrainedSize.height, theMinSize.height, theMaxSize.height);
	return aConstrainedSize;
}

NS_INLINE CGSize SFSizeScale(CGSize theSize, CGFloat theScaleFactor) {
	return CGSizeMake(theSize.width * theScaleFactor , theSize.height * theScaleFactor);
}

#pragma mark -
#pragma mark CGPoint

NS_INLINE CGPoint SFPointOffset(CGPoint thePoint, CGFloat theXOffset, CGFloat theYOffset) {
	CGPoint anOffsetPoint = thePoint;
	anOffsetPoint.x += theXOffset;
	anOffsetPoint.y += theYOffset;
	return anOffsetPoint;
}

