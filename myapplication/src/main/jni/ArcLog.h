#ifndef _______ARCLOG__H____
#define _______ARCLOG__H____

#include <stdio.h>
#define JNI_LOG

#ifdef JNI_LOG

#define LOG_TAG "ArcSoft_Log"

#include <android/log.h>

#define  LOGI(...)                  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)                  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)                  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGV(...)                  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)                  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)

#define FUNCTION_ENTER	LOGI("%s (in)", __FUNCTION__)
#define FUNCTION_QUIT	LOGI("%s (out)", __FUNCTION__)

#else
#define LOGD
#define LOGI
#define LOGW
#define LOGE
#define LOGF

#define FUNCTION_ENTER
#define FUNCTION_QUIT
#endif

#endif//_______ARCLOG__H____

