//
//  NSPointerFunctions_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 01/05/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSPointerFunctions (SFAdditions)
 */
@interface NSPointerFunctions (SFAdditions)

/** Returns pointer functions suitable for describing NSRange structures.
 @return An NSPointerFunctions instance that describes NSRange structures.
 */
+ (NSPointerFunctions *)pointerFunctionsForNSRange;

/** Returns pointer functions suitable for describing CGRect structures.
 @return An NSPointerFunctions instance that describes CGRect structures.
 */
+ (NSPointerFunctions *)pointerFunctionsForCGRect;

/** Returns pointer functions suitable for describing CGPoint structures.
 @return An NSPointerFunctions instance that describes CGPoint structures.
 */
+ (NSPointerFunctions *)pointerFunctionsForCGPoint;

/** Returns pointer functions suitable for describing CGSize structures.
 @return An NSPointerFunctions instance that describes CGSize structures.
 */
+ (NSPointerFunctions *)pointerFunctionsForCGSize;
@end
