//
//  NSDateComponents_Extensions.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 02/02/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @category NSDateComponents (SFAdditions)
 */
@interface NSDateComponents (SFAdditions)
- (NSComparisonResult)components:(NSCalendarUnit)flags compare:(NSDateComponents *)components;
- (BOOL)components:(NSCalendarUnit)flags match:(NSDateComponents *)components;
@end
