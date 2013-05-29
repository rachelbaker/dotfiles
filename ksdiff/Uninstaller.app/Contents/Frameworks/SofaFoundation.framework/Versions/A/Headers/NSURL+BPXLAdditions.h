//
//  NSURL+BPXLAdditions.h
//  SofaFoundation
//
//  Created by Doug Russell on 7/7/12.
//  Copyright (c) 2012 Black Pixel. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *BPXLURLAdditionsOneComponentFormatPrettyQuoted;
extern NSString *BPXLURLAdditionsOneComponentFormatRegular;
extern NSString *BPXLURLAdditionsTwoComponentFormatPrettyQuotedIn;
extern NSString *BPXLURLAdditionsOneComponentTwoComponentFormatParenthesis;

@interface NSURL (BPXLAdditions)

- (id)bpxl_fileResourceIdentifier:(NSError **)error;
- (id)bpxl_fileResourceIdentifier;
- (bool)bpxl_isEqualToFileURL:(NSURL *)target;
- (bool)bpxl_urlIsInTrashFolder;

- (NSURL *)bpxl_URLByStrippingQuery;

// This should become and instance method or be rewritten to indicate that it requires the input array have two URLs in it
+ (NSUInteger)bpxl_divergentPathComponentIndexForURLs:(NSArray *)urls;

- (NSString *)bpxl_displayNameOrFilesystemNameForLastPathComponent;
- (NSString *)bpxl_displayNameOrFilesystemNameForPathComponent:(NSUInteger)pathComponentIndex;
- (NSString *)bpxl_displayNameAccountingForDivergentComponentWithOthersURLs:(NSArray *)urls oneComponentFormat:(NSString *)oneComponentFormat twoComponentFormat:(NSString *)twoComponentFormat;

+ (NSArray *)bpxl_displayNamesForDivergentComponentsOfURLs:(NSArray *)urls;

@end
