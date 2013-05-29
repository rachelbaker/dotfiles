//
//	SofaFoundationMacros.h
//	SofaFoundation
//
//	Created by Jonathan Dann on 27/08/2008.
//	Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#ifndef SOFA_FOUNDATION_EXPORT
#define SOFA_FOUNDATION_EXPORT extern
#endif

// In the case that we're compiling against the 10.5 SDK, we need to define this as the 10.6 SDK does.
#ifndef MAC_OS_X_VERSION_10_6
#define MAC_OS_X_VERSION_10_6 1060
#endif

// In the case that we're compiling against the 10.5 SDK, we need to define this as the 10.6 SDK does.
// Note that this requires the definition of MAC_OS_X_VERSION_10_6
#ifndef AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_6
#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6
#define AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_6    DEPRECATED_ATTRIBUTE
#else
#define AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_6    AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER
#endif
#endif

#ifndef SF_DISPATCH_RUNTIME_AVAILABLE
#define SF_DISPATCH_RUNTIME_AVAILABLE (dispatch_async != NULL)
#endif // SF_DISPATCH_RUNTIME_AVAILABLE

// Determining if it's running on 10.6 or later is based on the availability of the dispatch_async function.
#ifndef SF_RUNNING_ON_10_6_OR_LATER
#define SF_RUNNING_ON_10_6_OR_LATER SF_DISPATCH_RUNTIME_AVAILABLE
#endif // SF_RUNNING_ON_10_6_OR_LATER

// Determining if it's running on 10.7 or later is based on the NSAppKitVersionNumber that gets linked 
#ifndef NSAppKitVersionNumber10_7
#define NSAppKitVersionNumber10_7 1110
#endif

#ifndef SF_RUNNING_ON_10_7_OR_LATER
#define SF_RUNNING_ON_10_7_OR_LATER ((BOOL)(floor(NSAppKitVersionNumber) >= NSAppKitVersionNumber10_7))
#endif // SF_RUNNING_ON_10_7_OR_LATER

#ifndef NSAppKitVersionNumber10_8
#define NSAppKitVersionNumber10_8 1187
#endif

#ifndef SF_RUNNING_ON_10_8_OR_LATER
#define SF_RUNNING_ON_10_8_OR_LATER ((BOOL)(floor(NSAppKitVersionNumber) >= NSAppKitVersionNumber10_8))
#endif // SF_RUNNING_ON_10_8_OR_LATER


// In the case that we're compiling against the 10.5 SDK, we need to define this as the 10.6 SDK does.
#ifndef __has_feature
#define __has_feature(x) 0     // Compatibility with non-clang compilers.
#endif

// In the case that we're compiling against the 10.5 SDK, we need to define this as the 10.6 SDK does.
#ifndef NS_RETURNS_RETAINED
#if __has_feature(attribute_ns_returns_retained)
#define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))
#else
#define NS_RETURNS_RETAINED
#endif
#endif

// In the case that we're compiling against the 10.5 SDK, we need to define this as the 10.6 SDK does.
#ifndef CF_RETURNS_RETAINED
#if __has_feature(attribute_cf_returns_retained)
#define CF_RETURNS_RETAINED __attribute__((cf_returns_retained))
#else
#define CF_RETURNS_RETAINED
#endif
#endif

// If the analyzer warns of a unused result after an assignment, you can silence it using this macro. 
#ifndef SF_DEAD_STORE
#define SF_DEAD_STORE __attribute__((unused))
#endif

#ifndef GETIMP
#define GETIMP(object, sel) [object methodForSelector:sel]
#endif

#ifndef CALLIMP
#define CALLIMP(imp, object, sel, args...) (*imp)(object, sel , args)
#endif

#ifndef SFARRAY
#define SFARRAY(args...) [NSArray arrayWithObjects:args, nil]
#endif

#ifndef SFSET
#define SFSET(args...) [NSSet setWithObjects:args, nil]
#endif

#ifndef SFDICTIONARY
#define SFDICTIONARY(args...) [NSDictionary dictionaryWithObjectsAndKeys:args, nil]
#endif

NS_INLINE BOOL SFEqualSelectors(SEL theSel1, SEL theSel2) {
#if OBJC_API_VERSION >= 2
	return sel_isEqual(theSel1, theSel2);
#else
	return theSel1 == theSel2;
#endif
}

SOFA_FOUNDATION_EXPORT NSString *SFStringFromBOOL(BOOL theBOOL);

typedef void * _SFKVOContext;

#ifndef SF_KVO_CONTEXT
#define SF_KVO_CONTEXT(x) static _SFKVOContext x = (_SFKVOContext)@#x
#endif

/* The reason for the do/whiles in these macros:

 http://cocoawithlove.com/2009/10/memory-and-thread-safe-custom-property.html
 
 "do/whiles are common constructs about any macro that isn't a simple statement. 
 
 The following code: 
 if (i > 0) NonatomicCopySetToFrom(a,b) else a = b;
 
 would not work as expected without the do/while because the else would bind to the nearest "if" (the one *inside* the macro) not the visible "if"."
 
 May be a little contrived for the following macros, but debugging such an issue would be a giant pain. Better to be safe.
 */

#ifndef SF_NONATOMIC_SETTER_RETAIN
#define SF_NONATOMIC_SETTER_RETAIN(ivar, new) \
	do { \
		if (ivar != new) { \
			[ivar release]; \
			ivar = [new retain]; \
		} \
	} while(0)
#endif

#ifndef SF_NONATOMIC_SETTER_COPY
#define SF_NONATOMIC_SETTER_COPY(ivar, new) \
	do { \
		if (ivar != new) { \
			[ivar release]; \
			ivar = [new copy]; \
		} \
	} while(0)
#endif

#ifndef SF_NONATOMIC_SETTER_MUTABLE_COPY
#define SF_NONATOMIC_SETTER_MUTABLE_COPY(ivar, new) \
	do { \
		if (ivar != new) { \
			[ivar release]; \
			ivar = [new mutableCopy]; \
		} \
	} while(0)
#endif

#ifndef SF_AUTORELEASE_POOL_LOOP_START
#define SF_AUTORELEASE_POOL_LOOP_START(var) NSAutoreleasePool *(var) = [[NSAutoreleasePool alloc] init]
#endif

#ifndef SF_AUTORELEASE_POOL_LOOP_RESTART
#define SF_AUTORELEASE_POOL_LOOP_RESTART(var) { [(var) drain]; (var) = [[NSAutoreleasePool alloc] init]; }
#endif

#ifndef SF_AUTORELEASE_POOL_LOOP_END
#define SF_AUTORELEASE_POOL_LOOP_END(var) [(var) drain]
#endif

#ifndef SF_AUTORELEASE_POOL_LOOP_CONTINUE
#define SF_AUTORELEASE_POOL_LOOP_CONTINUE(var) { SF_AUTORELEASE_POOL_LOOP_RESTART((var)); continue; }
#endif

#ifndef SFLog
	#ifdef SF_DEBUG
	#define SFLog(format, ...) NSLog(format, ## __VA_ARGS__)
	#else
	#define SFLog(format, ...)
	#endif
#endif

#ifndef SF_BIT_COUNT
	#define SF_BIT_COUNT(type) CHAR_BIT * sizeof(type)
#endif // SF_BIT_COUNT

#ifndef SF_ROTATE_LEFT
#define SF_ROTATE_LEFT(theValue, theShift) \
	(((theShift) & (SF_BIT_COUNT(__typeof__(theValue)) - 1)) == 0) ? (theValue) : (((theValue) << (theShift)) | ((theValue) >> (SF_BIT_COUNT(__typeof__(theValue)) - (theShift))))
#endif // SF_ROTATE_LEFT

#ifndef SF_ROTATE_RIGHT
#define SF_ROTATE_RIGHT(theValue, theShift) \
	(((theShift) & (SF_BIT_COUNT(__typeof__(theValue)) - 1)) == 0) ? (theValue) : (((theValue) >> (theShift)) | ((theValue) << (SF_BIT_COUNT(__typeof__(theValue)) - (theShift))))
#endif // SF_ROTATE_RIGHT

