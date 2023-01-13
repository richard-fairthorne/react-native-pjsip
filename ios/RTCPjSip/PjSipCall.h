#import <React/RCTUtils.h>
#import <VialerPJSIP/pjsua.h>

@interface PjSipCall : NSObject

@property int id;
@property bool isHeld;
@property bool isMuted;
@property NSMutableDictionary *headers;

+ (instancetype)itemConfig:(int)id;
+ (instancetype)itemConfig:(int)id rxData:(pjsip_rx_data*)rx;

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
