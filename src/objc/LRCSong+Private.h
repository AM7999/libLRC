#import "LRCSong.h"
#include <lrc/Song.hpp>
#include <lrc/Lyric.hpp>

NS_ASSUME_NONNULL_BEGIN

@interface LRCSong ()
- (instancetype)initWithSong:(const lrc::Song&)song;
@end

@interface LRCLyricLine ()
- (instancetype)initWithLyric:(const lrc::Lyric&)lyric;
@end

NS_ASSUME_NONNULL_END
