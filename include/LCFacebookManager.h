//
//  LCFacebookManager.h
//  ShouldI
//
//  Created by Weston McBride on 05/09/12.
//  Copyright (c) 2011 LeapCommerce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCBD_Facebook.h"

@interface LCFacebookManager : NSObject < LCBD_FBSessionDelegate, LCBD_FBDialogDelegate, LCBD_FBRequestDelegate >

+ (LCFacebookManager *)getFacebookManager;

- (void)startFacebook;
- (void)updateUser;
- (BOOL)handleOpenURL:(NSURL *)url;
- (BOOL)isSessionValid;

@property (nonatomic, copy) NSString *urlSchemeSuffix;
@property (nonatomic, retain) LCBD_Facebook *facebook;

@end

