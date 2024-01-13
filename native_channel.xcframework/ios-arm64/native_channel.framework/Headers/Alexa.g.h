// Autogenerated from Pigeon (v10.1.6), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#import <Foundation/Foundation.h>

@protocol FlutterBinaryMessenger;
@protocol FlutterMessageCodec;
@class FlutterError;
@class FlutterStandardTypedData;

NS_ASSUME_NONNULL_BEGIN

@class ApiAlexaError;

/// 异常信息
@interface ApiAlexaError : NSObject
+ (instancetype)makeWithErrorCode:(nullable NSNumber *)errorCode
    errorMessage:(nullable NSString *)errorMessage
    extData:(nullable NSDictionary<NSString *, NSString *> *)extData;
@property(nonatomic, strong, nullable) NSNumber * errorCode;
@property(nonatomic, copy, nullable) NSString * errorMessage;
@property(nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> * extData;
@end

/// The codec used by ApiAlexaHost.
NSObject<FlutterMessageCodec> *ApiAlexaHostGetCodec(void);

@protocol ApiAlexaHost
/// token 变更，空为退出状态
- (void)onTokenChangedToken:(nullable NSString *)token error:(FlutterError *_Nullable *_Nonnull)error;
/// 创建下行流
- (void)createDownStreamUrl:(NSString *)url completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// 关闭下行流
- (void)closeDownStreamWithCompletion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// 创建上行流 注：流数据由 askAudioData(Uint8List data, bool isEnd) 提供
/// url 请求地址
/// jsonBody 参数
- (void)createUploadStreamUrl:(NSString *)url jsonBody:(FlutterStandardTypedData *)jsonBody completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// 关闭上行流
- (void)closeUploadStreamWithCompletion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// ask 音频流数据（由设备采集）
- (void)askAudioDataData:(FlutterStandardTypedData *)data isEnd:(NSNumber *)isEnd error:(FlutterError *_Nullable *_Nonnull)error;
@end

extern void ApiAlexaHostSetup(id<FlutterBinaryMessenger> binaryMessenger, NSObject<ApiAlexaHost> *_Nullable api);

/// The codec used by ApiAlexaFlutter.
NSObject<FlutterMessageCodec> *ApiAlexaFlutterGetCodec(void);

@interface ApiAlexaFlutter : NSObject
- (instancetype)initWithBinaryMessenger:(id<FlutterBinaryMessenger>)binaryMessenger;
/// reply 数据 (由Alexa上行流回复)，正常是由json和音频数据组成
///
/// messageId 消息id
/// data 上行流收到的alex回复数据
/// isEnd 完成
- (void)replyAudioDataMessageId:(NSString *)messageId data:(FlutterStandardTypedData *)data isEnd:(NSNumber *)isEnd completion:(void (^)(FlutterError *_Nullable))completion;
/// 上行流异常
- (void)onUploadStreamErrorError:(ApiAlexaError *)error completion:(void (^)(FlutterError *_Nullable))completion;
/// 下行流响应数据
///
/// data 上行流收到的alex回复数据
- (void)downStreamDataData:(FlutterStandardTypedData *)data completion:(void (^)(FlutterError *_Nullable))completion;
/// 下行流异常
- (void)onDownStreamErrorError:(ApiAlexaError *)error completion:(void (^)(FlutterError *_Nullable))completion;
- (void)logLogMsg:(NSString *)logMsg completion:(void (^)(FlutterError *_Nullable))completion;
@end

NS_ASSUME_NONNULL_END
