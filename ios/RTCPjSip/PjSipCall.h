#import <React/RCTUtils.h>
#import <VialerPJSIP/pjsua.h>

// sip headers have a 48 char limit. Future proofing to 256.
const MAX_HDR_LEN = 256;

@interface PjSipCall : NSObject

@property int id;
@property bool isHeld;
@property bool isMuted;
@property NSDictionary *headers;

+ (instancetype)itemConfig:(int)id;

- (void)hangup;
- (void)decline;
- (void)answer;
- (void)hold;
- (void)unhold;
- (void)mute;
- (void)unmute;
- (void)xfer:(NSString*) destination;
- (void)xferReplaces:(int) destinationCallId;
- (void)redirect:(NSString*) destination;
- (void)dtmf:(NSString*) digits;

- (void)onStateChanged:(pjsua_call_info) callInfo;
- (void)onMediaStateChanged:(pjsua_call_info) callInfo;

- (NSDictionary *)toJsonDictionary:(bool) isSpeaker;

@end
