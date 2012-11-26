/*
 * Copyright 2010 Facebook
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "LCBD_FBLoginDialog.h"
#import "LCBD_FBRequest.h"

@class LCBD_FBFrictionlessRequestSettings;
@protocol LCBD_FBSessionDelegate;

/**
 * Main Facebook interface for interacting with the Facebook developer API.
 * Provides methods to log in and log out a user, make requests using the REST
 * and Graph APIs, and start user interface interactions (such as
 * pop-ups promoting for credentials, permissions, stream posts, etc.)
 */
@interface LCBD_Facebook : NSObject<LCBD_FBLoginDialogDelegate,LCBD_FBRequestDelegate>{
    NSString* _accessToken;
    NSDate* _expirationDate;
    id<LCBD_FBSessionDelegate> _sessionDelegate;
    NSMutableSet* _requests;
    LCBD_FBDialog* _loginDialog;
    LCBD_FBDialog* _fbDialog;
    NSString* _appId;
    NSString* _urlSchemeSuffix;
    NSArray* _permissions;
    BOOL _isExtendingAccessToken;
    LCBD_FBRequest *_requestExtendingAccessToken;
    NSDate* _lastAccessTokenUpdate;
    LCBD_FBFrictionlessRequestSettings* _frictionlessRequestSettings;
}

@property(nonatomic, copy) NSString* accessToken;
@property(nonatomic, copy) NSDate* expirationDate;
@property(nonatomic, assign) id<LCBD_FBSessionDelegate> sessionDelegate;
@property(nonatomic, copy) NSString* urlSchemeSuffix;
@property(nonatomic, readonly, getter=isFrictionlessRequestsEnabled) 
    BOOL isFrictionlessRequestsEnabled;

- (id)initWithAppId:(NSString *)appId
        andDelegate:(id<LCBD_FBSessionDelegate>)delegate;

- (id)initWithAppId:(NSString *)appId
    urlSchemeSuffix:(NSString *)urlSchemeSuffix
        andDelegate:(id<LCBD_FBSessionDelegate>)delegate;

- (void)authorize:(NSArray *)permissions;

- (void)extendAccessToken;

- (void)extendAccessTokenIfNeeded;

- (BOOL)shouldExtendAccessToken;

- (BOOL)handleOpenURL:(NSURL *)url;

- (void)logout;

- (void)logout:(id<LCBD_FBSessionDelegate>)delegate;

- (LCBD_FBRequest*)requestWithParams:(NSMutableDictionary *)params
                    andDelegate:(id <LCBD_FBRequestDelegate>)delegate;

- (LCBD_FBRequest*)requestWithMethodName:(NSString *)methodName
                          andParams:(NSMutableDictionary *)params
                      andHttpMethod:(NSString *)httpMethod
                        andDelegate:(id <LCBD_FBRequestDelegate>)delegate;

- (LCBD_FBRequest*)requestWithGraphPath:(NSString *)graphPath
                       andDelegate:(id <LCBD_FBRequestDelegate>)delegate;

- (LCBD_FBRequest*)requestWithGraphPath:(NSString *)graphPath
                         andParams:(NSMutableDictionary *)params
                       andDelegate:(id <LCBD_FBRequestDelegate>)delegate;

- (LCBD_FBRequest*)requestWithGraphPath:(NSString *)graphPath
                         andParams:(NSMutableDictionary *)params
                     andHttpMethod:(NSString *)httpMethod
                       andDelegate:(id <LCBD_FBRequestDelegate>)delegate;

- (void)dialog:(NSString *)action
   andDelegate:(id<LCBD_FBDialogDelegate>)delegate;

- (void)dialog:(NSString *)action
     andParams:(NSMutableDictionary *)params
   andDelegate:(id <LCBD_FBDialogDelegate>)delegate;

- (BOOL)isSessionValid;

- (void)enableFrictionlessRequests;

- (void)reloadFrictionlessRecipientCache;

- (BOOL)isFrictionlessEnabledForRecipient:(id)fbid;

- (BOOL)isFrictionlessEnabledForRecipients:(NSArray*)fbids;

@end

////////////////////////////////////////////////////////////////////////////////

/**
 * Your application should implement this delegate to receive session callbacks.
 */
@protocol LCBD_FBSessionDelegate <NSObject>

/**
 * Called when the user successfully logged in.
 */
- (void)fbDidLogin;

/**
 * Called when the user dismissed the dialog without logging in.
 */
- (void)fbDidNotLogin:(BOOL)cancelled;

/**
 * Called after the access token was extended. If your application has any
 * references to the previous access token (for example, if your application
 * stores the previous access token in persistent storage), your application
 * should overwrite the old access token with the new one in this method.
 * See extendAccessToken for more details.
 */
- (void)fbDidExtendToken:(NSString*)accessToken
               expiresAt:(NSDate*)expiresAt;

/**
 * Called when the user logged out.
 */
- (void)fbDidLogout;

/**
 * Called when the current session has expired. This might happen when:
 *  - the access token expired
 *  - the app has been disabled
 *  - the user revoked the app's permissions
 *  - the user changed his or her password
 */
- (void)fbSessionInvalidated;

@end
