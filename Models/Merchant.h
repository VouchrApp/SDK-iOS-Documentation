//
//  Merchant.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2018-01-11.
//  Copyright © 2018 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PaymentMerchantInfo;

@interface Merchant : NSObject

@property (nonatomic, readonly) long long merchantId;
@property (nonatomic, strong, readonly) NSString *merchantUri;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *photoUrl;
@property (nonatomic, strong, readonly) NSString *previewPhotoUrl;
@property (nonatomic, strong, readonly) NSString *backgroundColorHexString;

@property (nonatomic, assign, readonly) BOOL hasOnlinePurchases;
@property (nonatomic, assign, readonly) BOOL hasCashPurchases;
@property (nonatomic, assign, readonly) BOOL productSearchEnabled;

@property (nonatomic, strong, readonly) NSArray<PaymentMerchantInfo*> *paymentMerchantInfos;
@property (nonatomic, strong, readonly) PaymentMerchantInfo *sourceInfo;
@property (nonatomic, strong, readonly) NSString *websiteUrl;

+ (Merchant*)merchantFromDictionary:(NSDictionary*)dictionary;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (NSDictionary*)dictionaryRepresentation;

@end
