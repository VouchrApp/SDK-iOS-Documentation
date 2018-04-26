//
//  PersonalizationOption.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2018-01-19.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, PersonalizationType){
    PersonalizationTypeHint,
    PersonalizationTypeGift,
    PersonalizationTypePhoto,
    PersonalizationTypeTitle,
    PersonalizationTypeWrapping,
    PersonalizationTypeRecipient,
    PersonalizationTypeSuggestion,
    PersonalizationTypeSound,
    PersonalizationTypeVideo,
    PersonalizationTypeNote,
    PersonalizationTypeAnimated,
    PersonalizationTypeGames
};

@class PersonalizationOptionBuilder, ThemeManager;

/**
 PersonalizationOption represents a Voucher customization which will be available to the user in the VoucherCreationViewController. A PersonalizationOption should exist for each personalization the user allowed access to.
 
 @remark PersonalizationOption is used as a base class, instantiate an existing subclass (ex. PhotoPersonalizationOption) for use.
 @remark Any properties that are not set will have default values set.
 */
@interface PersonalizationOption : NSObject

/**
 The type of the personalization option.
 */
@property (nonatomic, readonly) PersonalizationType type;

/**
 Specifies whether more than one personalization of this type can be added.
 The options that support multiple additions are: Photo, Video, Animated, Note
 */
@property (nonatomic, readonly) BOOL canAddMultiple;

/**
 The image that appears in the carousel above the envelope, that the user will browse and select - each personalization type has a default image provided, unique to that type.
 */
@property (nonatomic, strong, readonly) UIImage *carouselImage;

/**
 The description that appears in the carousel below the carouselImage - default text is provided and is based on the personalization type
 */
@property (nonatomic, strong, readonly) NSString *carouselText;

/**
 The text that shows up on top of the carouselImage - default is nil
 */
@property (nonatomic, strong, readonly) NSString *carouselOverlappingText;

/**
 The background color that appears behind the carouselImage - default is clear
 */
@property (nonatomic, strong, readonly) UIColor *carouselBackgroundColor;

/**
 Theme manager used to style the personalization screen associated with this Personalization Option - default is nil.
 */
@property (strong, nonatomic, readonly) ThemeManager *themeManager;


/**
 Creates a personalization option with the values from the builder. Internally calls initWithBuilder
 @param builderBlock - the block containing the builder object. Set the desired properties on the supplied builder within the block.
 @return instancetype - PersonalizationOption object containing the properties set on the builder.
 */
+ (instancetype)personalizationOptionWithBuilder:(void (^)(PersonalizationOptionBuilder *))builderBlock;

/**
 Creates a personalization option with the values from the builder. Default initializer.
 @param builder - The builder block with specified values for each property.
 @return instancetype - PersonalizationOption object containing the properties set in the builder.
 */
- (instancetype)initWithBuilder:(PersonalizationOptionBuilder *)builder;

@end

@interface PersonalizationOptionBuilder : NSObject

@property (nonatomic) PersonalizationType type;
@property (nonatomic) BOOL canAddMultiple;
@property (strong, nonatomic) ThemeManager *themeManager;

// carousel properties
@property (nonatomic, strong) UIImage *carouselImage;
@property (nonatomic, strong) NSString *carouselText;
@property (nonatomic, strong) NSString *carouselOverlappingText;
@property (nonatomic, strong) UIColor *carouselBackgroundColor;

@end


