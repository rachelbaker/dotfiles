//
//  SFCoding.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 15/08/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SFCoding <NSObject>
- (NSArray *)keysForCoding;
@end
