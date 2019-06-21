package com.arcsoft.myapplication;

public class JNITest {

    static {
        System.loadLibrary("JNITest");
    }
    public native void nvJNITestStart();

    public native void nvJNITestStop();
}
