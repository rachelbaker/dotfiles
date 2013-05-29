//
//  SFSystemConfiguration.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 16/12/2009.
//  Copyright 2009 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>
#import <SystemConfiguration/SystemConfiguration.h>

SOFA_FOUNDATION_EXPORT CFStringRef SFCopyPrimaryMACAddress(void);
SOFA_FOUNDATION_EXPORT CFStringRef SFCopyMACAddressWithBSDName(CFStringRef theBSDName);

SOFA_FOUNDATION_EXPORT CFArrayRef SFCopyNetworkInterfacesWithType(CFStringRef theType);
