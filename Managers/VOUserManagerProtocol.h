//
//  VOUserManagerProtocol.h
//  VouchrSDK
//
//  Created by Jeff Lee on 2017-12-18.
//  Copyright © 2017 Vouchr. All rights reserved.
//

#ifndef VOUserManagerProtocol_h
#define VOUserManagerProtocol_h

@protocol VORefreshTokenProtocol;

@class User, Credential;

@protocol VOUserManagerProtocol

@property (nonatomic, strong, readonly) User *myProfile;
@property (nonatomic, readonly) long long myUserId;

/*
 * Login a user to the vouchr servers
 * after a successful login, `myUserId` & `myProfile` will be populated until logout is called or the token expires
 *
 * @param credentials - the credentials of the logging in user required for Vouchr's Servers
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 */
- (void)loginWithCredentials:(Credential *)credentials
          tokenRefreshClient:(id<VORefreshTokenProtocol>)tokenRefreshClient
                   onSuccess:(void(^)(void))onSucceed
                     onError:(void(^)(NSError* error))onError;


/*
 * logout the logged in user
 * this will clear all tokens, cache, persistence of anything related to login
 */
- (void)logout;


/*
 * returns whether a user is logged in or not
 */
- (BOOL)isLoggedIn;


/*
 * refresh's the current credentials with Vouchr's Servers
 */
- (void)refreshTokenOnCompletion:(void (^)(void))onCompletion;

/*
 * requests a profile from server and returns the user object when completed
 * the user object will automatically be cached if a cache manager is set
 *
 * @param uid - the user id of the profile being requested
 * @param forceUpdate - if true, gets the user from cache if possible
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 */
- (void)requestProfileWithId:(long long)uid
                 forceUpdate:(BOOL)forceUpdate
                   onSuccess:(void(^)(User *))onSucceed
                     onError:(void(^)(NSError *))onError;

/*
 * updates the user's profile from server and returns the new user object when completed
 * the user object will automatically be cached if a cache manager is set
 *
 * @param changes - the dictionary of changes being sent to the server
 * @param onSuccess - success callblock when the request completes
 * @param onError - error callblock if the request fails
 *
 */
-(void)updateProfileWithChanges:(NSDictionary*)changes
                      onSuccess:(void(^)(User *))onSucceed
                        onError:(void(^)(NSError *))onError;

/*
 * adds a user to the cache manager if a cache manager is set
 * if the user exists in cache and this is not the full profile, the user will not be cached
 *
 * NOTE: this should never be called by not-the-SDK - TODO: make this private to non-SDK
 *
 * @param newUser - the user to be added
 * @param isFullProfile - is the profile of the user full
 *
 */
// TODO: remove this from protocol
- (void)addUser:(User *)newUser isFullProfile:(BOOL)isFullProfile;

/*
 * sets the user id of the logged in user
 *
 * NOTE: this should never be called by not-the-SDK - TODO: make this private to non-SDK
 *
 * @param userId - the user id of the logged in user
 *
 */
-(void)setMyUserId:(long long)userId;


/*
 * gets the friends of the logged in user
 *
 * @param shouldForce - true if it should skip the cache
 * @param onSuccess - call block when request completes
 * @param onError - call block if an error occurs during the request
 *
 */
-(void)requestMyFriendsShouldForce:(BOOL)shouldForce
                         onSuccess:(void(^)(NSArray <User *> *friends))onSuccess
                           onError:(void(^)(NSError *error))onError;

@end

#endif /* VOUserManagerProtocol_h */
