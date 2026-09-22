#import "LRCSong+Private.h"

@implementation LRCLyricLine {
    lrc::Lyric _lyric;
}

- (instancetype)initWithLyric:(const lrc::Lyric&)lyric {
    if (self = [super init]) { _lyric = lyric; }
    return self;
}
- (int64_t)timestampMs { return _lyric.ts.ms; }
- (NSString *)text { return [NSString stringWithUTF8String:_lyric.lyric.c_str()]; }

@end

@implementation LRCSong {
    lrc::Song _song; // C++ member — fine in an Obj-C++ class
}

- (instancetype)initWithSong:(const lrc::Song&)song {
    if (self = [super init]) { _song = song; }
    return self;
}

- (NSString *)title  { return [NSString stringWithUTF8String:_song.title().c_str()]; }
- (NSString *)artist { return [NSString stringWithUTF8String:_song.artist().c_str()]; }
- (NSString *)album  { return [NSString stringWithUTF8String:_song.album().c_str()]; }

- (int64_t)lengthMs {
    auto len = _song.length();
    return len.has_value() ? len->ms : -1;
}

- (NSArray<LRCLyricLine *> *)lyrics {
    NSMutableArray<LRCLyricLine *> *out = [NSMutableArray array];
    for (const auto& lyric : _song.lyrics()) {
        [out addObject:[[LRCLyricLine alloc] initWithLyric:lyric]];
    }
    return out;
}

@end
