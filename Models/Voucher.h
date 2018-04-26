//
//  Voucher.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2017-12-21.
//  Copyright © 2017 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VoucherStatus) {
    VoucherStatusUnknown = -1,
    VoucherStatusPending = 0,
    VoucherStatusCreated,
    VoucherStatusClaimed,
    VoucherStatusRemoved,
    VoucherStatusFrozen,
    VoucherStatusError
};

typedef NS_ENUM(NSInteger, VoucherPrivacyStatus) {
    VoucherPrivacyStatusPrivate,
    VoucherPrivacyStatusFriends,
    VoucherPrivacyStatusPublic,
};

@class User, VoucherMedia, Merchant, VoucherPayment, WrappingPaper;

@interface Voucher : NSObject <NSCoding>

@property (nonatomic, readonly) long long vId;
@property (nonatomic, readonly) VoucherStatus status;

// Merchant properties
@property (nonatomic, readonly) double amount;
@property (nonatomic, readonly) double fee;
@property (nonatomic, strong, readonly) NSString *currency;
@property (nonatomic, strong, readonly) Merchant *merchant;

// payment
@property (nonatomic, strong, readonly) VoucherPayment *paymentInfo;

// Thank you photo
@property (nonatomic, readonly) BOOL isThankYouPhotoRequired;
@property (nonatomic, readonly) NSDate *thankYouDate;

// dates
@property (nonatomic, strong, readonly) NSDate *dateModified;
@property (nonatomic, strong, readonly) NSDate *dateCreated;
@property (nonatomic, strong, readonly) NSDate *dateClaimable;


// Users
@property (nonatomic, strong, readonly) User *creator;
@property (nonatomic, strong, readonly) User *claimer;
@property (nonatomic, strong, readonly) NSArray <User *> *viewers;
@property (nonatomic, strong, readonly) NSArray <User *> *recipients;
@property (nonatomic, strong, readonly) NSArray <NSNumber *> *unwrappedUsers;

// customization options
@property (nonatomic, strong, readonly) NSString *title;
@property (nonatomic, strong, readonly) NSString *shareImageUrl;
@property (nonatomic, readonly) VoucherPrivacyStatus privacy;
@property (nonatomic, strong, readonly) NSArray <VoucherMedia *> *medias;
@property (nonatomic, strong, readonly) WrappingPaper *wrappingPaper;


- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
+ (instancetype)voucherWithDictionary:(NSDictionary *)dictionary;

- (NSDictionary *)dictionaryRepresentation;

@end
