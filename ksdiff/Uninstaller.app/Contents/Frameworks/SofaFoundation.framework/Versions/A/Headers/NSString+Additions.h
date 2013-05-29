//
//  NSString_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 14/01/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/CFString+Additions.h>
#import <SofaFoundation/SFRange.h>

// These match those in CFStringTokenizer+Additions
enum {
	SFStringEnumerationSubstringNotRequired = 1UL << 9,
	SFStringEnumerationTokenizeLineBreaks = 1UL << 20,
	SFStringEnumerationIncludeWhitespace = 1UL << 30
};
typedef NSUInteger SFStringEnumerationOptions;

typedef void (*SFStringEnumerationFunction)(NSString */*substring*/, NSRange /*range*/, NSUInteger /*index*/, BOOL */*stop*/, void */*context*/);

SOFA_FOUNDATION_EXPORT NSString *const SFEmptyString;

#ifndef SF_STRING_GET_CHAR
#define SF_STRING_GET_CHAR(theString, theIndex) CFStringGetCharacterAtIndex((CFStringRef)(theString), (theIndex))
#endif // SF_STRING_GET_CHAR

#ifndef SFFORMAT
#define SFFORMAT(args...) [NSString stringWithFormat:args]
#endif // SFFORMAT

/**
	Abstraction for range manipulations when calculating the range of lines.
	@param theString The string for which we want to find the line range.
	@param theRange The range over which we want to calculate the line bounds.
	@param theContentsRange A pointer to an NSRange, on return it contains the line range not including the line terminators.
	@returns The line bounds enclosing |theRange|. The line range may exceed the bounds of |theRange|.
 */
NS_INLINE NSRange SFStringLineRangeForRange(NSString *theString, NSRange theRange, NSRange *theContentsRange)
 {
	CFIndex aLineBeginIndex = 0;
	CFIndex aLineEndIndex = 0;
	CFIndex aContentsEndIndex = 0;
	CFStringGetLineBounds((CFStringRef)theString, SFNSRangeToCFRange(theRange), &aLineBeginIndex, &aLineEndIndex, (theContentsRange == NULL ? NULL : &aContentsEndIndex));
	if (theContentsRange != NULL) {
		*theContentsRange = NSMakeRange((NSUInteger)aLineBeginIndex, (NSUInteger)(aContentsEndIndex - aLineBeginIndex));
	}
	return NSMakeRange((NSUInteger)aLineBeginIndex, (NSUInteger)(aLineEndIndex - aLineBeginIndex));
}

/**
 @category NSString (SFAdditions)
 */
@interface NSString (SFAdditions)
/**
	Creates a new (autoreleased) NSString from the given data for the given encoding.
	@param theData The string as NSData.
	@param theEncoding The encoding of the string.
	@returns A new (autoreleased) NSString. Returns nil if initialization fails.
 */
+ (NSString *)stringWithData:(NSData *)theData encoding:(NSStringEncoding)theEncoding;


/**
	Determines if the string consists of only whitespace. Raises an NSInvalidArgumentException if the length of the receiver is 0.
	@returns YES if the string consists of only whitespace characters.
 */
- (BOOL)isWhitespace;

/**
	Strips the receiver of whitespace.
	@returns A representation of the receiver with whitespace stripped.
 */
- (NSString *)stringByStrippingWhitespace;


/**
	Prepends |thePrefix| to the receiver.
	@param thePrefix The prefix to prepend.
	@returns A representation of the receiver |thePrefix| prepended. 
 */
- (NSString *)stringByPrependingString:(NSString *)thePrefix;

- (NSString *)stringByReplacingNewlinesWithSpaces;

#pragma mark -
#pragma mark File Paths

// For furture reference: esure the args in |SFARRAY(args)| are never surrounded by a second pair of parentheses. For example |SFARRAY((args))| This will produce incorrect results.
// Usage: SFFILEPATH(@"Users", @"Jonathan", @"Desktop") evaluates to @"Users/Jonathan/Desktop" at runtime.
#ifndef SFFILEPATH
#define SFFILEPATH(args...) [NSString pathWithComponents:SFARRAY(args)]
#endif // SFFILEPATH

- (NSString *)pathByAppendingPath:(NSString *)thePath;
- (NSString *)absolutePathByAppendingRelativePath:(NSString *)theRelativePath;

/**
	Searches the receiver for |theString| starting from |theIndex|.
	@param theString The string to search for.
	@param theIndex The index in the receiver from which to start the search.
	@returns The range of |theString| in terms of the receiver. If not found, the range will have a location of NSNotFound.
 */
- (NSRange)rangeOfString:(NSString *)theString startingIndex:(NSUInteger)theIndex;


/**
	Extracts a substring from the receiver between the given indices.
	@param theFromIndex The starting index for the substring.
	@param theToIndex The ending index for the substring.
	@returns A substring of the receiver.
 */
- (NSString *)substringBetweenIndex:(NSUInteger)theFromIndex andIndex:(NSUInteger)theToIndex;


#pragma mark -
#pragma mark Line Ranges

/**
	Returns the ranges of lines in the recevier.
	@param theCount A pointer to an NSUInteger. On return, the length of the array of NSRanges.
	@returns An array of line ranges as NSRange structs.
 */
- (NSRange *)getLineRanges:(NSUInteger *)theCount;

/**
	Returns the ranges of lines in the recevier for the supplied range.
	@param theRange The range over which to find the line ranges.
	@param theCount A pointer to an NSUInteger. On return, the length of the array of NSRanges.
	@returns An array of line ranges as NSRange structs. The first and last elements may exceed the bounds of |theRange|.
 */
- (NSRange *)getLineRangesInRange:(NSRange)theRange count:(NSUInteger *)theCount;


// TODO: DEPRECATE the methods that return an NSPointerArray in favour of those that return NSRange *
- (NSPointerArray *)lineRanges;
- (NSPointerArray *)lineRangesInRange:(NSRange)range;

/**
	Retuns the range of the given line number.
	@param theLineNumber The line number to search for.
	@returns The line range for |theLineNumber|, SFNotFoundRange if the line number exceeds the number of lines in the receiver.
 */
- (NSRange)rangeOfLine:(NSUInteger)theLineNumber;

/**
	The number of lines in the receiver. Found by counting line breaks.
	@returns The number of lines.
 */
- (NSUInteger)numberOfLines;

/**
	The number of lines in the receiver. Found by counting line breaks over the supplied range.
	@param theRange The range over which to count the lines.
	@returns The number of lines in |theRange|
 */
- (NSUInteger)numberOfLinesInRange:(NSRange)theRange;

- (NSRange)lineNumberRangeInRange:(NSRange)theCharacterRange;

- (void)enumerateLinesWithOptions:(SFStringEnumerationOptions)theOptions function:(SFStringEnumerationFunction)theFunction context:(void *)theContext;
- (void)enumerateLinesInRange:(NSRange)theRange options:(SFStringEnumerationOptions)theOptions function:(SFStringEnumerationFunction)theFunction context:(void *)theContext;


#pragma mark -
#pragma mark Word Ranges

- (void)enumerateWordsInRange:(NSRange)theRange options:(SFStringEnumerationOptions)theOptions function:(SFStringEnumerationFunction)theFunction context:(void *)theContext;

- (CFStringTokenizerRef)wordBoundaryTokenizer;
- (CFStringTokenizerRef)wordTokenizer;

- (NSPointerArray *)wordRangesForRange:(NSRange)theCharacterRange tokenizer:(CFStringTokenizerRef)theWordBoundaryTokenizer DEPRECATED_ATTRIBUTE;
- (NSRange *)getWordRangesForRange:(NSRange)theRange includeWhitespace:(BOOL)theIncludeWhitespaceFlag count:(NSUInteger *)theCount;
- (NSUInteger)numberOfWordsInRange:(NSRange)theRange DEPRECATED_ATTRIBUTE;
- (NSUInteger)numberOfWordsInRange:(NSRange)theRange includeWhitespace:(BOOL)theIncludeWhitespaceFlag;

#pragma mark -
#pragma mark Comparisons

- (NSComparisonResult)numericalCompare:(NSString *)string;
- (NSComparisonResult)finderCompare:(NSString *)string AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_6;

- (NSUInteger)lengthOfCommonPrefixWithString:(NSString *)theString;
- (NSRange)rangeOfCommonPrefixWithString:(NSString *)theString;

- (NSUInteger)lengthOfCommonSuffixWithString:(NSString *)theString;
- (NSRange)rangeOfCommonSuffixWithString:(NSString *)theString;

//#if (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
//- (void)enumerateCharactersUsingBlock:(void (^)(unichar /* char */, NSUInteger /* index */, BOOL * /* stop */))theBlock AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
//- (void)enumerateCharactersWithOptions:(SFStringEnumerationOptions)theOptions usingBlock:(void (^)(unichar /* char */, NSUInteger /* index */, BOOL * /* stop */))theBlock AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
//#endif // (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE

#pragma mark -
#pragma mark KeyPaths

#ifndef SFKEYPATH
#define SFKEYPATH(args...) [NSString keyPathWithComponents:args, nil]
#endif

+ (NSString *)keyPathWithComponents:(NSString *)theKey1, ... NS_REQUIRES_NIL_TERMINATION;

#pragma mark -
#pragma mark URL Escaping

- (NSString *)URLEscapedString;

@end


/**
 @category NSMutableString (SFAdditions)
 */
@interface NSMutableString (SFAdditions)
/** Strips all whitespace characters from the receiver.
 */
- (void)stripWhitespace;
@end
