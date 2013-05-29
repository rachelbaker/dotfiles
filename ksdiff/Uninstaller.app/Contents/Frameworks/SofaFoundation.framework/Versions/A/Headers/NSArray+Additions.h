//
//  NSArray+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 10/08/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

/**
 @category NSArray (SFAdditions)
 */
@interface NSArray (SFAdditions)
/** Returns a new array containing the objects in the passed in arrays.
 @return An autoreleased NSArray.
 @param array A nil-terminated list of NSArrays.
 @param NS_REQUIRES_NIL_TERMINATION
 */
+ (id)arrayWithObjectsFromArrays:(NSArray *)array, ... NS_REQUIRES_NIL_TERMINATION;

/** Returns a new array concatenated with the provided objects.
 @return An autoreleased NSArray.
 @param theObject A nil-terminated list of objects.
 @param NS_REQUIRES_NIL_TERMINATION
 */
- (id)arrayByAddingObjects:(id)theObject, ... NS_REQUIRES_NIL_TERMINATION;

#if (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
- (id)sf_mapObjectsUsingBlock:(id (^)(id /*object*/, NSUInteger /*index*/, BOOL */*stop*/))block AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
- (id)sf_mapObjectsInRange:(NSRange)range usingBlock:(id (^)(id /*object*/, NSUInteger /*index*/, BOOL */*stop*/))block AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
- (id)sf_mapObjectsUsingBlock:(id (^)(id /*object*/, NSUInteger /*index*/, BOOL */*stop*/))block condition:(BOOL (^)(NSUInteger /*index*/))condition AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
- (id)sf_mapObjectsInRange:(NSRange)range usingBlock:(id (^)(id /*object*/, NSUInteger /*index*/, BOOL */*stop*/))block condition:(BOOL (^)(NSUInteger /*index*/))condition AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
#endif // (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE

- (BOOL)containsObjectIdenticalTo:(id)anObject;

+ (id)sf_nilSafeArrayWithMaxCount:(int)maxCount objects:(id)firstObj, ...;

@end

/**
 @category NSMutableArray (SFAdditions)
 */
@interface NSMutableArray (SFAdditions)
/** Returns a new array containing the objects in the passed in arrays.
 @return An autoreleased NSArray.
 @param array A nil-terminated list of NSArrays.
 @param NS_REQUIRES_NIL_TERMINATION
 */
+ (id)arrayWithObjectsFromArrays:(NSArray *)array, ... NS_REQUIRES_NIL_TERMINATION;

/** Returns a new array containing the objects in the passed in arrays.
 @return An NSMutableArray.
 @param array A nil-terminated list of NSArrays.
 @param NS_REQUIRES_NIL_TERMINATION
 */
- (id)initWithObjectsFromArrays:(NSArray *)array, ... NS_REQUIRES_NIL_TERMINATION;

/** Returns a new array concatenated with the provided objects.
 @return An autoreleased NSArray.
 @param theObject A nil-terminated list of objects.
 @param NS_REQUIRES_NIL_TERMINATION
 */
- (void)addObjects:(id)theObject, ... NS_REQUIRES_NIL_TERMINATION;

@end

/**
 @category NSMutableArray (SFStack)
 */
@interface NSMutableArray (SFStack)
/** Appends an object to the end of the receiver.
 @param theObject The object to append to the array. May be nil.
 */
- (void)push:(id)theObject;

/** Removes and returns the last object in the receiver.
 @return An object or nil if the recevier is empty.
 */
- (id)pop;

/** Determines if the receiver contains no objects.
 @return Returns YES is the count of the receiver is zero, NO otherwise.
 */
- (BOOL)isEmpty;

@end
