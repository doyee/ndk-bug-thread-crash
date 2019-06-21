//
// Created by DDS on 2019-06-21.
//
#include <thread>
#include <android/log.h>
#include <time.h>
#include "ArcLog.h"
#include "ThreadTest.h"

typedef std::thread ThreadStd;
class TaskLogic{
public:
    TaskLogic():mThread(),mExit(false){
        LOGD( "TaskLogic constructor");
    }

    ~TaskLogic(){
        LOGD( "TaskLogic destructor");
    }

    void async_process(){
        mThread = ThreadStd(TaskLogic::ThreadCallback,this);
    }

    void force_quit_process(){
        mExit = true;
        if(mThread.joinable())
        {
            LOGD("force_quit_process A");
            LOGD("force_quit_process A mThread:id 0x%lu",mThread.get_id());
            mThread.join();
            LOGD("force_quit_process B mThread:id 0x%lu",mThread.get_id());
            LOGD("force_quit_process B");
        }
    }

private:
    void internal_process(){
        auto id = mThread.get_id();
        LOGD("internal_process mThread:id 0x%lu",id);
        do{
            LOGD("internal_process A");
            std::this_thread::sleep_for(std::chrono::microseconds(3));
            LOGD("internal_process B");
        }while(!mExit);
        LOGD("internal_process C");
    }

    static void ThreadCallback(TaskLogic* thiz){
        LOGD("TaskLogic in");
        thiz->internal_process();
        LOGD("TaskLogic out");
    }

private:
    ThreadStd mThread;
    bool mExit;
};

void TEST_CreateEngine(void** phEngine){
    if(nullptr == phEngine){
        return;
    }
    TaskLogic* pIns = new TaskLogic();
    *phEngine = (void*)pIns;
}

void TEST_DestroyEngine(void** phEngine){
    if(nullptr == phEngine || nullptr == (*phEngine)){
        return;
    }
    TaskLogic* pIns = (TaskLogic*)(*phEngine);
    delete pIns;
    *phEngine = nullptr;
}

void TEST_AsynProcess(void* hEngine){
    if(nullptr == hEngine){
        return;
    }
    TaskLogic* pIns = (TaskLogic*)(hEngine);
    pIns->async_process();
}

void TEST_AsncStop(void* hEngine){
    if(nullptr == hEngine){
        return;
    }
    TaskLogic* pIns = (TaskLogic*)(hEngine);
    pIns->force_quit_process();
}