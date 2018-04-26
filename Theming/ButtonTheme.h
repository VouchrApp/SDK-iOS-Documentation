//
//  ButtonTheme.h
//  VouchrSDK
//
//  Created by Ritchie Bui on 2018-01-12.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class FontTheme;

@interface ButtonTheme : NSObject <NSCopying>

@property (nonatomic) FontTheme *fontTheme;
@property (nonatomic) UIColor *backgroundColor;

@property (nonatomic) CGFloat borderWidth;
@property (nonatomic) UIColor *borderColor;

@property (nonatomic) CGSize shadowOffset;
@property (nonatomic) CGFloat shadowOpacity;
@property (nonatomic) CGFloat shadowRadius;
@property (nonatomic) UIColor *shadowColor;

+ (instancetype)baseProceedButtonTheme;
+ (instancetype)baseCancelButtonTheme;

@end
