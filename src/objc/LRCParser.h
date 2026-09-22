#import <Foundation/Foundation.h>
#import "LRCSong.h"
#import "LRCDiagnostics.h"

NS_ASSUME_NONNULL_BEGIN

@interface LRCParseResult : NSObject
@property (nonatomic, readonly) BOOL hasErrors;
@property (nonatomic, readonly, copy) NSArray<LRCDiagnostic *> *diagnostics;
@property (nonatomic, readonly) LRCSong *song;
@end

@interface LRCParser : NSObject
- (LRCParseResult *)parseText:(NSString *)text;
- (nullable LRCParseResult *)parseFileAtPath:(NSString *)path;
@end

NS_ASSUME_NONNULL_END
