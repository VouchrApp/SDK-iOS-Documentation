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

@property (nonatomic) FontTheme *primaryFontTheme;
@property (nonatomic) FontTheme *secondaryFontTheme;
@property (nonatomic) FontTheme *bodyFontTheme;

// TODO: replace with:
// navigationTitleFontTheme       - Font to be used in screen headers
// displayFontTheme               - Largest, most emphasized font (see amount in gift amount screen)
// h1FontTheme                    - Main header
// h2FontTheme                    - Smaller header
// bodyFontTheme                  - Used as main font for larger bodies of text
// captionFontTheme               - Small, light font, fine print-esque (see timestamps in conversation)

/**
 
 */
@property (nonatomic) UIColor *emptyBackgroundColor;
@property (nonatomic) UIColor *accentColor;
@property (nonatomic) UIColor *secondaryAccentColor;

@property (nonatomic) ButtonTheme *positiveActionButtonTheme;
@property (nonatomic) ButtonTheme *neutralActionButtonTheme;
@property (nonatomic) ButtonTheme *negativeActionButtonTheme;

@end
