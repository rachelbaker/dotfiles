//
//  NSInvocation+BPXLAdditions.h
//
//  Copyright (c) 2012 Black Pixel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSInvocation (BPXLAdditions)

+ (NSInvocation *)bpxl_invocationWithTarget:(id)target selector:(SEL)selector argCount:(NSUInteger)argCount arg0:(void *)arg0 arg1:(void *)arg1 arg2:(void *)arg2 arg3:(void *)arg3 arg4:(void *)arg4;

@end
