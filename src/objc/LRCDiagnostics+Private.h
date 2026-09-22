#import "LRCDiagnostics.h"
#include <lrc/Diagnostics.hpp>

NS_ASSUME_NONNULL_BEGIN

@interface LRCDiagnostic ()
- (instancetype)initWithDiag:(const lrc::ParseDiag&)diag;
@end

NS_ASSUME_NONNULL_END
