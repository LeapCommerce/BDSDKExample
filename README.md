BDSKDExample
============

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/best_decision_logo.png)

## ￼Best Decision SDK Documentation ©LEAP Commerce, 2011-2012
(Last updated 11.21.12)

**Developer support resources-**

General integration questions – developers@leapcommerce.com

Developer support forum – GetSatisfaction.com/BestDecision

Follow us on Facebook – fb.com/BestDecisionSDK, Twitter – twitter.com/BestDecisionSDK

**Abstract-**

Bring intelligent shopping to your mobile app with Best DecisionTM

It's easy to integrate our SDK and monetize your app while giving your users a unique, personalized, social shopping experience. Users will love Best Decision's product comparison and social features, and our innovative advanced learning algorithm offers them personalized recommendations, increasing engagement and netting you more users and better ratings.


**Getting Started-**

Getting up the Best Decision SDK is easy! We’ve put everything into ordered steps to get you started quickly.
We’re happy to help you with your initial setup. Please take a look at our developer forum (getsatisfaction.com/bestdecision) or get in touch with us by emailing developers@leapcommerce.com.


**Integration steps-**

*1) Find your API key / FB url scheme suffix:*

Shortly after you submit your request for SDK access on our website (GetBestDecision.com) we will send you a confirmation email with the SDK zip file, your unique API key, and your FB url scheme suffix. Please keep this in a safe place.
Next, make sure you send us your Bundle ID – Make sure you have sent us your bundle identifier so we can point Facebook to your app.

*2) Drag the Best Decision SDK zip file into Xcode:*

Drag the entire Best Decision SDK zip folder into your projects on Xcode. This is straightforward, but make sure to select the option, “Copy items into destination group’s folder.” [screenshot below]

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_1.png)

*3) Add Frameworks:*

You will need to add the following frameworks / dynamic libraries to integrate our SDK into your app:
* CFNetwork.framework
* SystemConfiguration.framework
* MobileCoreServices.framework
* CoreGraphics.framework 
* MapKit.framework
* CoreLocation.framework 
* QuartzCore.framework
* libz.dylib
* libsqlite3.0.dylib
* libz.1.2.5.dylib
* iAd.framework
* MediaPlayer.framework 
* Twitter.framework
* Accounts.framework
* MessageUI.framework
* Copy "resources" folder (with png images; it's in the xcode project) to your project and make sure that the copied images are linked in "Build Phases" -> "Copy Bundle Resources"
* Copy "dependencies" folder(it's in this xcode project) with JSON framework files to your project and make sure that the copied files appear in "Build Phases" -> "Compile Sources"

### Below is an installation example of a framework – CFNetwork.framework:

Opening the settings for your target by clicking on the topmost blue bar of the Xcode sidebar:

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_2.png)

Opening the “Build Phases” tab, expanding the box labeled, “Link Binary With Libraries,” and clicking the plus button:

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_3.png)

Choosing CFNetwork.framework from the list and clicking “Add”:

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_4.png)

Now, repeat the last two steps to add the remaining frameworks and dynamic libraries. 


*4) Build Settings*

In the target build settings, set Architectures to armv6 armv7 as our SDK supports iOS 3.0+ and universal apps.

Also in target build settings set Build Active Architecture Only to YES.


*5) Import the Header:*

In the header file of the view controller in which you want to implement the SDK, import “LCBDSDK.h”


*6) Add “-all_load” to the other linker flags:*

In the target build settings, make sure to add “-all_load” to the Other Linker Flags.

This step is required to make sure that all of our data parsing tools get compiled on build.

￼
*7) Facebook Integration:*

In order to integrate Facebook in the SDK, it is necessary to send your bundle identifier. Email the following to developers@leapcommerce.com:

Bundle ID – Make sure you have sent us your bundle identifier so we can point Facebook to your app


Next, the App Delegate – Put the following code in your app delegate: 
```Objective-C
//Begin code
#import "LCFacebookManager.h"
...
#pragma mark - Facebook handleOpenURL for SSO:
// Pre 4.2 support
- (BOOL) application:(UIApplication *)application handleOpenURL:(NSURL *)url {
  return [[LCFacebookManager getFacebookManager] handleOpenURL:url]; 
}
// For 4.2+ support
- (BOOL) application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
  return [[LCFacebookManager getFacebookManager] handleOpenURL:url]; 
}
//end code
```

Facebook URL Scheme – Include our custom FB URL scheme in your .plist

We'll provide it when you sign up (see attached image). If you don't have any URL types set up, click Add in the bottom right of the editor on your .plist and select “Add URL Type.” Add the new URL scheme (comma separated) in the URL.

Here we have our demo app’s personal openURL scheme (“shouldIbuyit” and the Facebook URL scheme “fb186397454781357foo”:

URL Scheme:

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_5.png)
￼￼
Bundle ID:

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_6.png)


*￼8) Ensuring 3rd party SDK compatibility*

If you use any of the following 3rd party SDKs, you need to follow the instructions in this step. If you do not use any of the following SDKs in your app, you can continue to the next step:
* Flurry
* JumpTap

To avoid duplicate errors with 3rd party SDKs, we have included the 3rd party SDKs as separate files for you to drag into your project.

If you already use any of these 3rd party SDKs, please ensure to delete these SDKs from our SDK packet so there is no duplicate error warning.


*9) Using the SDK:*

You have now completed integration of the SDK in your app. The following code examples and resource list will help you to implement the SDK in your app.

```Objective-C
LCBDSDK *bdSDK = [[LCBDSDK alloc] init];

[bdSDK launchModalOnTopOfViewController:self
                          andSearchTerm:@"iPod"
                          andFacebookID:@"285517068236312"
                              andAPIKey:@"bf80c20eed1efd9b3d97fe23d70907df"
                     andURLSchemeSuffix:@"testsdk"];
```
￼
<table>
<th>Resources</th>
<th>Descriptions</th>
<tr>
  <td>(UIViewController *) viewController</td>
  <td>￼￼The viewController that the SDK is launching on top of (this will usually be "self" if you are launching the SDK from a viewController). <b>Required</b></td>
</tr>
<tr>
  <td>(NSString *) searchTerm</td>
  <td>￼￼￼￼￼￼The string used to initiate the product search. This can be anything from a simple query like "iPad 2" or a specific UPC "1234678910".</td>
</tr>
<tr>
  <td>(NSString *) facebookID</td>
  <td>￼￼This is the user's Facebook ID. We use this to identify a unique user and pull in their product likes to help make our recommendations. If you do not have the user's FBID, please pass in nil. We'll ask the user for their Facebook permissions.</td>
</tr>
<tr>
  <td>(NSString *) APIkey</td>
  <td>The APIkey that we've provided for you. <b>Required</b></td>
</tr>
<tr>
  <td>(NSString *) URLSchemeSuffix</td>
  <td>This is the URL Scheme Suffix we provided you to redirect back to your app after Facebook authentication. <b>Required</b></td>
</tr>
</table>￼￼


*10) Additional code example:*

Here is a very simple example of an implementation in a list app. The Table View Controller has a list of items hardcoded in, and clicking on any of these items will launch the SDK.

![Best Decision Logo](https://raw.github.com/wiki/LeapCommerce/BDSDKExample/screenshot_7.png)

￼￼￼
##**Leap Commerce/Best Decision SDK License**##

By using any part of this SDK, you or the entity or company that you represent (“you,” “your,” “yours” or “licensee”) are unconditionally consenting to be bound by and are becoming a party to this Leap Commerce/Best Decision SDK License Agreement (the “agreement”), and are hereby representing and warranting that you are authorized to bind licensee. Your download, installation or continued use of the downloaded materials or the SDK (as defined below) shall also constitute assent to the terms of this agreement. If you do not unconditionally agree to all of the terms of this agreement, do not click the “Submit” button and you will have no right to use the SDK. If these terms are considered an offer, acceptance is expressly limited to these terms to the exclusion of all other terms.

1. Subject to full compliance with the terms of this Agreement, Leap Commerce, Inc. (“we,” “us” “our” or “Leap”) hereby grants you a limited, personal, non-
sublicensable, non-transferable, royalty-free, nonexclusive license to use our Software Development Kit (“SDK”) and related information and documentation
(collectively, the “SDK”) for the sole purpose of allowing you to build software applications (each an “App”) that communicate with Leap’s shopping service
(the “Service”), and for other purposes authorized by us in writing.
2. Subject to full compliance with the terms of this Agreement, we hereby grant you a limited, personal, non- sublicensable, non-transferable, royalty-free, nonexclusive license to distribute the SDK in object code form only as part of an App, and only subject to an end-user license agreement which is at least as protective of our proprietary rights in the SDK as those contained in this agreement. Without limiting the foregoing, these terms and conditions must include terms for Leap’s benefit regarding (a) restrictions on reverse engineering (to the maximum extent permitted by applicable law); (b) disclaimer of warranties; and (c) limitation of liability.
3. Except in connection with your limited right to distribute the SDK in object code form in accordance with Section 2, you agree not to disclose (or allow access
to) the SDK (or any information derived from them) to any third party and will limit access to the SDK (and any derived information) to your employees who are developing the App. In support of this obligation, you will apply at least the same security that you use to protect your own most confidential information. You will not reverse engineer any aspect of the SDK or authorize or encourage anyone else to do so (except to the extent such restriction is prohibited by applicable law).
4. You agree not to block, disable, hide or limit in any way the ability of any device (whether or not it includes the App) to access the Service or any portion or
functionality of or enabled by the Service.
5. Each App must (a) maintain 100% compatibility with the SDK and the Service (including changes provided to you by Leap, which shall be implemented in the App promptly thereafter). You understand that we may cease support of old versions or releases of the SDK. If any App uses or implements an outdated version of the API, SDK or the Service, you acknowledge and agree that such App may not be able to communicate with the Service. You agree not to modify, extend, subset or superset the SDK to any extent.
6. LEAP PROVIDES THE SDK “AS IS” AND WITHOUT WARRANTY OF ANY KIND, AND HEREBY DISCLAIMS ALL EXPRESS OR IMPLIED WARRANTIES, INCLUDING WITHOUT LIMITATION WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, PERFORMANCE, ACCURACY, RELIABILITY, AND NON-INFRINGEMENT.
7. Limitation of Liability: under no circumstances and under no legal theory, including, but not limited to, tort, contract, negligence, strict liability, or otherwise, shall Leap or its suppliers or resellers be liable to you or any other person for any indirect, special, incidental, or consequential damages including, without limitation, damages for lost profits, loss of goodwill, , or damages resulting from licensee’s use of the SDK. Leap’s liability for damages of any kind whatsoever arising out of this agreement shall be limited to $100. The foregoing will not apply to damages for bodily injury that, under applicable law, cannot be so limited. The foregoing limitations shall apply even if you have been informed of the possibility of such damages. Some states do not allow the exclusion or limitation of incidental or consequential damages, so the above limitation and exclusion may not apply to you.
8. This Agreement represents the complete agreement concerning the subject matter hereof between the parties and supersedes all prior agreements and
representations between them. This Agreement may be amended only by a writing executed by both parties. If any provision of this Agreement is held to be
unenforceable for any reason, such provision shall be reformed only to the extent necessary to make it enforceable. The failure of Leap to act with respect to
a breach of this Agreement by Licensee or others does not constitute a waiver and shall not limit Leap’s rights with respect to such breach or any subsequent
breaches. This Agreement is personal to Licensee and may not be assigned or transferred for any reason whatsoever without Leap’s consent and any action
or conduct in violation of the foregoing shall be void and without effect. Leap expressly reserves the right to assign this Agreement and to delegate any of its
obligations hereunder. This Agreement shall be governed by and construed under California law as such law applies to agreements between California residents entered into and to be performed within California. The sole and exclusive jurisdiction and venue for actions arising under this Agreement shall be the State and Federal courts in San Francisco, California; both parties hereby agree to service of process in accordance with the rules of such courts. The party prevailing in any dispute under this Agreement shall be entitled to its costs and legal fees.