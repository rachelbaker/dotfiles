//
//  RunLoopServicingOperation.h
//  RunLoops
//
//  Created by Jonathan Dann on 05/12/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/SFOperation.h>
#import <SofaFoundation/SFBackgroundTask.h>

@protocol SFBackgroundTaskOperation <NSObject>
- (void)finish;
- (void)cancel;
- (void)waitUntilFinished;
@end

@interface SFRunLoopServicingOperation : SFOperation <SFBackgroundTaskOperation> {
@private
	CFRunLoopRef				wRunLoop;
	NSThread					*mThread;
	id <SFBackgroundTask>		mTask;
	BOOL						mTaskIsFinished;
}
@property (readonly, retain) id <SFBackgroundTask> task;
+ (id)operationWithTask:(id <SFBackgroundTask>)theTask;
- (id)initWithTask:(id <SFBackgroundTask>)theTask;
@end