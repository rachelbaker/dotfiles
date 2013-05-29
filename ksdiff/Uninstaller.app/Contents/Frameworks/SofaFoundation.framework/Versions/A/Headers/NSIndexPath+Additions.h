//
//  NSIndexPath_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 05/05/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

/**
 @category NSIndexPath (SFAdditions)
 */
@interface NSIndexPath (SFAdditions)

/** Returns an empty NSIndexPath.
 @return An autoreleased empty NSIndexPath
 */
+ (NSIndexPath *)indexPath;

/** Returns the first index of the receiver.
 @return An index.
 */
- (NSUInteger)firstIndex;

/** Returns the last index of the receiver.
 @return An index.
 */
- (NSUInteger)lastIndex;

/** Returns a new index path by incrementing the last index of receiver.
 @return An autoreleased index path.
 */
- (NSIndexPath *)indexPathByIncrementingLastIndex;

- (NSIndexPath *)indexPathByReplacingIndexAtPosition:(NSUInteger)position withIndex:(NSUInteger)index;

//#if (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
//
//enum {
//	SFIndexPathEnumerationReverse = 0
//};
//typedef NSUInteger SFIndexPathEnumerationOptions;
//
//- (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger /* indexNumber */, NSUInteger /* indexValue */, BOOL * /* stop */))theBlock;
//- (void)enumerateIndexesWithOptions:(SFIndexPathEnumerationOptions)theOptions usingBlock:(void (^)(NSUInteger /* indexNumber */, NSUInteger /* indexValue */, BOOL * /* stop */))theBlock;
//#endif // (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
@end
