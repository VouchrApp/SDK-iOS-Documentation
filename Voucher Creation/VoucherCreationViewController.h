//
//  VoucherCreationViewController.h
//  VouchrSDK
//
//  Created by Ritchie Bui on 2018-01-15.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PersonalizationOption.h"

@protocol PersonalizationOptionViewControllerProtocol;
@class Merchant;
@class User;
@class Voucher;
@class PersonalizationOption;
@class ThemeManager;
@class VoucherCreationManager;
@class VoucherCreationViewController;

/**
 The 'VoucherCreationViewControllerDelegate' is the object responsible for supplying additional screens
 **/
@protocol VoucherCreationViewControllerDelegate <NSObject>

/**
 * This delegate callback occurs when the user wants to proceed with their voucher but is not currently logged in. Perform a login or prompt the user to login during this callback and then execute the completion block.
 *
 * @param viewController - The current `VoucherCreationViewController` being actioned on.
 * @param completion - Block containing additional tasks to be executed upon logging in. Pass in nil if login was successful, the corresponding `NSError` if login has failed.
 *
 */
- (void)createViewController:(VoucherCreationViewController *)viewController needsLoginWithCompletion:(void(^)(NSError *error))completion;


/**
 * This delegate callback occurs when the user has completed their actions on the `VoucherCreationViewController` and wants to proceed with sending their voucher.
 *
 * @param viewController - The current `VoucherCreationViewController` being actioned on.
 * @param envelopeFrame - The frame of the envelope on the `VoucherCreationViewController`. This frame is intended to be used for any custom transitions or animations of the envelope on the next view controller.
 * @param backgroundColor - The current background color of the `VoucherCreationViewController`. It is supplied in the case consistency is required on the next screen.
 *
 */
- (void)createViewController:(VoucherCreationViewController *)viewController completedWithEnvelopeFrame:(CGRect)envelopeFrame backgroundColor:(UIColor *)backgroundColor;


/**
 * This delegate callback occurs when the user wants to add a particular personalization to their voucher.
 *
 * @param type - The personalization type that the user wants to customize.
 * @param transitionController - The transition controller to be used to present the personalization view controller.
 * @return The `UIViewController` presented to the user that allows customization of the desired personalization for the voucher. The view controller must conform to the `PersonalizationOptionViewControllerProtocol` protocol.
 *
 */
- (UIViewController <PersonalizationOptionViewControllerProtocol>*)personalizationViewControllerForType:(PersonalizationType)type
                                                                                   transitionController:(NSObject<UIViewControllerAnimatedTransitioning> *)transitionController;

@end

/**
 The 'VoucherCreationViewController' is the screen responsible for presenting all personalization options and provides visual feedback for alterations to the `Voucher`. This screen contains the carousel of personalization options at the top and the envelope containing the personalizations below.
 **/
@interface VoucherCreationViewController : UIViewController

@property (weak, nonatomic) id<VoucherCreationViewControllerDelegate> delegate;

/**
 * This method initializes the `VoucherCreationViewController`. This is the default initializer.
 *
 * @param createManager - The manager responsible for handling the flow management in the creation process.
 * @param themeManager - Theme manager for the VoucherCreationViewController
 * @param personalizationOptions - A list containing personalizations accessible to the user.
    The order of personalization options passed in will be the order they are displayed in.
 *
 */
+ (instancetype)voucherCreationViewControllerWithVoucherCreationManager:(VoucherCreationManager *)createManager
                                                           themeManager:(ThemeManager *)themeManager
                                                 personalizationOptions:(NSArray<PersonalizationOption *> *)personalizationOptions;


///---------------------------
/// @name Prepopulating the Voucher with initial content.
///---------------------------

/**
 * Starts the creation of a new `Voucher` with contents of an existing `Voucher`. All personalizations in the passed in voucher will be visualized in the envelope.
 *
 * @param voucher - The `Voucher` object to populate from.
 *
 */
- (void)populateWithVoucher:(Voucher *)voucher;

/**
 * Starts the creation of a voucher with recipients already selected.
 *
 * @param recipients - List of recipients that the `Voucher` will be sent to.
 * @param shouldLaunchRecipientScreen - Indicates whether or not to display the recipient selection screen upon launch of the `VoucherCreationViewController` so the user can verify the recipients.
 *
 */
- (void)populateWithRecipients:(NSArray<User *> *)recipients shouldLaunchRecipientScreen:(BOOL)shouldLaunchRecipientScreen;

/**
 * Starts the creation of a `Voucher` with a monetary amount.
 *
 * @param merchant - Contains information about the monetary personalization.
 * @param amount - The amount of the personalization.
 * @param currencyString - The string representing the currency.
 * @param isLocked - Specifies whether the user can edit and remove this monetary personalization from the `Voucher`.
 *
 */
- (void)populateWithMerchant:(Merchant *)merchant
                      amount:(float)amount
              currencyString:(NSString *)currencyString
                    isLocked:(BOOL)isLocked;

// TODO: document
- (void)reopenEnvelope;

@end
