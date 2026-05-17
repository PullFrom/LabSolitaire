// =====================================================================================================================
//  LabSolitaireViewController.h
// =====================================================================================================================


#import <AVFoundation/AVFoundation.h>
#import <GameKit/GameKit.h>
#import <UIKit/UIKit.h>
#import "CardEngine.h"
#import "LocalPlayer.h"


#define kNumCardDrawSounds		4
#define kNumCardPlaceSounds		4


@class LSStackView;


@interface LabSolitaireViewController : UIViewController <CEStackViewDelegate, LocalPlayerDelegate, GKGameCenterControllerDelegate>
{
	LSStackView					*_cellViews[4];
	LSStackView					*_foundationViews[4];
	LSStackView					*_tableauViews[8];
	UIButton					*_newButton;
	UIButton					*_undoButton;
	UIButton					*_infoButton;
	UIInterfaceOrientation		_orientation;
	BOOL						_initialLayoutApplied;
	NSTimer						*_putawayTimer;
	NSTimer						*_undoHeldTimer;
	BOOL						_undoAllAlertOpen;
	BOOL						_playedAtleastOneCard;
	BOOL						_gameWon;
	BOOL						_autoPutaway;
	NSInteger					_autoPutawayMode;
	BOOL						_allPutaway;
	BOOL						_playSounds;
	BOOL						_wasAutoPutaway;
	NSInteger					_wasAutoPutawayMode;
	BOOL						_infoViewIsOpen;
	int							_dragRestriction;
	BOOL						_splashDismissed;
	NSMutableArray				*_worriedCards;
	LocalPlayer					*_localPlayer;
	NSUInteger					_dealIndex;
	UIView						*_currentInfoView;							// Weak reference.
	UIView						*_rotatingView;
	UIView						*_darkView;
	UIImageView					*_paperBackgroundView;
	UIView						*_infoView;
	UIView						*_overlayingView;							// Weak reference.
	IBOutlet UIView				*_aboutView;
	IBOutlet UIView				*_settingsView;
	IBOutlet UIView				*_rulesView;
	IBOutlet UIView				*_gameOverView;
	IBOutlet UIButton			*_autoPutawayButton;
	IBOutlet UIButton			*_allPutawayButton;
	IBOutlet UIButton			*_smartPutawayButton;
	IBOutlet UILabel			*_smartPutawayModeLabel;
	IBOutlet UIImageView		*_putawaySelectedImage;
	IBOutlet UIButton			*_playSoundsButton;
	IBOutlet UILabel			*_gamesPlayedLabel;
	IBOutlet UILabel			*_gamesWonLabel;
	IBOutlet UILabel			*_gamesWonPercentageLabel;
	IBOutlet UILabel			*_personalScoreLabel;
	IBOutlet UIButton			*_gameCenterButton;
}

- (void) createCardTableLayout;
- (void) openSplashAfterDelay;
- (void) saveState;
- (void) restoreState;

- (IBAction) info: (id) sender;
- (IBAction) aboutInfo: (id) sender;
- (IBAction) openLabSolitaireInAppStore: (id) sender;
- (IBAction) openParlourSolitaireInAppStore: (id) sender;
- (IBAction) openGliderInAppStore: (id) sender;
- (IBAction) settingsInfo: (id) sender;
- (IBAction) rulesInfo: (id) sender;
- (IBAction) closeInfo: (id) sender;
- (IBAction) toggleAutoPutaway: (id) sender;
- (IBAction) selectAutoPutawayMode: (id) sender;
- (IBAction) toggleSound: (id) sender;
- (IBAction) openGameCenter: (id) sender;
- (IBAction) openGameOverView: (id) sender;

@end
