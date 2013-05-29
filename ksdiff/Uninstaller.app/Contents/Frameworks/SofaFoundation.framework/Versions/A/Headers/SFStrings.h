//
//  SFStrings.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 23/09/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

SOFA_FOUNDATION_EXPORT NSString *const SFArrangedObjectsKey;

SOFA_FOUNDATION_EXPORT NSString *const SFSelectionIndexKey;
SOFA_FOUNDATION_EXPORT NSString *const SFSelectionIndexesKey;
SOFA_FOUNDATION_EXPORT NSString *const SFSelectionIndexPathsKey;
SOFA_FOUNDATION_EXPORT NSString *const SFSelectionKey;

SOFA_FOUNDATION_EXPORT NSString *const SFRepresentedObjectKey;

SOFA_FOUNDATION_EXPORT NSString *const SFViewKey;
SOFA_FOUNDATION_EXPORT NSString *const SFFrameKey;
SOFA_FOUNDATION_EXPORT NSString *const SFBoundsKey;
SOFA_FOUNDATION_EXPORT NSString *const SFAlphaValueKey;
SOFA_FOUNDATION_EXPORT NSString *const SFTransformKey;
SOFA_FOUNDATION_EXPORT NSString *const SFAnchorPointKey;
SOFA_FOUNDATION_EXPORT NSString *const SFHiddenKey;

SOFA_FOUNDATION_EXPORT NSString *const SFContentKey;
SOFA_FOUNDATION_EXPORT NSString *const SFContentArrayKey;
SOFA_FOUNDATION_EXPORT NSString *const SFContentSetKey;
// NSObjectController is not KVC-compliant for @"contentObject", but it does have an NSContentObjectBinding. When observing the content of an NSObjectController, don't be tempted to use "contentObject" or SFContentObjectKey. Instead observe the @"content" using SFContentKey.
//SOFA_FOUNDATION_EXPORT NSString *const SFContentObjectKey;
SOFA_FOUNDATION_EXPORT NSString *const SFContentArrayForMultipleSelectionKey;

SOFA_FOUNDATION_EXPORT NSString *const SFFilterPredicateKey;

SOFA_FOUNDATION_EXPORT NSString *const SFSortDescriptorsKey;

SOFA_FOUNDATION_EXPORT NSString *const SFEditableKey;

SOFA_FOUNDATION_EXPORT NSString *const SFEnabledKey;

SOFA_FOUNDATION_EXPORT NSString *const SFManagedObjectContextKey;

SOFA_FOUNDATION_EXPORT NSString *const SFIsFinishedKey;
SOFA_FOUNDATION_EXPORT NSString *const SFIsExecutingKey;

SOFA_FOUNDATION_EXPORT NSString *const SFUserDefaultsValuesKey;
