//
//  NSUserDefaults+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 10/02/2010.
//  Copyright 2010 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

SOFA_FOUNDATION_EXPORT NSString *const SFAppleScrollerPagingBehaviorDefaultsKey;
SOFA_FOUNDATION_EXPORT NSString *const SFAppleScrollAnimationEnabledDefaultsKey;

enum {
	SFScrollPagingBehaviourJumpToNextPage = 0,
	SFScrollPagingBehaviourJumpToClickedPoint = 1
};
typedef NSInteger SFScrollPagingBehaviour;

@interface NSUserDefaults (SFAdditions)
- (SFScrollPagingBehaviour)scrollPagingBehaviour;
- (BOOL)scrollAnimationEnabled;
@end
