//	Copyright (c) 2007, Keith Duncan and Jonathan Dann
//	All rights reserved.
//
//	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
//	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
//	Neither the name of the thirty-three nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Additions by Jonathan Dann.

#import <Foundation/Foundation.h>

/**
 @category NSObject (AFAdditions)
 */
@interface NSObject (AFAdditions)

/*!
 @brief
 To message a thread, the thread must have a valid runloop.
 */
- (id)syncThreadProxy:(NSThread *)thread;
- (id)asyncThreadProxy:(NSThread *)thread;

/*!
 @brief
 This simply calls <tt>-[NSObject threadProxy:]</tt> using [NSThread mainThread] as an argument.
 Sync messages will be performed synchronously. If async, control returns immediately to caller.
 */
- (id)syncMainThreadProxy;
- (id)asyncMainThreadProxy;

/*!
 @brief
 This creates a background thread and associates the proxy with it.
 Sync messages will be performed synchronously. If async, control returns immediately to caller.
 */

- (id)protocolProxy:(Protocol *)protocol; // Note: only selectors that return true for respondsToSelector: will be forwarded

#ifdef SF_DEBUG // THIS CANNOT BE CANCELLED, SO DON'T PUT IT IN A RELEASE BUILD. THIS IS FOR QUICK TESTING ONLY
- (id)delayedPerformerProxy:(NSTimeInterval)delay;
#endif // SF_DEBUG

- (id)queueProxy:(NSOperationQueue *)operationQueue;
/** Returns a proxy for the reciever. Messages sent to the proxy will be converted into an NSInvocationOperation and executed on the provided operation queue. By passing a reference to an NSInvocationOperation, it is possible to get the return value of the invocation when the operation has completed.
 @return An autoreleased NSProxy subclass.
 @param operationQueue The operation queue on which the invocation operation will be executed
 @param theOperationPtr A reference to the operation that is created and invoked. Pass NULL if you don't need it (for example when you want to perform a void-returning method asynchronously).
 */
- (id)queueProxy:(NSOperationQueue *)operationQueue operation:(NSInvocationOperation **)theOperationPtr;

- (id)invocationProxy:(NSInvocation **)theInvocationPtr;

- (id)invocationOperationProxy:(NSInvocationOperation **)theInvocationOperationPtr;
@end
