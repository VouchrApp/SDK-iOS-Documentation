//
//  TitlePersonalizationOption.h
//  VouchrSDK
//
//  Created by Ivan Bui on 2018-01-24.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import "PersonalizationOption.h"

@class TitlePersonalizationOptionBuilder;

/**
 TitlePersonalizationOption represents a `Voucher` customization which will allow users to title their `Voucher`. Instantiate a `TitlePersonalizationOption` and include it in the `VoucherCreationViewController` setup if you would like the user to be able to add a title to their Voucher.
 **/
@interface TitlePersonalizationOption : PersonalizationOption

/**
 (Unselectable) text to be displayed when there is no title text.
 **/
@property (nonatomic, readonly) NSString *placeholderText;

/**
 Initial title text to be displayed in `CreateAddTitleViewController`.
 **/
@property (nonatomic, readonly) NSString *titleText;

/**
 The maximum number of characters that titleText can contain.
 */
@property (nonatomic, readonly) NSInteger maxTitleLength;

/**
 Creates a TitlePersonalizationOption object with the values from the builder. Internally calls initWithBuilder
  @param builderBlock - the block containing the builder to construct the personalization option. Set the desired properties on the builder within the block.
 @return instancetype - TitlePersonalizationOption object containing the properties specified in the builder.
 **/
+ (instancetype)titlePersonalizationOptionWithBuilder:(void (^)(TitlePersonalizationOptionBuilder *))builderBlock;

@end

@interface TitlePersonalizationOptionBuilder : PersonalizationOptionBuilder

@property (nonatomic) NSString *titleText;
@property (nonatomic) NSInteger maxTitleLength;
@property (nonatomic) NSString *placeholderText;

@end
