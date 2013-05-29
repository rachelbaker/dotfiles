//
//  SFKVONotification.h
//  SofaFoundation
//
//  Created by Jonathan Dann on 06/12/2008.
//  Copyright 2008 Sofa BV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SofaFoundation/SofaFoundationMacros.h>

SOFA_FOUNDATION_EXPORT NSString *const SFKVONotificationNotifyOnMainThreadKey;

@class SFKVOContext;

/*!
 @class SFKVONotification
Instances of SFKVONotification are sent as the argument to custom KVO callbacks. Instances contain all information that is usually passed to observers via -observeValueForKeyPath:ofOject:change:context:.
 */
@interface SFKVONotification : NSObject {
	@private
	id				mObject;
	NSString		*mKeyPath;
	NSDictionary	*mChange;
	id				mUserInfo;
	SFKVOContext	*mContext;
}
/** Returns the observed object.
 
 */
@property(readonly, nonatomic, retain) id object;

/** Returns the observed key path.
 
 */
@property(readonly, nonatomic, copy) NSString *keyPath;

/** Returns the observed change.
 
 */
@property(readonly, nonatomic, retain) NSDictionary *change;

/** Returns the user info provided during registration of the observation.
 
 */
@property(readonly, nonatomic, retain) id userInfo;

/** Returns yes if the notification call back is a prior change notification.
 
 */
@property (readonly, nonatomic, getter = isPrior) BOOL prior;

/** Returns the object for key NSKeyValueChangeOldKey from the change dictionary.
 
 */
@property (readonly, nonatomic) id changeOldValue;

/** Returns the object for key NSKeyValueChangeNewKey from the change dictionary.
 
 */
@property (readonly, nonatomic) id changeNewValue;

/** Returns the result of -[object valueForKeyPath:keyPath]
 
 */
@property (readonly, nonatomic) id currentValue;

@property (readonly, nonatomic, retain) SFKVOContext *context;

/** Creates and returns an autoreleased notification object.
 @return An autoreleased SFKVONotification
 @param theObject The observed object.
 @param theKeyPath The observed key path.
 @param theChange The change dictionary. Contains tha same information as -observeValueForKeyPath:ofOject:change:context:
 @param theUserInfo The user info provided during registration of the observation.
 @param theContext The current SFKVOContext fromt the thread on which the SFKVONotification object was created (therefore the thread on which the observed property was changed).
 */
+ (SFKVONotification *)notificationWithObject:(id)theObject keyPath:(NSString *)theKeyPath change:(NSDictionary *)theChange userInfo:(id)theUserInfo context:(SFKVOContext *)theContext;

/** Creates and returns a notification object. Designated initializer.
 @return An SFKVONotification
 @param theObject The observed object.
 @param theKeyPath The observed key path.
 @param theChange The change dictionary. Contains tha same information as -observeValueForKeyPath:ofOject:change:context:
 @param theUserInfo The user info provided during registration of the observation.
 @param theContext The current SFKVOContext fromt the thread on which the SFKVONotification object was created (therefore the thread on which the observed property was changed).
 */
- (id)initWithObject:(id)theObject keyPath:(NSString *)theKeyPath change:(NSDictionary *)theChange userInfo:(id)theUserInfo context:(SFKVOContext *)theContext;

@end
