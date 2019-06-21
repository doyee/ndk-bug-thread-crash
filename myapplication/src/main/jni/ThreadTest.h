//
// Created by DDS on 2019-06-21.
//

#ifndef THREADQUEUEEXERCISE_THREADTEST_H
#define THREADQUEUEEXERCISE_THREADTEST_H

#include <jni.h>
#include <stdio.h>



#define CLAIM_EXTERN_C_START extern "C"{
#define CLAIM_EXTERN_C_END };
//the c style function declare start
CLAIM_EXTERN_C_START

void TEST_CreateEngine(void** phEngine);
void TEST_DestroyEngine(void** phEngine);

void TEST_AsynProcess(void* hEngine);
void TEST_AsncStop(void* hEngine);

//the c style function declare end.
CLAIM_EXTERN_C_END
#endif //THREADQUEUEEXERCISE_THREADTEST_H
