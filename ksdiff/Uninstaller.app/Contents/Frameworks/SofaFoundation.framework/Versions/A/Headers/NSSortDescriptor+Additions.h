//
//  NSSortDescriptor_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 20/08/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSSortDescriptor (SFAdditions)
 */
@interface NSSortDescriptor (SFAdditions)

/** Creates and returns a sort descriptor for the given key
 @return An autoreleased sort descriptor.
 @param theKey The property key to use when performing a comparison. In the comparison, the property is accessed using key-value coding.
 @param theAscendingFlag YES if the receiver specifies sorting in ascending order, otherwise NO.
 */
+ (NSSortDescriptor *)sortDescriptorWithKey:(NSString *)theKey ascending:(BOOL)theAscendingFlag;

/** Creates and returns a sort descriptor for the given key
 @return An autoreleased sort descriptor.
 @param theKey The property key to use when performing a comparison. In the comparison, the property is accessed using key-value coding.
 @param theAscendingFlag YES if the receiver specifies sorting in ascending order, otherwise NO.
 @param theSelector A custom comparison selector
 */
+ (NSSortDescriptor *)sortDescriptorWithKey:(NSString *)theKey ascending:(BOOL)theAscendingFlag selector:(SEL)theSelector; 
@end
