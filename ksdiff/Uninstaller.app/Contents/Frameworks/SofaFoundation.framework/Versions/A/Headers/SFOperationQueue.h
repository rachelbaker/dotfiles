//
//  SFOperation.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 08/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/SFBackgroundTask.h>

@class SFRunLoopServicingOperation;

@interface SFOperationQueue : NSOperationQueue

- (SFRunLoopServicingOperation *)addOperationForTask:(id <SFBackgroundTask>)theTask;

@end
