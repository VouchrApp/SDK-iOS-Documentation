# SDK-iOS-Documentation

# Getting Started

1. Add the SDK to your android project `build.gradle` file
```groovy
compile 'com.surpriise.libs:SurpriiseClaimSDK'
```

2. Create a `VouchrEngine`
```java
VouchrEngine.Builder engineBuilder = new VouchrEngine.Builder("server_base_url").setSdkId("SDK_ID");
engineBuilder.build();
```

# Create

### Setup

In order to send Vouchrs you need to setup a create configuration.
```java
CreateConfiguration createConfiguration = new CreateConfiguration.Builder()
    .setGiftItems(
                  new TipPersonalizationOption(context),
                  new TitlePersonalizationOption(),
                  new ToPersonalizationOption(),
                  new NotePersonalizationOption(),
                  new WrappingPaperPersonalizationOption(),
                  new GifPersonalizationOption(),
                  new ImagePersonalizationOption(),
                  new GiftCardPersonalizationOption(),
                  new VideoPersonalizationOption(),
                  new AudioPersonalizationOption())
    )
    .createConfig();
```
Then add it to your VouchrEngine

```java
engineBuilder.setCreateConfig(createConfiguration);
engineBuilder.build();
```

### Customization of Personalization Options
The Vouchr SDK comes with a robust set of `PersonalizationOptions` that can be customized and themed.
The following options can be changed for each one:
``` java
new ImagePersonalizationOption()
    .setImage(R.drawable.add_photo) // image that represent the option on the create screen
    .setTitle(R.string.add_an_image_to_tour_gift) // text to represent the option on the create screen
    .setTextColor(Color.WHITE); // color of the text on the create screen
    .analyticsName("PhotoCustomizationOption") // name used in analytics events
    .canAddMultiple(false); // determines if the user can add multiple or only one of this item in their Vouchr
```

Additionally there are specific customizations for each of the built in PersonalizationItem
```java
new ImagePersonalizationOption()
    .canUseCamera(true) // Can the user add photos from the camera
    .canUseGallery(true) // Can the user add photos from there phone gallery
    .canUseGoogleImages(true) // Can the user grab photos from Google
    .allowUserCustomSearch(false) // Can the user input there own search terms within google
```

### New Personalization Items
If you want to add your own custom `PersonaliztionOption`. All you have to do is extend `PersonalizationOption` and implement it's two abstract methods
```java

public void onItemClicked(View view, PendingVoucher pendingVoucher, LoadingBaseActivity activity, CreateUIUpdater UIUpdater) {
    //  Called when the Personalization Option is clicked. 
    //  Use this method to display customizations that the user can make to their Vouchr and call the UIUpdater if nesssary.
}

public void onItemRemoved(View view, PendingVoucher pendingVoucher, LoadingBaseActivity activity, CreateUIUpdater UIUpdater) {
    //  Called when a user attempts to remove a personalization. 
    //  Use this method to remove the option from the pendingVouchr and call UIUpdater if necessary.
}

```





