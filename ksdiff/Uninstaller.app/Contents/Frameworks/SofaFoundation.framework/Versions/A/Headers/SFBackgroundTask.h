//
//  SFBackgroundTask.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 07/12/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SFOperation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

@class SFSemaphore;

@protocol SFBackgroundTaskOperation;

@protocol SFBackgroundTask <NSObject> // See SFBackgroundTask for a concrete implementation
- (void)main;
- (void)stop DEPRECATED_ATTRIBUTE;
- (void)finish;
- (void)cancel;
@property (readwrite, assign, getter = isCancelled) BOOL cancelled;
@property (readonly, assign) BOOL requiresRunLoop;

// The task may exceed the lifetime of the operation. In those cases,
// messaging to the weakly referenced operation would message a zombie.
// Therefore, all access to the operation MUST be done through a @synchronized
// on the task.
@property (readwrite, assign) SFOperation <SFBackgroundTaskOperation> *operation;

@optional
- (void)waitUntilFinished;

@end

@interface SFBackgroundTask : NSObject <SFBackgroundTask>

@end
