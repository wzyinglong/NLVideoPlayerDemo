//
//  NLWriterVideoRecordManager.h
//  NLVideoPlayer
//
//  Created by yj_zhang on 2018/5/22.
//  Copyright © 2018年 yj_zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "NLWriterVideoRecordViewController.h"

@protocol NLWriterVideoRecordManagerVCDelegate <NSObject>
//录制完成
-(void)recordFinishedWithOutputFileURL:(NSURL *)fileURL RecordTime:(CGFloat)recordTime;
//录制时间
-(void)reloadRecordTime:(CGFloat)time;
//隐藏闪光灯
-(void)lightIsHidden:(BOOL)isHidden;
//添加滤镜层
-(CVPixelBufferRef)showView:(CMSampleBufferRef)sampleBuffer;

@end

@protocol NLWriterVideoRecordManagerDelegate <NSObject>

@optional
//获取视频数据流
-(void)getVideoData:(NSData *)outputData URL:(NSURL *)outputURL;
//录制时间
-(void)getRecordTime:(CGFloat)time;
//录制封面
-(void)getRecordVideoCoverURL:(NSURL *)coverURL Image:(UIImage *)coverImage;
//获取视频数据流,录制封面
-(void)getVideoData:(NSData *)outputData DataURL:(NSURL *)outputURL CoverURL:(NSURL *)coverURL Image:(UIImage *)coverImage;

@end

@interface NLWriterVideoRecordManager : NSObject

@property(nonatomic,strong)AVCaptureSession *session;

@property(nonatomic,weak)id <NLWriterVideoRecordManagerVCDelegate>vcDelegate;

@property(nonatomic,weak)id <NLWriterVideoRecordManagerDelegate>delegate;

+(NLWriterVideoRecordManager *)shareVideoRecordManager;

+(UIViewController *)createRecordViewControllerWithRecordParam:(NLRecordParam *)param;
//配置参数
-(void)configVideoParamsWithRecordParam:(NLRecordParam *)param;
//开始画面采集
-(void)startSessionRunning;
//结束画面采集
-(void)stopSessionRunning;
//开始录制
-(void)startRecord;
//结束录制
-(void)stopRecord;
//清除输入源与输出源
-(void)removeOutputAndInput;
//保存视频
-(void)saveVideo;
//切换摄像头
-(void)turnCamera;
//闪光灯
-(void)changeLightWithState:(AVCaptureTorchMode)state;
//视频压缩
-(void)videoCompressionURL:(NSURL *)videoURL CompletionHandler:(void (^)(NSURL *))handler;

@end
