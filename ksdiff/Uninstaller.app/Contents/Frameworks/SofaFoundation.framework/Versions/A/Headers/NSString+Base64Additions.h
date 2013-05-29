//
//  NSString+Base64Additions.h
//  SofaFoundation
//
//  Created by Dirk Stoop on 5/18/10.
//  Copyright 2010 Sofa BV. All rights reserved.
//

/*
 
 This code Copyright (c) Dave Dribin, copy/pasted from:
 http://www.cocoadev.com/index.pl?BaseSixtyFour

*/

#import <Foundation/Foundation.h>

@interface NSString (Base64Additions)

- (NSData *)decodeBase64;
- (NSData *)decodeBase64WithNewlines:(BOOL)theEncodedWithNewlinesFlag;

@end