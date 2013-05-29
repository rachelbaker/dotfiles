//
//  CFCollection+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 23/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

SOFA_FOUNDATION_EXPORT const CFDictionaryKeyCallBacks kSFUniCharDictionaryKeyCallbacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryValueCallBacks kSFUniCharDictionaryValueCallbacks;

SOFA_FOUNDATION_EXPORT const CFArrayCallBacks kSFNSIntegerArrayCallbacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryKeyCallBacks kSFNSIntegerDictionaryKeyCallbacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryValueCallBacks kSFNSIntegerDictionaryValueCallbacks;

SOFA_FOUNDATION_EXPORT const CFArrayCallBacks kSFNSUIntegerArrayCallbacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryKeyCallBacks kSFNSUIntegerDictionaryKeyCallBacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryValueCallBacks kSFNSUIntegerDictionaryValueCallBacks;

SOFA_FOUNDATION_EXPORT const CFArrayCallBacks kSFNSRangeArrayCallbacks;

SOFA_FOUNDATION_EXPORT const CFArrayCallBacks kSFCFIndexArrayCallbacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryKeyCallBacks kSFCFIndexDictionaryKeyCallbacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryValueCallBacks kSFCFIndexDictionaryValueCallbacks;

SOFA_FOUNDATION_EXPORT const CFArrayCallBacks kSFBOOLArrayCallBacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryKeyCallBacks kSFBOOLDictionaryKeyCallBacks;
SOFA_FOUNDATION_EXPORT const CFDictionaryValueCallBacks kSFBOOLDictionaryValueCallBacks;

typedef BOOL (*SFArrayComparisonFunction)(const void * /*arrayA*/, NSUInteger /*indexA*/, const void * /*arrayB*/, NSUInteger /*indexB */, void * /*context*/);

SOFA_FOUNDATION_EXPORT NSUInteger SFArrayLengthOfCommonPrefix(const void *arrayA, NSRange theRangeA, const void *arrayB, NSRange theRangeB, SFArrayComparisonFunction theComparisonFunction, void *theContext);

SOFA_FOUNDATION_EXPORT NSUInteger SFArrayLengthOfCommonSuffix(const void *arrayA, NSRange theRangeA, const void *arrayB, NSRange theRangeB, SFArrayComparisonFunction theComparisonFunction, void *theContext);
