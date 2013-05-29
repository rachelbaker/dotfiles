//
//  SFPrivilegedExecutableOperation.h
//  SofaFoundation
//
//  Created by Pieter de Bie on 5/19/10.
//  Copyright 2010 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/SFOperation.h>

// This operation allows you to execute commands with root privileges.
// This is done by wrapping the Authorization framework in an SFOperation,
// allowing you to run the command async, or sync by waiting for the operation.

// To do this correctly, the command being run needs to work together with this task
// by providing its own PID. This is necessary in order to wait on the correct child
// task inside the operation, as the Authorization framework does not provide a
// way to get the PID of the launched task. This is done with the following 'interface':

// The first output on the STDOUT of the process has to be in the form of
//
// "PID: <PID>\n"
//
// That is, the string "PID:", followed by a space, followed by the PID of
// child process, and then followed by a newline. In a shell script, this
// can be done easily by adding:
//
// echo "PID: $$"
//
// as the first line of the script.

// Any data sent to the STDOUT of the child after this interface will
// end up in the 'processOutput' property of this task. Information sent
// to the STDERR won't be stored; it will just disappear or end up in the
// console.

// Any errors encountered while executing the command or parsing the output
// will end up in the 'errorMessage' property; if this property is nil
// after the task has finished, no errors were encountered. The child
// process itself may have exited with an error status though; you can
// check this with the 'exitCode' property. This property has no meaning
// if 'errorMessage' is set.

@interface SFPrivilegedExecutableOperation : SFOperation 
{
	AuthorizationRef mAuthorization;
	BOOL 			 mShouldFreeAuthorization;
	NSError 		 *mError;
	
	NSString 		 *mExecutablePath;
	NSArray 		 *mArguments;

	NSData			 *mProcessOutput;
	int 			 mExitCode;
}

@property (copy) NSString *executablePath;
@property (retain) NSArray *arguments;
@property (assign) int exitCode;
@property (readonly, retain) NSError *error;
@property (readonly, retain) NSData *processOutput;

// Use this if you already have an Authorization to be used.
- (id)initWithAuthorization:(AuthorizationRef)theAuthorization executablePath:(NSString *)theExecutablePath arguments:(NSArray *)theArguments;

// Use this if this is one-shot and you don't need the authorization for anything else.
- (id)initWithExecutablePath:(NSString *)theExecutablePath arguments:(NSArray *)theArguments;

@end