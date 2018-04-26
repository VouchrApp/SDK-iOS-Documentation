# Integrating the SDK

1. Add the SDK to your project via CocoaPods by adding the following line to your Podfile. 
```
pod `VouchrSDK`
```
Run a navigate to your project directory in Terminal and run: 
``pod install`` 
Note: Your Xcode project must be opened using the .xcworkspace file, not the .xcodeproj file.


# Setup

2. Create a `VouchrEngine`
```objective-c
self.vouchrEngineSDK = [VouchrEngine vouchrEngineWithBuilder:^(VouchrEngineBuilder *builder) {
        builder.cacheManager = [CacheManager new];
        builder.networkManager = [NetworkManager new];
        builder.persistManager = [[PersistManager alloc] initWithUserDefaults:[NSUserDefaults standardUserDefaults]];
        builder.userManager = [[UserManager alloc] initWithCacheManager:builder.cacheManager networkManager:builder.networkManager persistManager:builder.persistManager];
        builder.voucherManager = [[VoucherManager alloc] initWithNetworkManager:builder.networkManager cacheManager:builder.cacheManager];
        builder.wrappingPaperManager = [[WrappingPaperManager alloc] initWithNetworkManager:builder.networkManager];
    }];
```

Instantiate a VoucherCreationManager:
```objective-c
VoucherCreationManager *creationManager = [VoucherCreationManager voucherCreationManagerWithBuilder:^(VoucherCreationManagerBuilder *builder) {
        builder.networkManager = [[VouchrEngine instance] networkManager];
        builder.wrappingPaperManager = [[VouchrEngine instance] wrappingPaperManager];
        builder.userManager = [[VouchrEngine instance] userManager];
        builder.giftManager = [[VouchrEngine instance] giftManager];
        builder.fullScreenLoadingView = [[SurpriiseLoadingView alloc] initWithFrame:CGRectZero];
        builder.alwaysShowFullSummaryScreen = YES;
    }];
```
Instantiate a VoucherCreationFlowCoordinator:
```objective-c
self.voucherCreationFlowCoordinator = [VoucherCreationFlowCoordinator voucherCreationFlowCoordinatorWithManager:creationManager
                                                                                                       themeManager:self.themeManager
                                                                                                           delegate:self];
```

Instantiate PersonalizationOptions for all personalizations that will be available to the user.
```objective-c
NSMutableArray <PersonalizationOption *> *personalizationOptions = [NSMutableArray new];
    [personalizationOptions addObject:[RecipientPersonalizationOption recipientPersonalizationOptionWithBuilder:^(RecipientPersonalizationOptionBuilder *builder) {
        builder.themeManager = [self recipientThemeManager];
        builder.canChangeUnwrapDate = YES;
        builder.canMakeItARace = YES;
        builder.canSendToEmail = YES;
        builder.canSendToPhoneNumber = YES;
    }]];
    
    [personalizationOptions addObject:[TitlePersonalizationOption titlePersonalizationOptionWithBuilder:^(TitlePersonalizationOptionBuilder *builder) {
        builder.themeManager = [self recipientThemeManager];
    }]];
    
    [personalizationOptions addObject:[PhotoPersonalizationOption photoPersonalizationOptionWithBuilder:^(PhotoPersonalizationOptionBuilder *builder) {
        builder.themeManager = self.themeManager;
        builder.canAddMultiple = NO;
        builder.canUploadPhotos = NO;
        builder.canAddGoogleImages = YES;
        builder.canTakePhotos = YES;
        builder.suggestedSearchTerms = @[@"one", @"two", @"three"];
    }]];
```

Start the Voucher Creation flow:
```objective-c
[self.voucherCreationFlowCoordinator startFlowOnViewController:self.selectedViewController personalizationOptions:personalizationOptions];
```
