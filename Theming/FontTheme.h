//
//  FontTheme.h
//  VouchrSDK
//
//  Created by Ritchie Bui on 2018-01-12.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIColor, UIFont;

@interface FontTheme : NSObject <NSCopying>

@property (nonatomic) UIColor *darkColor;
@property (nonatomic) UIColor *lightColor;
@property (nonatomic) UIFont *font;
// TODO: rb - add font size modifier

+ (instancetype)fontThemeWithDarkColor:(UIColor *)darkColor lightColor:(UIColor *)lightColor font:(UIFont *)font;

@end
