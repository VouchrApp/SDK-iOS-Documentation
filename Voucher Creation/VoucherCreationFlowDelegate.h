//
//  VoucherCreationFlowDelegate.h
//  VouchrSDK
//
//  Created by Ritchie Bui on 2018-01-15.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#ifndef VoucherCreationFlowDelegate_h
#define VoucherCreationFlowDelegate_h



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "PersonalizationOption.h"

@protocol PersonalizationOptionViewControllerProtocol, SectionDataSourceProtocol, VoucherSummaryScreenProtocol;
@class Voucher, MutableVoucher, VoucherPayment;

@protocol VoucherCreationFlowDelegate <NSObject>

@required

/************************************************************************
* * * * * * * * * * * * * * * * PAYMENTS * * * * * * * * * * * * * * * *
*************************************************************************/

/*!
@brief This delegate method is called if payment information needs to be provided to complete activation of the voucher. The callback occurs when the user hits send on the summary screen or if the user taps on the credit card cell.
 
@remark If no paymentInfo needs to be provided, execute the completion block with a nil payment.
@remark The contents of the paymentInfo dictionary will be dependent on the payment system being used and will require discussion with backend team.
 
@property viewController - the current top viewController. If a paymentViewController needs to be presented to retrieve additional payment information, it should be presented on this viewController.
@property voucher - The voucher that needs the payment information.
@property completion - Completion block to be executed when the payment information has been obtained. Supply a dictionary with payment info as the paymentInfo. This will be used in the activateVoucher call. Supply an error if an error has occurred, or if the payment could not be completed.
 */
- (void)voucherCreationShowPaymentOnViewController:(UIViewController *)viewController forVoucher:(Voucher *)voucher onCompletion:(void(^)(NSDictionary *paymentInfo, NSError *error))completion;


/************************************************************************
 * * * * * * * * * * * * * * * * * LOGIN * * * * * * * * * * * * * * * *
 ************************************************************************/

/*!
 @brief This delegate method is called when a user needs to be logged in to proceed with the flow. Users can start with creation of a voucher without being logged in, but must be logged in to send it.
 @remark This callback will occur if the `UserManager` in the `CreationManager` returns false for isLoggedIn.
 
 @param viewController - the current top viewController. If a loginViewController needs to be presented as part of login, it should be presented on this viewController.
 @param completion - completionBlock when login has completed. If an error occurred it will be returned in the completion block.
 This completion block does not need to be called, however it is recommended that it should be.
 */
- (void)showLoginOnViewController:(UIViewController *)viewController onCompletion:(void(^)(NSError *error))completion;


@optional

/************************************************************************
 * * * * * * * * * * * * PERSONALIZATION OPTIONS * * * * * * * * * * * *
 ************************************************************************/

/*
 * @brief This delegate method is called when a personalization screen needs to be displayed to the user.
 * If a nil object is returned, the default implementation of the personalization screen will be used.
 *
 * @param type - the type classification of the personalization requested.
 * @param transitionController - the transition animator for displaying personalization screens. If no transition controller is supplied, the default circular expand transition will be used.
 * @return - The view controller returned must adhere to PersonalizationOptionViewControllerProtocol
 */
- (UIViewController <PersonalizationOptionViewControllerProtocol>*)personalizationViewControllerForType:(PersonalizationType)type
                                                                                   transitionController:(NSObject<UIViewControllerAnimatedTransitioning> *)transitionController;


/************************************************************************
 * * * * * * * * * * * * * * SUMMARY SCREEN * * * * * * * * * * * * * * *
 ************************************************************************/

/*!
 @brief This delegate method is called when the default summary screen is displayed to the user. The summary screen requires an array of data sources, each representing sections of cells in the tableView. They will be displayed in the default summary screen in the order given. Custom data sources & cells can be added as long as they follow the SectionDataSourceProtocol.
 
 @remark
 If this method is not implemented, or if nil is returned, it will use the default data sources:
 1) SummaryScreenClaimerInfoDataSource
     - shows who the gift is being sent to (if there is one)
     - shows when the gift is claimable
 2) SummaryScreenPriceDataSource
     - shows the gift card envelope
     - shows the amount, fees and total cost
     - shows any credits used (if any were used)
     - shows who the gift is visible to
 3) SummaryScreenPaymentDataSource
     - shows which credit card will be used (last 4 digits and type of card) if a credit card is provided
 4) SummaryScreenEndInfoDataSource
     - shows where the receipt is being emailed to
     - shows legal disclaimerText if any is in the Voucher
     - shows terms and conditions if any is in the Voucher
     - shows cardHolderAgreementUrl if one is in the Voucher
 */
- (NSArray <id<SectionDataSourceProtocol>> *)summaryScreenDataSourcesForVoucher:(Voucher *)voucher;

/*
 @brief This delegate method is called when a summary screen needs to be displayed to the user.
 If a nil object is returned, the default implementation will be used
 
 @param payment - the payment type of the Voucher
 @param transitionController - the transition animator for displaying personalization screens.
 */
- (UIViewController<VoucherSummaryScreenProtocol> *)summaryScreenViewControllerForVoucherPayment:(VoucherPayment *)payment
                                                                            transitionController:(NSObject<UIViewControllerAnimatedTransitioning> *)transitionController;


/************************************************************************
 * * * * * * * * * * * * * * * * WRAPPING * * * * * * * * * * * * * * * *
 ************************************************************************/

/*!
 @brief This delegate method is called before the network request to the Vouchr server is made to wrap a voucher.
 @remark Wrapping a voucher puts it in a 'pending' state. The contents of the voucher will be validated,
 payment requirements and fees will be added, and the voucher will be saved in the Vouchr database.
 @param voucher - This is the voucher that will be sent to the server for validation. Can be modified before being sent.
 */
- (void)voucherCreationVoucherWillWrap:(MutableVoucher *)voucher;

/*!
  @brief This delegate method is called after the network request to the Vouchr server is made to wrap a voucher completes successfully.
  @param voucher - The finalized voucher returned from the server.
 */
- (void)voucherCreationVoucherWrapCompleted:(Voucher *)voucher;

/*!
 @brief This delegate method is called if the network request to the Vouchr server fails during validation.
 @param error - The error returned from the server.
 */
- (void)voucherCreationVoucherWrapFailedWithError:(NSError *)error;


/************************************************************************
 * * * * * * * * * * * * * * * ACTIVATION * * * * * * * * * * * * * * * *
 ************************************************************************/

/*!
 @brief This delegate method is called before the network request to the Voucher server is made to activate a voucher. Activating a voucher will process the payment, put the voucher in an active state, and notify the claimer(s) they have been sent a voucher.
 @param voucher - The voucher that is being activated.
 */
- (void)voucherCreationVoucherWillActivate:(Voucher *)voucher;

/*!
 @brief This delegate method is called when a voucher is activated successfully.
 @param voucher - The voucher that was activated.
 */
- (void)voucherCreationVoucherActivationCompleted:(Voucher *)voucher;

/*!
 @brief This delegate method is called if the network request to the Vouchr server fails when activating a voucher.
 @param error - The error returned from the server.
 */
- (void)voucherCreationVoucherActivationFailedWithError:(NSError *)error;

@end

#endif /* VoucherCreationFlowDelegate_h */
