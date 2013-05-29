//
//  NSPointerArray_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 22/05/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSPointerArray (SFAdditions)
 */
@interface NSPointerArray (SFAdditions)

//#if NS_BLOCKS_AVAILABLE
//- (void)enumeratePointersUsingBlock:(void (^)(NSUInteger /* index */, void * /* pointer */, BOOL * /* stop */))theBlock;
//#endif // NS_BLOCKS_AVAILABLE

/** Creates and returns an NSPointerArray suitable for storing pointers to NSRange structures
 @return An autoreleased NSPointerArray instance suitable for storing pointers to NSRange structures.
 */
+ (id)rangePointerArray;

/** Returns an NSRange at the given index.
 @return An NSRange structure.
 @param theIndex An index within the bounds of the receiver.
 */
- (NSRange)rangeAtIndex:(NSUInteger)theIndex;

/** Appends an NSRange to the receiver.
 @param theRange The NSRange structure to add to the receiver.
 */
- (void)addRange:(NSRange)theRange;

/** Creates and returns an NSPointerArray suitable for storing pointers to CGRect structures
 @return An autoreleased NSPointerArray instance suitable for storing pointers to CGRect structures.
 */
+ (id)rectPointerArray;

/** Returns an CGRect at the given index.
 @return An CGRect structure.
 @param theIndex An index within the bounds of the receiver.
 */
- (CGRect)rectAtIndex:(NSUInteger)theIndex;

/** Appends an CGRect to the receiver.
 @param theRect The CGRect structure to add to the receiver.
 */
- (void)addRect:(CGRect)theRect;

/** Creates and returns an NSPointerArray suitable for storing pointers to CGPoint structures
 @return An autoreleased NSPointerArray instance suitable for storing pointers to CGPoint structures.
 */
+ (id)pointPointerArray;

/** Returns an CGPoint at the given index.
 @return An CGPoint structure.
 @param theIndex An index within the bounds of the receiver.
 */
- (CGPoint)pointAtIndex:(NSUInteger)theIndex;

/** Appends an CGPoint to the receiver.
 @param thePoint The CGPoint structure to add to the receiver.
 */
- (void)addPoint:(CGPoint)thePoint;

/** Creates and returns an NSPointerArray suitable for storing pointers to CGSize structures
 @return An autoreleased NSPointerArray instance suitable for storing pointers to CGSize structures.
 */
+ (id)sizePointerArray;

/** Returns an CGSize at the given index.
 @return An CGSize structure.
 @param theIndex An index within the bounds of the receiver.
 */
- (CGSize)sizeAtIndex:(NSUInteger)theIndex;

/** Appends an CGSize to the receiver.
 @param theSize The CGSize structure to add to the receiver.
 */
- (void)addSize:(CGSize)theSize;

@end
