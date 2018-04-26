//
//  MutableVoucher.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2018-01-09.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import "Voucher.h"

@interface MutableVoucher : Voucher

@property (nonatomic) long long vId;
@property (nonatomic) VoucherStatus status;

// Merchant properties
@property (nonatomic) double amount;
@property (nonatomic) double fee;
@property (nonatomic, strong) NSString *currency;

// Thank you photo
@property (nonatomic) BOOL isThankYouPhotoRequired;
@property (nonatomic) NSDate *thankYouDate;

// dates
@property (nonatomic, strong) NSDate *dateModified;
@property (nonatomic, strong) NSDate *dateCreated;
@property (nonatomic, strong) NSDate *dateClaimable;

// Users
@property (nonatomic, strong) User *creator;
@property (nonatomic, strong) User *claimer;
@property (nonatomic, strong) NSArray <User *> *viewers;
@property (nonatomic, strong) NSArray <User *> *recipients;
@property (nonatomic, strong) NSArray <NSNumber *> *unwrappedUsers;

// customization options
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *shareImageUrl;
@property (nonatomic) VoucherPrivacyStatus privacy;
@property (nonatomic, strong) NSArray <VoucherMedia *> *medias;
@property (nonatomic, strong) WrappingPaper *wrappingPaper;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

+ (instancetype)mutableVoucherWithDictionary:(NSDictionary *)dictionary;
+ (instancetype)mutableVoucherWithVoucher:(Voucher *)voucher;

- (void)addMedia:(VoucherMedia *)media;
- (void)removeMedia:(VoucherMedia *)media;

@end
