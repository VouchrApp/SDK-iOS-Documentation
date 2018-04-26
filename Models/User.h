//
//  User.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2017-12-18.
//  Copyright © 2017 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UserNetwork;

@interface User : NSObject <NSCoding, NSCopying>

@property (nonatomic, readonly) long long userId;
@property (nonatomic, strong, readonly) NSString *email;

// names
@property (nonatomic, strong, readonly) NSString *firstName;
@property (nonatomic, strong, readonly) NSString *lastName;
@property (nonatomic, strong, readonly) NSString *businessName;
@property (nonatomic, strong, readonly) NSString *fullName;
@property (nonatomic, strong, readonly) NSString *shortName;

// photo urls
@property (nonatomic, strong, readonly) NSString *coverImageUrl;
@property (nonatomic, strong, readonly) NSString *profileImageUrl;

// User networks
@property (nonatomic, strong, readonly) NSArray <UserNetwork *> *userNetworks;

+ (instancetype)userWithDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryRepresentation;
@end
