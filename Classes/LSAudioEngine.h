// =====================================================================================================================
//  LSAudioEngine.h
// =====================================================================================================================

#import <Foundation/Foundation.h>

@interface LSAudioEngine : NSObject

+ (instancetype)sharedEngine;
- (void)preloadEffect:(NSString *)filename;
- (void)playEffect:(NSString *)filename;

@end
