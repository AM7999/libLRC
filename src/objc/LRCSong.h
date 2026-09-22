#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LRCLyricLine : NSObject
@property (nonatomic, readonly) int64_t timestampMs;
@property (nonatomic, readonly, copy) NSString *text;
@end

@interface LRCSong : NSObject
@property (nonatomic, readonly, copy) NSString *title;
@property (nonatomic, readonly, copy) NSString *artist;
@property (nonatomic, readonly, copy) NSString *album;
@property (nonatomic, readonly) int64_t lengthMs; // -1 if absent
@property (nonatomic, readonly, copy) NSArray<LRCLyricLine *> *lyrics;
@end

NS_ASSUME_NONNULL_END
