//
//  CFString+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 22/08/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

#ifndef SF_STRING_LENGTH
#define SF_STRING_LENGTH(theString) CFStringGetLength((CFStringRef)(theString))
#endif

#ifndef SF_STRING_BUFFER_GET_CHAR
#define SF_STRING_BUFFER_GET_CHAR(theBufferPtr, theIndex) CFStringGetCharacterFromInlineBuffer((theBufferPtr), theIndex)
#endif


SOFA_FOUNDATION_EXPORT CFIndex SFStringLengthOfCommonPrefixWithString(CFStringRef theString, CFStringRef theOtherString);
SOFA_FOUNDATION_EXPORT CFIndex SFStringLengthOfCommonSuffixWithString(CFStringRef theString, CFStringRef theOtherString);

//#if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
//
//enum {
//	SFStringEnumerationReverse = NSStringEnumerationReverse,
//	SFStringEnumerationCharacterNotRequired = 1UL << 9
//};
//typedef NSUInteger SFStringEnumerationOptions;
//
//SOFA_FOUNDATION_EXPORT void SFStringEnumerateCharactersUsingBlock(CFStringRef theString, void (^theBlock)(unichar /* char */, NSUInteger /* index */, BOOL * /* stop */)) AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
//SOFA_FOUNDATION_EXPORT void SFStringEnumerateCharactersWithOptionsUsingBlock(CFStringRef theString, SFStringEnumerationOptions theOptions, void (^theBlock)(unichar /* char */, NSUInteger /* index */, BOOL * /* stop */)) AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
//
//#endif // (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE

SOFA_FOUNDATION_EXPORT CFStringTokenizerRef SFStringCreateWordBoundaryTokenizer(CFStringRef theString);
SOFA_FOUNDATION_EXPORT CFStringTokenizerRef SFStringCreateWordTokenizer(CFStringRef theString);
SOFA_FOUNDATION_EXPORT NSPointerArray * SFStringWordRangesForCharacterRange(CFStringRef theSourceString, CFRange theCharacterRange, CFStringTokenizerRef theTokenizer) DEPRECATED_ATTRIBUTE;
