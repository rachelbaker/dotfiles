//
//  SFCLIArgumentParser.h
//  SofaFoundation
//
//  Created by Jonathan on 05/01/2011.
//  Copyright 2011 Sofa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>


@interface SFCLIArgumentParser : NSObject {
	@private
	NSSet *mOptionDefinitions;
	char const **mArguments;
	int	mCount;
	BOOL mAllowsNonOptions;
}

- (id)initWithArguments:(char const **)theArguments count:(int)theCount optionDefinitions:(NSSet *)theDefinitions allowsNonOptions:(BOOL)theAllowsNonOptions;

- (NSArray *)parse;

@end
