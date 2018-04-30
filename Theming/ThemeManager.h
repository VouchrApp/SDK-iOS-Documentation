//
//  ThemeManager.h
//  VouchrSDK
//
//  Created by Ritchie Bui on 2018-01-12.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FontTheme.h"
#import "ButtonTheme.h"

@interface ThemeManager : NSObject <NSCopying>

/**
Font theme to be used for navigation bar titles
*/
@property (nonatomic) FontTheme *navigationTitleFontTheme;

/**
This font style is applied to elements which require much more size and emphasis than a header.
This is typically used only for special cases (eg. amount display on gift card details screen).
*/
@property (nonatomic) FontTheme *displayFontTheme;

/**
Primary header font, majority of headers will use this theme.
*/
@property (nonatomic) FontTheme *mainHeaderFontTheme;

/**
Secondary header font, used in screens where a subheading is required, or a more subtle header.
*/
@property (nonatomic) FontTheme *subHeaderFontTheme;

/**
Font style used for paragraph text. 
*/
@property (nonatomic) FontTheme *bodyFontTheme;

/**
Font style used for more 'fine print' type of texts (eg. timestamps).
*/
@property (nonatomic) FontTheme *captionFontTheme;

/**
Color used for screen backgrounds.
*/
@property (nonatomic) UIColor *emptyBackgroundColor;

/**
Main brand color, used to accent screens.
*/
@property (nonatomic) UIColor *accentColor;

/**
Secondary brand color, used to accent screens.
*/
@property (nonatomic) UIColor *secondaryAccentColor;

/**
style applied to confirmation buttons such as: "next", "done".
*/
@property (nonatomic) ButtonTheme *positiveActionButtonTheme;

/**
Style applied to general buttons.
*/
@property (nonatomic) ButtonTheme *neutralActionButtonTheme;

/**
Style applied to cancellation buttons such as: "cancel", "dismiss".
*/
@property (nonatomic) ButtonTheme *negativeActionButtonTheme;

@end
