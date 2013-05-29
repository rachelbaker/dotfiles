//
//  SFCLIOptionToken.h
//  SofaFoundation
//
//  Created by Jonathan on 05/01/2011.
//  Copyright 2011 Sofa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SofaFoundation/SFCLIToken.h>

@class SFCLIOptionDefinition;

@interface SFCLIOptionToken : SFCLIToken <NSCopying> {
	@private
	SFCLIOptionDefinition *mOptionDefinition;
	NSString *mArgument;
}
@property (readonly, nonatomic, copy) SFCLIOptionDefinition *optionDefinition;
@property (readonly, nonatomic, copy) NSString *argument;

+ (id)optionTokenWithOptionDefinition:(SFCLIOptionDefinition *)theOptionDefinition argument:(NSString *)anArgument;
+ (id)optionTokenWithOptionDefinition:(SFCLIOptionDefinition *)theOptionDefinition cStringArgument:(char *)anArgument;
- (id)initWithOptionDefinition:(SFCLIOptionDefinition *)theOptionDefinition argument:(NSString *)anArgument;
- (id)initWithOptionDefinition:(SFCLIOptionDefinition *)theOptionDefinition cStringArgument:(char *)anArgument;
@end
