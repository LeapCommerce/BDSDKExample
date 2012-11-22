//
//  LCBDSDK.h
//  LCBDSDK
//
//  Created by Weston McBride on 2/26/12.
//  Copyright (c) 2012 LEAP Commerce, Inc. All rights reserved.
//
//
// Example code: if launching within a view controller (self), with a search term (iPad) for a user with FacebookID (123456789) and the app's API key (abc123def456)
/*
 LCBDSDK *bdSDK = [[LCBDSDK alloc] init];
 [bdSDK launchModalOnTopOfViewController:self andSearchTerm:@"iPad" andFacebookID:@"123456789" andAPIKey:@"abc123def456" andURLSchemeSuffix:@"foo"];
 [bdSDK release];  
 */

// Version 1.6. 
// Uses 1.6 production access point.


#import <Foundation/Foundation.h>

@interface LCBDSDK : NSObject

// Launch with search string and facebookID.
- (void)launchModalOnTopOfViewController:(UIViewController *)viewController andSearchTerm:(NSString *)searchString andFacebookID:(NSString *)facebookIDString andAPIKey:(NSString *)_apiKey andURLSchemeSuffix:(NSString *)urlSuffix;


@end
