//
//  SFKVOContext.h
//  SofaFoundation
//
//  Created by Jonathan on 20/05/2010.
//  Copyright 2010 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

/**
 SFKVOContext is used to provide metadata when invoking KVO-compliant accessors. Observers using SFKVONotification have access to the context object and can retrieve information from it using -valueForKey:.
 
 Usage:
 
 When mutating a KVO-compliant property:
 [SFKVOContext beginTransaction];
 [SFKVOContext setValue:aValue forKey:aKey]; // |aKey| can is an NSString.
 [anObject setThing:];
 [SFKVOContext endTransaction];
 
 After the invocation of -setThing:, observers get their callback:
 
 - (void)thingDidChange:(SFKVONotification *)theNotification;
 {
	SFKVOContext *aContext = [theNotification context]; // |aContext| may be nil if no transaction was created when mutating |thing|
	// inspect |aContext|
	id aValue = [aContext valueForKey:aKey];
	// do whatever you need to.
 }
 
 Notes on usage:
 In the KVO callback, there should be no reason to set more data on the context. It's lifetime is limted to the scope of the +beginTransaction and +endTransaction calls. And in the case that the KVO callback is forwarded to the main thread by the SFKVONotification system there may be more than one thread that has a reference to the context at any one time.
 
 Threadsafety:
 We store a stack of contexts (although it is highly likely there will only be one instance of SFKVOContext in the stack at any one time) which are keyed by the current thread. In this way the context is thread-local. Multiple clients creating transactions from multiple thread for multiple key paths will therefore get the correct context passed back to them in KVO callbacks. Two threads creating a transaction and mutating the same key path of an object will get the correct context passed back to them in the KVO callback. The threadsafety of mutating the key path itself is, of course, up to you.
 Using the SFKVONotification system with the |SFKVONotificationNotifyOnMainThreadKey| is supported as the thread local context is set on the SFKVONotification object before the callback is pushed to the main thread.
 */

@interface SFKVOContext : NSObject {
	@private
	NSMutableDictionary *mStorage;
}
+ (void)beginTransaction;
+ (void)endTransaction;

/**
 
 */
+ (void)setValue:(id)theValue forKey:(NSString *)theKey;

/**
 Returns objects stored under |theKey| when the context was created in a transaction.
 @param theKey The key used to look up objects.
 @returns The object set under |theKey|, or nil.
 */
- (id)valueForKey:(NSString *)theKey;
@end

@interface SFKVOContext (_SFKVONotificationObserver_Friend)
+ (SFKVOContext *)currentContext; // Do not call this yourself. This is only for use in SFKVOContext and _SFKVONotificationObserver
@end
