//
//  SFAllocation.h
//  SofaFoundation
//
//  Created by Jonathan on 21/06/2010.
//  Copyright 2010 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

/*
 Increases the length of the array by |theAdditionalLength| if |theUsedLength| is >= |*theTotalLength|
 */
SOFA_FOUNDATION_EXPORT void *SFReallocateIfNeededWithAdditionalLength(void *array, NSUInteger theUsedLength, NSUInteger *theTotalLength, NSUInteger theSizeOfArrayType, NSUInteger theAdditionalLength);

/*
 Increases the length of the array by 64 if |theUsedLength| is >= |*theTotalLength| (for convenience).
 Returns the new pointer to the reallocated array.
 */
SOFA_FOUNDATION_EXPORT void *SFReallocateIfNeeded(void *array, NSUInteger theUsedLength, NSUInteger *theTotalLength, NSUInteger theSizeOfArrayType);
