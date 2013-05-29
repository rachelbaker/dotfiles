//
//  SFCIIStringToken.h
//  SofaFoundation
//
//  Created by Pieter de Bie on 7/29/10.
//  Copyright 2010 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/SFCLIToken.h>

@interface SFCLIStringToken : SFCLIToken <NSCopying> {
	@private
	char *mCString;
}

- (id)initWithCString:(char *)theCString;

@property (readonly, nonatomic) NSString *stringValue;
@property (readonly, nonatomic) NSString *filePathValue;

@end
