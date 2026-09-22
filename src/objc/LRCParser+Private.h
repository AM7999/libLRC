#import "LRCParser.h"
#include <lrc/Parser.hpp>

NS_ASSUME_NONNULL_BEGIN

@interface LRCParseResult ()
- (instancetype)initWithResult:(lrc::Result&&)result;
@end

NS_ASSUME_NONNULL_END
