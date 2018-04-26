//
//  VoucherCreationManager.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2018-01-24.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol VoucherCreationFlowDelegate, VONetworkManagerProtocol, VOWrappingPaperManagerProtocol,
    VOTrackManagerProtocol, VOUserManagerProtocol, VouchrLoadingViewProtocol, VOGiftManagerProtocol;

@class VoucherCreationManagerBuilder, MutableVoucher;

@interface VoucherCreationManager : NSObject

/*!
 @brief The voucher that is being created. This will be modified throughout the create process via
 any personalizations. It will be become a `Voucher` at the end of the create process.
 @remark Default is a new, empty voucher.
 */
@property (strong, nonatomic, readonly) MutableVoucher *mutableVoucher;

/*!
 @brief Used throughout the create flow to facilitate network calls.
 
 @remark Default is nil.
 */
@property (weak, nonatomic, readonly) id<VONetworkManagerProtocol> networkManager;

/*!
 @brief An instance of `GiftManager` used to create and activate the mutableVoucher.
 
 @remark Default is nil.
 */
@property (weak, nonatomic, readonly) id<VOGiftManagerProtocol> giftManager;

/*!
 @brief Analytics manager used to track events throughout the create flow.
 
 @remark Default is nil.
 */
@property (weak, nonatomic, readonly) id<VOTrackManagerProtocol> trackManager;

/*!
 @brief User manager used to login, fetch profile information.
 @remark Default is nil.
 */
@property (weak, nonatomic, readonly) id<VOUserManagerProtocol> userManager;

/*!
 @brief Used to fetch wrapping papers that the user can use to personalize their voucher.
 @remark Default is nil.
 */
@property (weak, nonatomic, readonly) id<VOWrappingPaperManagerProtocol> wrappingPaperManager;

/*!
 @brief A Fullscreen loading view that will be displayed when user interaction needs to be blocked during load time.
 @remark Default is a UIActivityIndicator with a semi-transparent overlay.
 */
@property (strong, nonatomic, readonly) UIView <VouchrLoadingViewProtocol> *fullScreenLoadingView;

/*!
 @brief Colours shown in the background of the create screen. Colors are cycled based on wrapping paper selection. After a wrapping paper is chosen, the color closest to the wrapping paper is set as the new background color.
 
 @remark Default colors are:
 Red: #E86963, Orange: #FFAD76, Yellow: #FFDA67, Green: #77E097, Teal: #2FCCAD, Navy Blue: #509CDE, Purple: #9372FF
 Pass in an empty array for no color.
 */
@property (strong, nonatomic, readonly) NSArray <UIColor *> *voucherCreationBackgroundColors;


/*!
 @brief The list of colors used color the borders of the items dropping into the envelope.
 A random color will be picked from this list. Supply a nil or empty array if no border is desired.
 
 @remark Default list consists of a single color; white.
 */
@property (strong, nonatomic, readonly) NSArray <UIColor *> *creationItemBorderColors;

/*!
 @brief The border width shown on the items dropped into the envelope.
 @remark Default is 7 px.
 */
@property (nonatomic, readonly) CGFloat creationItemBorderWidth;

/*!
 @brief The text shown if the create carousel is emptied (all personalizations completed by the user).
 @remark Default text is localized 'Your SURPRiiSE looks awesome!'.
 */
@property (nonatomic, readonly) NSString *carouselEmptiedText;

/*!
 @brief Specifies whether recipient information is required to be entered before sending a Voucher.
 @remark Default is YES.
 */
@property (nonatomic, readonly) BOOL recipientRequired;

/*!
 @breif Specifies whether a summary screen should be displayed when no monetary
 value is included in the voucher.
 @remark The summary screen displays a breakdown of the price and payment
 @remark Default is NO
 */
@property (nonatomic, readonly) BOOL alwaysShowFullSummaryScreen;

/*!
 @brief Minimum number of customizations required before allowing
 the voucher to be created
 @remark Default is 1
 */
@property (nonatomic, readonly) NSInteger minimumNumberOfCustomizations;

/*!
 @brief Specifies whether vouchers must include a monetary amount.
 @remark Default is YES
 */
@property (nonatomic, readonly) BOOL allowFreeGifts;

/*!
 @brief Default initializer for VoucherCreationManager.
 @param builderBlock - block containing builder object used to configure properties in VoucherCreationManager.
 Set desired properties on this builder.
 @return instance of VoucherCreationManager
 */
+ (instancetype)voucherCreationManagerWithBuilder:(void (^)(VoucherCreationManagerBuilder *))builderBlock;

@end


@interface VoucherCreationManagerBuilder : NSObject

@property (strong, nonatomic) MutableVoucher *mutableVoucher;
@property (weak, nonatomic) id<VONetworkManagerProtocol> networkManager;
@property (weak, nonatomic) id<VOGiftManagerProtocol> giftManager;
@property (weak, nonatomic) id<VOTrackManagerProtocol> trackManager;
@property (weak, nonatomic) id<VOUserManagerProtocol> userManager;
@property (weak, nonatomic) id<VOWrappingPaperManagerProtocol> wrappingPaperManager;
@property (strong, nonatomic) UIView <VouchrLoadingViewProtocol> *fullScreenLoadingView;
@property (strong, nonatomic) NSArray <UIColor *> *voucherCreationBackgroundColors;
@property (strong, nonatomic) NSArray <UIColor *> *creationItemBorderColors;
@property (nonatomic) CGFloat creationItemBorderWidth;
@property (nonatomic) NSString *carouselEmptiedText;
@property (nonatomic) BOOL recipientRequired;
@property (nonatomic) BOOL alwaysShowFullSummaryScreen;
@property (nonatomic) NSInteger minimumNumberOfCustomizations;
@property (nonatomic) BOOL allowFreeGifts;

@end
