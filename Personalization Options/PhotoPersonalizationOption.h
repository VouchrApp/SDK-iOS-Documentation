//
//  PhotoPersonalizationOption.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2018-01-19.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import "PersonalizationOption.h"

@class PhotoPersonalizationOptionBuilder;

/**
 PhotoPersonalizationOption represents a `Voucher` customization that allows the user to add images to their `Voucher`. Instantiate a PhotoPersonalizationOption and include it in the `VoucherCreationViewController` setup if you would like the user to be able to add photos.
 **/
@interface PhotoPersonalizationOption : PersonalizationOption

/*!
 @brief Allows the photo to be edited after it is selected.
 
 @remark Default is YES.
 */
@property (nonatomic, readonly) BOOL allowPhotoEditing;
/*!
 @brief Allows the user to add their own photos from their camera roll to the `Voucher`.
 
 @remark Default is YES.
 */
@property (nonatomic, readonly) BOOL canUploadPhotos;
/*!
 @brief Allows the user to add photos taken from their camera to the `Voucher`.
 
 @remark Default is YES.
 */
@property (nonatomic, readonly) BOOL canTakePhotos;

/*!
 @brief Allows the user to add photos from Google image search to the `Voucher`.
 
 @remark Default is YES.
 */
@property (nonatomic, readonly) BOOL canAddGoogleImages;

/*!
 @brief The colors of the image tiles that contain the images to choose from. The colors will only be visible before during the loading phase, before the image thumbnail has finished downloading.
 
 @remark Default list is:
 Red: #E86963, Orange: #FFAD76, Yellow: #FFDA67, Green: #77E097, Teal: #2FCCAD, Navy Blue: #509CDE, Purple: #9372FF
 If you do not want background colors, pass in an empty array.
 */
@property (nonatomic, strong, readonly) NSArray <UIColor *> *imageBackgroundColors;
/*!
 @brief A list of suggested search terms shown to a user in the Google image search screen.
 If no list of suggested search terms is given, the default list from the Vouchr Server will be used.
 
 @remark Default is nil.
 */
@property (nonatomic, strong, readonly) NSArray <NSString *> *suggestedSearchTerms;

/*!
 @brief The maximum number of images returned by the SearchAgent. Set to zero to enable paginated fetches.
 
 @remark Default is 0.
 */
@property (nonatomic, readonly) NSInteger maxSearchResults;

/*!
 @brief Whether the user is allowed to type in the Google Images search bar. If this is disabled, the user will only be able to search using the `suggestedSearchTerms`.
 
 @remark Default is YES.
 */
@property (nonatomic, readonly) BOOL allowUserCustomSearch;


/*!
 @brief Creates a Photo personalization option with the values from the builder. Internally calls initWithBuilder.
 
 @param builderBlock - the block containing the builder to construct the personalization option. Set the desired properties on the builder within the block.
 
 @return instancetype - PhotoPersonalizationOption object containing the properties specified in the builder.
 */
+ (instancetype)photoPersonalizationOptionWithBuilder:(void (^)(PhotoPersonalizationOptionBuilder *))builderBlock;

@end

@interface PhotoPersonalizationOptionBuilder : PersonalizationOptionBuilder

@property (nonatomic) BOOL allowPhotoEditing;
@property (nonatomic) BOOL canUploadPhotos;
@property (nonatomic) BOOL canTakePhotos;
@property (nonatomic) BOOL canAddGoogleImages;

@property (nonatomic, strong) NSArray <UIColor *> *imageBackgroundColors;
@property (nonatomic, strong) NSArray <NSString *> *suggestedSearchTerms;
@property (nonatomic) NSInteger maxSearchResults;
@property (nonatomic) BOOL allowUserCustomSearch;

@end
