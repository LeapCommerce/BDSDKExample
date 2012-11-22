//
//  PruthaDetailViewController.h
//  TestSDK1
//
//  Created by Prutha Desai on 11/7/12.
//  Copyright (c) 2012 Prutha Desai. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LCBDSDK.h"

@interface PruthaDetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (strong, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end
