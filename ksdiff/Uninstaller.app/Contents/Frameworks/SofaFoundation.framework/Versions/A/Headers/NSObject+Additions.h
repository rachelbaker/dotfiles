//
//  NSObject_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 21/02/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

// When thowing an exception in the initializer we need the @finally block to ensure memory is cleaned up. return nil is outside the @finally so we can work with assertions in tests properly. If we want to assert that an initializer (commonly -init) raises, the assert macro needs to handle the exception _before_ we return. Otherwise @finally is executed, we return nil, the test fails, _then_ the assertion handles the exception that would pass the test. Re-read the exception handling guide, rethrowing exceptions in-particular has very sublte bahaviours.
#ifndef SF_NOT_DESIGNATED_INITIALIZER
#define SF_NOT_DESIGNATED_INITIALIZER(theDesigantedInitializerSelector) \
@try { \
	[NSException raise:NSGenericException format:@"%@ is not the designated initializer of class, %@. Instead call %@", NSStringFromSelector(_cmd), [self class], NSStringFromSelector((theDesigantedInitializerSelector))]; \
} \
@finally { \
	[self release]; \
} \
return nil;
#endif // SF_NOT_DESIGNATED_INITIALIZER

/**
 @category NSObject (SFAdditions)
 */
@interface NSObject (SFAdditions)
/** Raises an exception that informs the developer that the method should be implemented by subclasses. Useful when writing abstract classes.
 @param theSelector A selector to be implemented by subclasses.
 */
- (void)subclassShouldImplementSelector:(SEL)theSelector;
@end

/**
 @category NSObject (SFKVONotification)
 */
@interface NSObject (SFKVONotification)

/** Registers observer to receive KVO notifications for the specified key-path relative to the receiver.
 @param observer The object to receive key-value change notifications.
 @param keyPath The key path, relative to the receiver, of the property to observe. This value must not be nil.
 @param selector The selector, implemented by the observer, which will be invoked when changes occurr.
 @param userInfo A dictionary used to pass context information when selector is invoked. Use an NSNumber keyed by SFKVONotificationNotifyOnMainThreadKey to force callbacks to be invoked on the main thread only (useful when observing properties on NSOperation).
 @param options A combination of the NSKeyValueObservingOptions values that specifies what is included in observation notifications.
 */
- (void)addObserver:(id)observer forKeyPath:(NSString *)keyPath selector:(SEL)selector userInfo:(NSDictionary *)userInfo options:(NSKeyValueObservingOptions)options;

/** Stops the observer from receiving change notifications for the property specified by a given key-path relative to the receiver.
 @param observer The object to remove as an observer.
 @param keyPath A key-path, relative to the receiver, for which observer is registered to receive KVO change notifications.
 @param selector The selector, implemented by observer, which was specified when registering.
 */
- (void)removeObserver:(id)observer forKeyPath:(NSString *)keyPath selector:(SEL)selector;

//#if (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
///** Registers observer to receive KVO notifications for the specified key-path relative to the receiver.
// @param observer The object to receive key-value change notifications.
// @param keyPath The key path, relative to the receiver, of the property to observe. This value must not be nil.
//main thread only (useful when observing properties on NSOperation).
// @param options A combination of the NSKeyValueObservingOptions values that specifies what is included in observation notifications.
// @param theQueue The queue on thich the block will be invoked.
// @param theBlock The callback block for the observation.
// */
//- (id <NSObject, NSCopying>)addObserver:(id)theObserver forKeyPath:(NSString *)theKeyPath options:(NSKeyValueObservingOptions)theOptions queue:(NSOperationQueue *)theQueue block:(void (^)(NSDictionary * /* change */))theBlock AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
//
///** Unregistered an observation represented by theObserver. Unregistration is exact.
// @param theObserver The object returned when registration occurred.
// */
//- (void)removeObserver:(id <NSObject, NSCopying>)theObserver AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
//#endif // (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE

@end

@interface NSObject (SFForwarding)
- (id)forwardingTargetForSelector:(SEL)aSelector;
@end
