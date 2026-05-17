// =====================================================================================================================
//  LSAudioEngine.m
// =====================================================================================================================

#import <AVFoundation/AVFoundation.h>
#import "LSAudioEngine.h"


@implementation LSAudioEngine
{
    NSMutableDictionary<NSString *, AVAudioPlayer *> *_players;
}

+ (instancetype)sharedEngine
{
    static LSAudioEngine *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[LSAudioEngine alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        _players = [[NSMutableDictionary alloc] init];

        NSError *error = nil;
        [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryAmbient error:&error];
        if (error)
            NSLog(@"LSAudioEngine: failed to set audio session category: %@", error);
    }
    return self;
}

- (NSURL *)urlForFilename:(NSString *)filename
{
    NSString *name = [filename stringByDeletingPathExtension];
    NSString *ext = [filename pathExtension];
    NSURL *url = [[NSBundle mainBundle] URLForResource:name withExtension:ext];
    if (url == nil)
        NSLog(@"LSAudioEngine: sound file not found in bundle: %@", filename);
    return url;
}

- (void)preloadEffect:(NSString *)filename
{
    if (_players[filename] != nil)
        return;

    NSURL *url = [self urlForFilename:filename];
    if (url == nil)
        return;

    NSError *error = nil;
    AVAudioPlayer *player = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];
    if (player == nil)
    {
        NSLog(@"LSAudioEngine: failed to create player for %@: %@", filename, error);
        return;
    }

    [player prepareToPlay];
    _players[filename] = player;
}

- (void)playEffect:(NSString *)filename
{
    AVAudioPlayer *player = _players[filename];

    if (player == nil)
    {
        [self preloadEffect:filename];
        player = _players[filename];
        if (player == nil)
            return;
    }

    if ([player isPlaying])
    {
        NSError *error = nil;
        AVAudioPlayer *duplicate = [[AVAudioPlayer alloc] initWithContentsOfURL:[player url] error:&error];
        if (duplicate)
        {
            [duplicate play];
        }
    }
    else
    {
        player.currentTime = 0;
        [player play];
    }
}

@end
