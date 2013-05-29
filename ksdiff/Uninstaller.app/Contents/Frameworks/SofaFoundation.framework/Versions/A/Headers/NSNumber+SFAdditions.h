//
//  NSNumber+SFAdditions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 22/09/2009.
//  Copyright 2009 Sofa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

/**
 @category NSNumber (SFAdditions)
 */
@interface NSNumber (SFAdditions)

/** Returns an NSNumber object initialized to contain the given value, treated as an CGFloat
 @return An autoreleased NSNumber object containing value, treating it as an CGFloat
 @param cgFloat The value for the new number.
 */
+ (id)numberWithCGFloat:(CGFloat)cgFloat;

/** Returns an NSNumber object initialized to contain the given value, treated as an CGFloat
 @return An NSNumber object containing value, treating it as an CGFloat
 @param cgFloat The value for the new number.
 */
- (id)initWithCGFloat:(CGFloat)cgFloat;

/** Returns the receiver’s value as a CGFloat.
 @return A CGFloat representation of the receiver.
 */
- (CGFloat)CGFloatValue;

@property (readonly) BOOL isUnsigned;
@end
