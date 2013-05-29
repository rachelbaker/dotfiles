//
//  NSAttributedString_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 02/02/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSAttributedString (SFAdditions)
 */
@interface NSAttributedString (SFAdditions)

/** Creates an attributed string.
 @return An autoreleased attributed string.
 */
+ (id)attributedString;

/** Creates an attributed string with the provided string.
 @return An autoreleased attributed string.
 @param string An NSString instance.
 */
+ (id)attributedStringWithString:(NSString *)string;

/** Creates an attributed string with the given string and attributes.
 @return An autoreleased attributed string.
 @param attributes The attributes for the attributed string.
 @param string An NSString instance.
 */
+ (id)attributedStringWithString:(NSString *)string withAttributes:(NSDictionary *)attributes;

/** Prepends the given string to the receiver.
 @return An autoreleased attributed string.
 @param string An NSString instance.
 */
- (NSAttributedString *)attributedStringByPrependString:(NSString *)string;

/** Appends the given string to the receiver.
 @return An autoreleased attributed string.
 @param string An NSString instance.
 */
- (NSAttributedString *)attributedStringByAppendingString:(NSString *)string;

@end

/**
 @category NSMutableAttributedString (SFAdditions)
 */
@interface NSMutableAttributedString (SFAdditions)

/** Appends the given string to the receiver.
 @param string An NSString instance.
 */
- (void)appendString:(NSString *)string;

/** Appends the given string with attributes to the receiver.
 @param string An NSString instance.
 @param attributes The attributes for the appended string.
 */
- (void)appendString:(NSString *)string withAttributes:(NSDictionary *)attributes;

/** Prepends the given string to the receiver.
 @param string An NSString instance.
 */
- (void)prependString:(NSString *)string;

/** Inserts the given string with attributes at the given index in the receiver.
 @param string An NSString instance.
 @param attributes The attributes for the inserted string.
 @param index The index at which to insert in the receiver.
 */
- (void)insertString:(NSString *)string withAttributes:(NSDictionary *)attributes atIndex:(NSUInteger)index;

@end
