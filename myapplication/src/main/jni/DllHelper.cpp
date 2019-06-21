
#include "ArcLog.h"
#include "DllHelper.h"
#include <dlfcn.h>

DllHelper::DllHelper(){
    LOGD("DllHelper::DllHelper");
    // dlopen and dlsym here and if successful, create zoom translator object
    const char* szLibPath = "libThreadTest.so";
    dlPtr = dlopen(szLibPath, RTLD_NOW);
    if (!dlPtr) {
        const char *error = dlerror();
        LOGE("arcsoft-dlopen-failed-with-error %s", error ? error : "");
        return ;
    }

    fnCreateEngine          = (FN_CreateEngine)dlsym(dlPtr, DLL_CreateEngine);
    fnDestroyEngine         = (FN_DestroyEngine)dlsym(dlPtr, DLL_DestroyEngine);
    fnAsynProcess           = (FN_AsynProcess)dlsym(dlPtr, DLL_AsynProcess);
    fnAsncStop              = (FN_AsncStop)dlsym(dlPtr, DLL_AsncStop);

    if (!dlPtr               ||
        !fnCreateEngine      ||
        !fnDestroyEngine     ||
        !fnAsynProcess       ||
        !fnAsncStop )
    {

        if(dlPtr)
        {
            dlclose(dlPtr);
            dlPtr = nullptr;
        }
        LOGE("arcsoft dlsym failed");
    }
}

DllHelper::~DllHelper(){
    if(dlPtr)
    {
        dlclose(dlPtr);
        dlPtr = nullptr;
    }
}

void DllHelper::CreateEngine(void** phEngine)
{
    (*fnCreateEngine)(phEngine);
}

void DllHelper::DestroyEngine(void **phEngine)
{
    (*fnCreateEngine)(phEngine);
}

void DllHelper::AsynProcess(void* hEngine)
{
    (*fnAsynProcess)(hEngine);
}

void DllHelper::AsncStop(void* hEngine)
{
    (*fnAsncStop)(hEngine);
}
