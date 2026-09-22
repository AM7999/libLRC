#import "LRCDiagnostics+Private.h"

@implementation LRCDiagnostic {
    lrc::ParseDiag _diag;
}

- (instancetype)initWithDiag:(const lrc::ParseDiag&)diag {
    if (self = [super init]) { _diag = diag; }
    return self;
}

- (LRCSeverity)severity {
    return _diag.sv == lrc::Severity::Error ? LRCSeverityError : LRCSeverityWarning;
}
- (NSInteger)lineNumber { return (NSInteger)_diag.lineNumber; }
- (NSString *)line    { return [NSString stringWithUTF8String:_diag.line.c_str()]; }
- (NSString *)message { return [NSString stringWithUTF8String:_diag.message.c_str()]; }

@end
