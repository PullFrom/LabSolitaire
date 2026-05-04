// =====================================================================================================================
//  LocalPlayer.h
// =====================================================================================================================


#import <Foundation/Foundation.h>


@protocol LocalPlayerDelegate;


@interface LocalPlayer : NSObject
{
	NSString			*_playerID;
	NSString			*_displayName;
	BOOL				_authenticated;
	BOOL				_usingGameCenter;
	__weak id			_delegate;
}

@property(nonatomic,readonly)	NSString	*playerID;			// Only valid if using Game Center. Must be authenticated.
@property(nonatomic,readonly)	NSString	*displayName;		// Only valid if using Game Center. Must be authenticated.
@property(nonatomic,readonly)	BOOL		authenticated;		// Returns YES if authenticated (always YES if local).
@property(nonatomic,readonly)	BOOL		usingGameCenter;	// Returns YES if LocalPlayer is from Game Center.
@property(nonatomic,weak)		id <LocalPlayerDelegate>	delegate;	// Delegate called for asynchronous completions.

- (id) init;

// Submits a score to the Game Center leaderboard (if authenticated) or stores it locally via NSUserDefaults.
- (BOOL) postLeaderboardScore: (NSInteger) score forCategory: (NSString *) category;

- (void) postLocalScore: (NSInteger) score forCategory: (NSString *) category;

// Retrieves score from local NSUserDefaults. Returns YES if score for category was found.
- (BOOL) retrieveLocalScore: (NSInteger *) score forCategory: (NSString *) category;

@end


@protocol LocalPlayerDelegate<NSObject>

@optional

- (void) localPlayerAuthenticated: (LocalPlayer *) player;
- (void) localPlayer: (LocalPlayer *) player failedAuthenticationWithError: (NSError *) error;
- (void) localPlayer: (LocalPlayer *) player failedPostScoreForCategory: (NSString *) category error: (NSError *) error;
- (void) localPlayer: (LocalPlayer *) player needsToPresentAuthenticationViewController: (UIViewController *) viewController;

@end
