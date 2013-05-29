//
//  NSOperationQueue_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 08/11/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSOperationQueue (SFAdditions)
 */
@interface NSOperationQueue (SFAdditions)

/** Returns an NSOperationQueue.
 @return An autoreleased NSOperationQueue instance.
 // DEPRECATED. Use +concurrentQueue instead
 */
+ (instancetype)operationQueue DEPRECATED_ATTRIBUTE;

/** Returns an NSOperationQueue.
 @return An autoreleased NSOperationQueue instance.
 */
+ (instancetype)concurrentQueue;

/** Returns an NSOperationQueue which allows a single operation to execute at a time.
 @return An autoreleased NSOperationQueue instance which allows a single operation at a time.
 */
+ (instancetype)serialQueue;

@end
