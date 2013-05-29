//
//  SFCLIOptionDefinition.h
//  SofaFoundation
//
//  Created by Jonathan on 05/01/2011.
//  Copyright 2011 Sofa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <getopt.h>

SOFA_FOUNDATION_EXPORT NSString *const SFCLIOptionDefinitionLongOnlyKey;

enum {
	SFCLIOptionArgumentRequirementNone = no_argument,
	SFCLIOptionArgumentRequirementRequired = required_argument,
	SFCLIOptionArgumentRequirementOptional = optional_argument	
};
typedef int SFCLIOptionArgumentRequirement;

@interface SFCLIOptionDefinition : NSObject <NSCopying> {
	@private
	NSString *mLongOption;
	int mShortOption;
	SFCLIOptionArgumentRequirement mArugmentRequirement;
	BOOL mLongOnly;
}
@property (readonly, nonatomic, copy) NSString *longOption;
@property (readonly, nonatomic, assign) int shortOption;
@property (readonly, nonatomic, assign) SFCLIOptionArgumentRequirement arugmentRequirement;
@property (readonly, nonatomic, assign) BOOL longOnly;

+ (id)optionDefinitionWithLongOption:(NSString *)theLongOption shortOption:(int)theShortOption argumentRequirement:(SFCLIOptionArgumentRequirement)theArugmentRequirement longOnly:(BOOL)theLongOnly;
- (id)initWithLongOption:(NSString *)theLongOption shortOption:(int)theShortOption argumentRequirement:(SFCLIOptionArgumentRequirement)theArugmentRequirement longOnly:(BOOL)theLongOnly;

@property (readonly, nonatomic) struct option optionRepresentation;

@end
