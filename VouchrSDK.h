//
//  VouchrSDK.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2017-12-18.
//  Copyright © 2017 Vouchr. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for VouchrSDK.
FOUNDATION_EXPORT double VouchrSDKVersionNumber;

//! Project version string for VouchrSDK.
FOUNDATION_EXPORT const unsigned char VouchrSDKVersionString[];

// ### UI ###

// Theming objects
#import <VouchrSDK/ButtonTheme.h> //
#import <VouchrSDK/FontTheme.h>

#import <VouchrSDK/ThemeManager.h>

// Common
#import <VouchrSDK/VouchrWebImageView.h>
#import <VouchrSDK/VouchrLoadingViewProtocol.h>

// Action sheet
#import <VouchrSDK/VouchrActionSheetViewController.h>
#import <VouchrSDK/VouchrActionSheetItem.h>

// Voucher Creation
#import <VouchrSDK/VoucherCreationManager.h>
#import <VouchrSDK/VoucherCreationFlowCoordinator.h>
#import <VouchrSDK/VoucherCreationFlowDelegate.h>
#import <VouchrSDK/VoucherCreationViewController.h>
#import <VouchrSDK/EditVoucherContentsViewController.h>

// Creation Personalization Configuration Objects
#import <VouchrSDK/PersonalizationOption.h>
#import <VouchrSDK/PhotoPersonalizationOption.h>
#import <VouchrSDK/RecipientPersonalizationOption.h>
#import <VouchrSDK/WrappingPersonalizationOption.h>
#import <VouchrSDK/NotePersonalizationOption.h>
#import <VouchrSDK/CreationItemImageView.h>
#import <VouchrSDK/TitlePersonalizationOption.h>
#import <VouchrSDK/AnimatedPersonalizationOption.h>
#import <VouchrSDK/RecipientPersonalizationOption.h>

// Personalization Screens
#import <VouchrSDK/CreateAddTitleViewController.h>
#import <VouchrSDK/AddNoteViewController.h>
#import <VouchrSDK/WrappingViewController.h>
#import <VouchrSDK/VouchrImageMediaSearchViewController.h>
#import <VouchrSDK/GiftTagViewController.h>

// Image Personalization Setup & Editing
#import <VouchrSDK/SearchAgent.h>
#import <VouchrSDK/GoogleImageSearchAgent.h>
#import <VouchrSDK/FullScreenImageEditViewController.h>


// ### ENGINE ###

#import <VouchrSDK/VouchrEngine.h>

// Models
#import <VouchrSDK/User.h>
#import <VouchrSDK/Voucher.h>
#import <VouchrSDK/MutableVoucher.h>
#import <VouchrSDK/UserNetwork.h>
#import <VouchrSDK/VoucherMedia.h>
#import <VouchrSDK/Merchant.h>
#import <VouchrSDK/Credential.h>
#import <VouchrSDK/VouchrError.h>
#import <VouchrSDK/ImageModel.h>
#import <VouchrSDK/WrappingPaper.h>
#import <VouchrSDK/WrappingPaperCategory.h>
#import <VouchrSDK/PaymentMerchantInfo.h>
#import <VouchrSDK/MerchantProduct.h>
#import <VouchrSDK/FeaturedMerchant.h>
#import <VouchrSDK/VoucherPayment.h>
#import <VouchrSDK/PaymentInfo.h>
#import <VouchrSDK/ActivityFeedVoucher.h>
#import <VouchrSDK/GameData.h>
#import <VouchrSDK/HTMLGameData.h>

// Manager Protocols
#import <VouchrSDK/VOUserManagerProtocol.h>
#import <VouchrSDK/VOGiftManagerProtocol.h>
#import <VouchrSDK/VONetworkManagerProtocol.h>
#import <VouchrSDK/VORefreshTokenProtocol.h>
#import <VouchrSDK/VOPersistManagerProtocol.h>
#import <VouchrSDK/VOCacheProtocol.h>
#import <VouchrSDK/VOWrappingPaperManagerProtocol.h>
#import <VouchrSDK/VOTrackManagerProtocol.h>

// Concrete Managers
#import <VouchrSDK/NetworkManager.h>
#import <VouchrSDK/UserManager.h>
#import <VouchrSDK/GiftManager.h>
#import <VouchrSDK/CacheManager.h>
#import <VouchrSDK/PersistManager.h>
#import <VouchrSDK/WrappingPaperManager.h>
