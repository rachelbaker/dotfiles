//
//  CFStringTokenizer+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 10/12/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

enum {
	SFStringTokenizerEnumerationSubstringNotRequired = 1UL << 9
};
typedef NSUInteger SFStringTokenizerEnumerationOptions;

typedef void (*SFStringTokenizerEnumerationFunction)(CFStringRef /*tokenString*/, CFRange /*tokenRange*/, NSUInteger /*tokenNumber*/, BOOL */*stop*/, void */*context*/);

SOFA_FOUNDATION_EXPORT void SFStringTokenizerEnumerateTokensInRange(CFStringTokenizerRef theTokenizer, CFStringRef theSourceString, CFRange theRange, SFStringTokenizerEnumerationOptions theOptions, SFStringTokenizerEnumerationFunction theFunctionPtr, void *theContext);

SOFA_FOUNDATION_EXPORT void SFStringTokenizerEnumerateTokens(CFStringTokenizerRef theTokenizer, CFStringRef theSourceString, SFStringTokenizerEnumerationFunction theFunctionPtr, void *theContext);

//#if NS_BLOCKS_AVAILABLE
//SOFA_FOUNDATION_EXPORT void SFStringTokenizerEnumerateTokensInRangeUsingBlock(CFStringTokenizerRef theTokenizer, CFStringRef theSourceString, CFRange theRange, SFStringTokenizerEnumerationOptions theOptions, void (^theBlock)(CFStringRef /*tokenString*/, CFRange /*tokenRange*/, NSUInteger /*tokenNumber*/, BOOL */*stop*/));
//#endif // NS_BLOCKS_AVAILABLE

SOFA_FOUNDATION_EXPORT NSPointerArray *SFTokenizerTokenRangesForRange(CFStringTokenizerRef theTokenizer, CFRange theRange);
