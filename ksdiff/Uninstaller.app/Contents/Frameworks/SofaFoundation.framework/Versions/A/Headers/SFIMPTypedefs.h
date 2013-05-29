//
//  SFIMPTypedefs.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 11/11/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef BOOL (*_SFBOOLIMPFunctionPtr)(id, SEL, ...);

typedef NSRange (*_SFRangeIMPFunctionPtr)(id, SEL, ...);
typedef void (*_SFRangeSetIMPFunctionPtr)(id, SEL, NSRange);

// Example SF_CACHE_RANGE_RETURNING_IMP(NSValue, @selector(rangeValue), aRangeSelector, _RangeFunction)
// ....
// NSRange aRange = _RangeFunction(object, aRangeSelector, NULL);
#ifndef SF_CACHE_RANGE_RETURNING_IMP
#define SF_CACHE_RANGE_RETURNING_IMP(class, selector, selectorLocalVarName, functionLocalVarName) \
SEL selectorLocalVarName = (selector); \
_SFRangeIMPFunctionPtr functionLocalVarName = (_SFRangeIMPFunctionPtr)[class instanceMethodForSelector:selectorLocalVarName];
#endif // SF_CACHE_RANGE_RETURNING_IMP
