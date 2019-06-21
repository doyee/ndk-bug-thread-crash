
#include <jni.h>
#include <stdio.h>
#include <thread>
#include <android/log.h>
#include <time.h>
#include "ArcLog.h"
#include "DllHelper.h"

#define CLAIM_EXTERN_C_START extern "C"{
#define CLAIM_EXTERN_C_END };
//the c style function declare start
CLAIM_EXTERN_C_START

void* gCoreEngine;
//DllHelper helper;
JNIEXPORT void JNICALL
Java_com_arcsoft_myapplication_JNITest_nvJNITestStart(JNIEnv *env, jobject thiz) {
    DllHelper helper;
    helper.CreateEngine(&gCoreEngine);
    helper.AsynProcess(gCoreEngine);
}

JNIEXPORT void JNICALL
Java_com_arcsoft_myapplication_JNITest_nvJNITestStop(JNIEnv *env, jobject thiz) {
    DllHelper helper;
    helper.AsncStop(gCoreEngine);
    helper.DestroyEngine(&gCoreEngine);
}


//the c style function declare end.
CLAIM_EXTERN_C_END