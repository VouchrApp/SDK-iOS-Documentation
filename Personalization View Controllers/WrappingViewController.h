//
//  WrappingViewController.h
//  Vouchr
//
//  Created by Bryan Lahartinger on 2014-04-07.
//  Copyright (c) 2014 AndSpot. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PersonalizationOptionViewControllerProtocol.h"

@class WrappingPaper;

/**
 This personalization screen allows users to browse and select WrappingPapers for their `Voucher`
 **/
@interface WrappingViewController : UIViewController <PersonalizationOptionViewControllerProtocol>

@property (nonatomic, retain) WrappingPaper *wrappingPaper;

/**
 Default initializer for WrappingViewController.
 @param personalizationOption - Contains desired configurations for this screen.
 @param createManager - The manager responsible for handling the flow management in the creation process.
 @param delegate - The delegate of the WrappingViewController instance.
 @return instance of WrappingViewController
 */
+ (instancetype)viewControllerWithPersonalizationOption:(PersonalizationOption *)personalizationOption
                                          createManager:(VoucherCreationManager *)createManager
                                               delegate:(id<PersonalizationOptionViewControllerDelegate>)delegate;

@end
