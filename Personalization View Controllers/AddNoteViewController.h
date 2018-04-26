//
//  AddNoteViewController.h
//  Pods
//
//  Created by Mark Hetherington on 2017-05-31.
//
//

#import <UIKit/UIKit.h>
#import "PersonalizationOptionViewControllerProtocol.h"


@protocol VOTrackManagerProtocol;
@class VoucherCreationManager, NoteMedia, PersonalizationOption;

@protocol AddNoteViewControllerDelegate <NSObject>

/**
 This delegate callback occurs when the user has finished creating a note.
 @param note - The `NoteMedia` containing information about the created note.
 @param noteView - The styled `UIView` containing the note, to be used to render and dropped in envelope.
 **/
- (void)didAddNote:(NoteMedia *)note noteView:(UIView *)noteView;

@end

@interface AddNoteViewController : UIViewController

/**
 Default instantiation method for `AddNoteViewController`
 @param personalizationOption - contains the configuration options for the note creation
 @param creationManager - the manager responsible for handling the flow management in the creation process.
 @param delegate - the object responsible for implementing CreateddTitleViewController callbacks
 @return an instance of CreateAddTitleViewController
 **/
+ (instancetype)viewControllerWithPersonalizationOption:(PersonalizationOption *)personalizationOption
                                                  notes:(NSArray<NoteMedia *> *)notes
                                        creationManager:(VoucherCreationManager *)creationManager
                                               delegate:(id<AddNoteViewControllerDelegate>)delegate;

@end
