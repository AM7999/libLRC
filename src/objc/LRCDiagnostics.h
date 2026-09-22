#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LRCSeverity) {
    LRCSeverityWarning,
    LRCSeverityError
};

NS_ASSUME_NONNULL_BEGIN

@interface LRCDiagnostic : NSObject
@property (nonatomic, readonly) LRCSeverity severity;
@property (nonatomic, readonly) NSInteger lineNumber;
@property (nonatomic, readonly, copy) NSString *line;
@property (nonatomic, readonly, copy) NSString *message;
@end

NS_ASSUME_NONNULL_END
