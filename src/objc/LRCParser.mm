#import "LRCParser+Private.h"
#import "LRCSong+Private.h"
#import "LRCDiagnostics+Private.h"
#include <fstream>

@implementation LRCParseResult {
    lrc::Result _result;
}

- (instancetype)initWithResult:(lrc::Result&&)result {
    if (self = [super init]) { _result = std::move(result); }
    return self;
}

- (BOOL)hasErrors { return _result.hasErrors() ? YES : NO; }

- (NSArray<LRCDiagnostic *> *)diagnostics {
    NSMutableArray<LRCDiagnostic *> *out = [NSMutableArray array];
    for (const auto& diag : _result.diagnostics) {
        [out addObject:[[LRCDiagnostic alloc] initWithDiag:diag]];
    }
    return out;
}

- (LRCSong *)song {
    return [[LRCSong alloc] initWithSong:_result.song];
}

@end

@implementation LRCParser {
    lrc::Parser _parser;
}

- (LRCParseResult *)parseText:(NSString *)text {
    std::string cppText = std::string([text UTF8String]);
    return [[LRCParseResult alloc] initWithResult:_parser.parse(cppText)];
}

- (nullable LRCParseResult *)parseFileAtPath:(NSString *)path {
    std::ifstream stream([path UTF8String]);
    if (!stream.is_open()) return nil;
    return [[LRCParseResult alloc] initWithResult:_parser.parseFile(stream)];
}

@end
