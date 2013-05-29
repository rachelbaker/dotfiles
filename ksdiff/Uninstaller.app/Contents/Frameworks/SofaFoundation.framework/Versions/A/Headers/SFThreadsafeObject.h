//
//  SFThreadsafeObject.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 01/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SFSemaphore.h>

@interface SFThreadsafeObject : NSObject {
	@private
	id						mRepresentedObject;
	sofa_semaphore_t		mSynchronizationSemaphore;
	sofa_semaphore_t		mMutationSemaphore;
	NSUInteger				mNumberOfReaders;
	NSMapTable				*mReaderMap;
	NSThread				*mWriterThread;
	NSUInteger				mNumberOfWritesFromCurrentThread;
}
@property (readwrite, retain) id representedObject;

- (id)initWithRepresentedObject:(id)theRepresentedObject;

#if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE

typedef void (^SFThreadsafeObjectTransactionBlock)(id /* representedObject */);

- (void)readTransactionUsingBlock:(SFThreadsafeObjectTransactionBlock)theBlock;
- (void)writeTransactionUsingBlock:(SFThreadsafeObjectTransactionBlock)theBlock;
#endif // (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE

typedef void (*SFThreadsafeObjectTransactionCallBack)(id /* representedObject */, void * /* context */ );

- (void)readTransactionUsingFunction:(SFThreadsafeObjectTransactionCallBack)theFunction context:(void *)theContext;
- (void)writeTransactionUsingFunction:(SFThreadsafeObjectTransactionCallBack)theFunction context:(void *)theContext;

- (void)beginRead;
- (void)endRead;

- (void)beginWrite;
- (void)endWrite;
@end
