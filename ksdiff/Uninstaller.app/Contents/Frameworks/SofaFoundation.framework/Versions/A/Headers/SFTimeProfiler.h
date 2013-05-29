//
//  SFProfiling.h
//  SofaFoundation
//
//  Created by Jonathan on 06/06/2010.
//  Copyright 2010 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SFTimeProfiler : NSObject {
	@private
	NSString		*mName;
	NSDate			*mStart;
	NSTimeInterval	mDuration;
	NSUInteger		mNormalizationFactor;
}
@property (readonly, nonatomic, copy) NSString *name;
@property (readonly, nonatomic, assign) NSTimeInterval duration;
@property (readwrite, nonatomic, assign) NSUInteger normalizationFactor;
@property (readonly, nonatomic) NSTimeInterval normalizedDuration;

- (void)beginProfile;
- (void)endProfile;

#if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
- (void)timeProfileUsingBlock:(void (^)(void))theBlock;
- (void)timeProfileIterations:(NSUInteger)theCount usingBlock:(void (^)(void))theBlock;
#endif // (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6) && NS_BLOCKS_AVAILABLE
@end
