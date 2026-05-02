// =====================================================================================================================
//  LabSolitaireAppDelegate.h
// =====================================================================================================================


#import <UIKit/UIKit.h>


@class LabSolitaireViewController;


@interface LabSolitaireAppDelegate : NSObject <UIApplicationDelegate>
{
	UIWindow				*_window;
	LabSolitaireViewController	*_viewController;
}

@property (nonatomic, strong) IBOutlet UIWindow					*_window;
@property (nonatomic, strong) IBOutlet LabSolitaireViewController	*_viewController;

@end

