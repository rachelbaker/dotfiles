//
//  SFSemaphore.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 01/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

typedef void * sofa_semaphore_t;

SOFA_FOUNDATION_EXPORT sofa_semaphore_t sofa_semaphore_create(NSInteger theValue);
SOFA_FOUNDATION_EXPORT void sofa_semaphore_release(sofa_semaphore_t theSemaphore);
SOFA_FOUNDATION_EXPORT void sofa_semaphore_wait(sofa_semaphore_t theSemaphore);
SOFA_FOUNDATION_EXPORT void sofa_semaphore_timed_wait(sofa_semaphore_t theSemaphore, int64_t theOffset);
SOFA_FOUNDATION_EXPORT void sofa_semaphore_signal(sofa_semaphore_t theSemaphore);

#if NS_BLOCKS_AVAILABLE
typedef void (^sofa_semaphore_block_t)(void);
SOFA_FOUNDATION_EXPORT void sofa_semaphore_wait_signal(sofa_semaphore_t theSemaphore, sofa_semaphore_block_t theBlock);
#endif // NS_BLOCKS_AVAILABLE

inline static uint64 SFNSecToSec(uint64 theNanoseconds) {
	return theNanoseconds / 1000000000;
}

inline static uint64 SFSecToNSec(uint64 theSeconds) {
	return theSeconds * 1000000000;
}


#pragma mark -

@interface SFSemaphore : NSObject {
	@private
	sofa_semaphore_t mSemaphore;
}
- (id)initWithValue:(NSInteger)theValue;

- (void)wait;
- (void)waitWithTimeout:(uint64)theTimeout; // timeout in nanoseconds; 1 second = 1.000.000.000 nanoseconds
- (void)signal;

#if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
- (void)waitAndSignalUsingBlock:(sofa_semaphore_block_t)theBlock;
#endif // (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
@end
