//
//  VOVoucherManagerProtocol.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2017-12-21.
//  Copyright © 2017 Vouchr. All rights reserved.
//

#ifndef VOVoucherManagerProtocol_h
#define VOVoucherManagerProtocol_h

@class Voucher, ActivityFeedVoucher;

@protocol VOVoucherManagerProtocol

/**
 * This will save and validate the voucher on the server
 * This voucher will not be sent to users until activate call is made
 *
 * @param voucher - the voucher that is being created
 * @param onSucceed - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 **/
- (void)createPendingVoucher:(Voucher *)voucher
                   onSuccess:(void(^)(Voucher *voucher))onSucceed
                     onError:(void(^)(NSError *error))onError;

/**
 * This validates payment and sends the Voucher to users
 *
 * @param voucherId - the id of the voucher sent to the server
 * @param paymentSourceDictionary - payment information if necessary, if nil it is assumed this is a FREE voucher
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 **/
-(void)activateVoucherWithId:(long long)voucherId
     paymentSourceDictionary:(NSDictionary *)paymentSourceDictionary
                   onSuccess:(void(^)(Voucher *voucher))onSuccess
                     onError:(void(^)(NSError *error))onError;


/**
 * Unwraps a voucher
 * @discussion - Multiple people can unwrap a voucher but only one person can claim a voucher.
    Usually the unwrap & claim call occur one right after the other.
 * ## Note - Unwrap must be called before claim for the user.
 *
 * @param voucherId - the id of the voucher sent to the server
 * @param score - the score achieved in the game, if a game was played
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 **/
- (void)unwrapVoucherWithId:(long long)voucherId
                      score:(NSInteger)score
                  onSuccess:(void(^)(Voucher *voucher))onSuccess
                    onError:(void(^)(NSError *error))onError;

/**
 * Claims a voucher. After a voucher is claimed no other users will be able to claim.
 *
 * @param voucherId - the id of the voucher sent to the server
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 **/
- (void)claimVoucherWithId:(long long)voucherId
                 onSuccess:(void(^)(Voucher *voucher))onSuccess
                   onError:(void(^)(NSError *error))onError;

/**
 * Retrieves a voucher from server or cache
 *
 * @param voucherId - the id of the voucher sent to the server
 * @param forceUpdate - if true, will ignore cache
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 **/
-(void)requestVoucher:(long long)voucherId
          forceUpdate:(BOOL)forceUpdate
            onSuccess:(void(^)(Voucher *voucher))onSuccess
              onError:(void(^)(NSError *error))onError;

@end

#endif /* VOGiftManagerProtocol_h */
