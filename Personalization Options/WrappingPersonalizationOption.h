//
//  WrappingPersonalizationOption.h
//  VouchrSDK
//
//  Created by Ivan Bui on 2018-02-08.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <VouchrSDK/VouchrSDK.h>
#import "WrappingPaper.h"
#import "WrappingPaperCategory.h"

@class WrappingPersonalizationOptionBuilder;

@interface WrappingPersonalizationOption : PersonalizationOption

/**
 A list of wrapping paper groups displayed to the user. Each group should represent a particular theme or occasion. Default is nil.
 If no list is provided, the default list of categories will be fetched from the Vouchr server
 **/
@property (nonatomic, strong, readonly) NSArray <WrappingPaperCategory *> *wrappingCategories;

/**
 A list of suggested search terms shown to a user in the Google image search screen - default is nil.
 If no list of terms is provided, the default list will be fetched from the Vouchr server.
 **/
@property (nonatomic, strong, readonly) NSArray <NSString *> *searchSuggestions;

/**
 Set a title for the wrapping paper screen - default is "Wrap your SURPRiiSE!"
 **/
@property (nonatomic, readonly) NSString *titleText;

/**
 Placeholder text for the search bar located in the footer at the bottom of the screen.
 Default text is "Search for any occasion".
 **/
@property (nonatomic, readonly) NSString *searchHintFooterLabelText;

/**
 Allows users to upload photos from their camera roll to be used as wrapping papers - default is NO
 **/
@property (nonatomic, readonly) BOOL canUploadPhotos;

/**
 Allows users to search and use wrapping papers from Google Images - Default is NO
 **/
@property (nonatomic, readonly) BOOL canSearch;

/**
 Creates a WrappingPersonalizationOption with values set in the builder.
 @remark Internally calls initWithBuilder
 @param builderBlock - the block containing the builder to construct the personalization option. Set the desired properties on the builder within the block.
 @return instancetype - WrappingPersonalizationOption object containing the properties specified in the builder.
 **/
+ (instancetype)wrappingPersonalizationOptionWithBuilder:(void (^)(WrappingPersonalizationOptionBuilder *))builderBlock;

@end

@interface WrappingPersonalizationOptionBuilder : PersonalizationOptionBuilder

@property (nonatomic, strong) NSArray <WrappingPaperCategory *> *wrappingCategories;
@property (nonatomic, strong) NSArray <WrappingPaper *> *searchSuggestions;
@property (nonatomic) NSString *titleText;
@property (nonatomic) NSString *searchHintFooterLabelText;
@property (nonatomic) BOOL canUploadPhotos;
@property (nonatomic) BOOL canSearch;

@end
