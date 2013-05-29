//
//  CFArray+Additions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 23/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

SOFA_FOUNDATION_EXPORT CFArrayRef SFArrayCreateSubarrayWithRange(CFAllocatorRef theAllocator, CFArrayRef array, CFRange theRange);