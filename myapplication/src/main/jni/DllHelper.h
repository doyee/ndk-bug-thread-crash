//
// Created by DDS on 2019-06-21.
//

#ifndef _THREADTESTDLOPEN_H
#define _THREADTESTDLOPEN_H
#ifdef __cplusplus
extern "C" {
#endif

typedef void (*FN_CreateEngine)(void** phEngine);
typedef void (*FN_DestroyEngine)(void** phEngine);
typedef void (*FN_AsynProcess)(void* hEngine);
typedef void (*FN_AsncStop)(void* hEngine);


//the dll export function
#define DLL_CreateEngine                 "TEST_CreateEngine"
#define DLL_DestroyEngine                "TEST_DestroyEngine"
#define DLL_AsynProcess                  "TEST_AsynProcess"
#define DLL_AsncStop                     "TEST_AsncStop"

//for processor dll handle struct
class DllHelper
{
    //the dll handle
    void*                  dlPtr;
    FN_CreateEngine        fnCreateEngine;
    FN_DestroyEngine       fnDestroyEngine;
    FN_AsynProcess         fnAsynProcess;
    FN_AsncStop            fnAsncStop;

public:
    DllHelper();

    ~DllHelper();

    void CreateEngine(void** phEngine);
    void DestroyEngine(void** phEngine);
    void AsynProcess(void* hEngine);
    void AsncStop(void* hEngine);
};

#ifdef __cplusplus
}
#endif

#endif //_THREADTESTDLOPEN_H
