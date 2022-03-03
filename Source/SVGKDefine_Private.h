/**
SVGKDefine_Private.h

SVGKDefine define some common macro used for private header.
*/

#ifndef SVGKDefine_Private_h
#define SVGKDefine_Private_h

#import "SVGKDefine.h"
@import CocoaLumberjack;

// These macro is only used inside framework project, does not expose to public header and effect user's define

#define SVGKIT_LOG_CONTEXT 556

#define SVGKitLogWithControl(async, level, frmt, ...)                                                                  \
    do {                                                                                                               \
        if (enableSVGKitLog) {                                                                                         \
            LOG_MAYBE(async, LOG_LEVEL_DEF, level, SVGKIT_LOG_CONTEXT, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__); \
        }                                                                                                              \
    } while (NO);


#define SVGKitLogError(frmt, ...)   SVGKitLogWithControl(NO,                DDLogFlagError,     frmt, ##__VA_ARGS__)
#define SVGKitLogWarn(frmt, ...)    SVGKitLogWithControl(LOG_ASYNC_ENABLED, DDLogFlagWarning,   frmt, ##__VA_ARGS__)
#define SVGKitLogInfo(frmt, ...)    SVGKitLogWithControl(LOG_ASYNC_ENABLED, DDLogFlagInfo,      frmt, ##__VA_ARGS__)
#define SVGKitLogDebug(frmt, ...)   SVGKitLogWithControl(LOG_ASYNC_ENABLED, DDLogFlagDebug,     frmt, ##__VA_ARGS__)
#define SVGKitLogVerbose(frmt, ...) SVGKitLogWithControl(LOG_ASYNC_ENABLED, DDLogFlagVerbose,   frmt, ##__VA_ARGS__)

#if DEBUG
static const int ddLogLevel = DDLogLevelVerbose;
#else
static const int ddLogLevel = DDLogLevelWarning;
#endif

#if SVGKIT_MAC
#define NSStringFromCGRect(rect) NSStringFromRect(rect)
#define NSStringFromCGSize(size) NSStringFromSize(size)
#define NSStringFromCGPoint(point) NSStringFromPoint(point)
#endif

#endif /* SVGKDefine_Private_h */
