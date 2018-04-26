//
//  VouchrEngine.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2017-12-21.
//  Copyright © 2017 Vouchr. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "VOCacheProtocol.h"
#import "VOUserManagerProtocol.h"
#import "VONetworkManagerProtocol.h"
#import "VOPersistManagerProtocol.h"
#import "VOGiftManagerProtocol.h"
#import "VOWrappingPaperManagerProtocol.h"
#import "VOTrackManagerProtocol.h"

@class VouchrEngineBuilder;

/*
 `VouchrEngine` is a singleton that persists and provides access to core manager dependencies.

 ## Usage Notes
 Initialize the `VouchrEngine` using the `vouchrEngineWithBuilder:` method.
 Example:
 
 VouchrEngine *vouchrEngine = [VouchrEngine vouchrEngineWithBuilder:^(VouchrEngineBuilder *builder) {
     builder.cacheManager = [CacheManager new];
     builder.networkManager = [NetworkManager new];
     builder.userManager = [[UserManager alloc] initWithCacheManager:builder.cacheManager
                                                      networkManager:builder.networkManager persistManager:nil];
 }];
 */
@interface VouchrEngine : NSObject

@property (strong, nonatomic, readonly) id<VONetworkManagerProtocol> networkManager;
@property (strong, nonatomic, readonly) id<VOUserManagerProtocol> userManager;
@property (strong, nonatomic, readonly) id<VOCacheProtocol> cacheManager;
@property (strong, nonatomic, readonly) id<VOPersistManagerProtocol> persistManager;
@property (strong, nonatomic, readonly) id<VOGiftManagerProtocol> giftManager;
@property (strong, nonatomic, readonly) id<VOWrappingPaperManagerProtocol> wrappingPaperManager;
@property (strong, nonatomic, readonly) id<VOTrackManagerProtocol> trackManager;

/**
 This initializes the `VouchrEngine` with the specified dependencies.
 
 @param builderBlock A block containing configuration of the `VouchrEngineBuilder`.
 
 @return The singleton instance of `VouchrEngine`.
 */
+ (instancetype)vouchrEngineWithBuilder:(void (^)(VouchrEngineBuilder *))builderBlock;

/*
 Returns the singleton instance of the `VouchrEngine`
 */
+ (instancetype)instance;

/*
 Returns the authorization token stored in persistence
 
 This method will try and refresh the token if it can't find one in persistence.
 */
- (void)getTokenOnCompletion:(void (^)(NSString *token))onCompletion;

/*
 Persists the authorization token.
 @param token The authorization token received upon successful login.
 */
- (void)setToken:(NSString *)token;

@end


/*
 `VouchrEngineBuilder` is used only to help construct the VouchrEngine and should not be initialized directly.
 */
@interface VouchrEngineBuilder : NSObject

/*
 Instances of these properties should be instantiated and set in the `VouchrEngine` `vouchrEngineWithBuilder:` method.
 */
@property (strong, nonatomic) id<VONetworkManagerProtocol> networkManager;
@property (strong, nonatomic) id<VOUserManagerProtocol> userManager;
@property (strong, nonatomic) id<VOCacheProtocol> cacheManager;
@property (strong, nonatomic) id<VOPersistManagerProtocol> persistManager;
@property (strong, nonatomic) id<VOGiftManagerProtocol> giftManager;
@property (strong, nonatomic) id<VOWrappingPaperManagerProtocol> wrappingPaperManager;
@property (strong, nonatomic) id<VOTrackManagerProtocol> trackManager;


@end
