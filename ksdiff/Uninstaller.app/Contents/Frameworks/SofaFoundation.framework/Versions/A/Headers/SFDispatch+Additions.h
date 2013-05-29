//
//  SFDispatch+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 01/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

#if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
#import <dispatch/dispatch.h>
SOFA_FOUNDATION_EXPORT void sofa_dispatch_semaphore_wait_signal(dispatch_semaphore_t theSemaphore, dispatch_block_t theBlock);
#endif // (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
