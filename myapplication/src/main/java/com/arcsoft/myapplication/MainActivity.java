package com.arcsoft.myapplication;

import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    Button mTestButton;
    JNITest mTest;
    UpdataUIRunnable mUIUpdate;
    Button mBatButton;
    TextView mUiProgress;

    static class UpdataUIRunnable implements Runnable{
        TextView mTVProgress;
        int mProgress;
        @Override
        public void run() {
            if(null != mTVProgress){
                mTVProgress.setText(String.valueOf(mProgress));
            }
        }

        public void setTVProgress(TextView tv, int progress){
            mTVProgress = tv;
            mProgress = progress;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTest = new JNITest();

        mTestButton = findViewById(R.id.test_button);
        mTestButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final Integer TEST_START = 0x1001;
                final Integer TEST_STOP = 0x1002;
                Integer action = (Integer) mTestButton.getTag();
                if(null == action || 0 == action.compareTo(TEST_STOP)){
                    mTest.nvJNITestStart();

                    mTestButton.setTag(TEST_START);
                    mTestButton.setText("Stop Test");

                }else{
                    mTest.nvJNITestStop();

                    mTestButton.setTag(TEST_STOP);
                    mTestButton.setText("Start Test");
                }
            }
        });

        mBatButton = findViewById(R.id.bat_start_stop);
        mUiProgress = findViewById(R.id.text_progress);
        mUIUpdate = new UpdataUIRunnable();



        mBatButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mBatButton.setEnabled(false);
                runSeveralTimes();
            }
        });
    }


    private void asyncStart(){
        mTest.nvJNITestStart();
        /*Thread mThread = new Thread(new Runnable() {
            @Override
            public void run() {
                mTest.nvJNITestStart();
            }
        });
        mThread.start();
        try{
            mThread.join();
        }catch (Exception ex){
            ex.printStackTrace();
        }*/
    }

    private void asyncStop(){
        mTest.nvJNITestStop();
        /*Thread mThread = new Thread(new Runnable() {
            @Override
            public void run() {
                mTest.nvJNITestStop();
            }
        });
        mThread.start();
        try{
            mThread.join();
        }catch (Exception ex){
            ex.printStackTrace();
        }*/
    }

    private void runSeveralTimes(){
        Thread mThread = new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i = 1 ; i <= 1000; i++){
                    asyncStart();
                    SystemClock.sleep(100);
                    asyncStop();

                    mUIUpdate.setTVProgress(mUiProgress,i);
                    MainActivity.this.runOnUiThread(mUIUpdate);
                }

                MainActivity.this.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        mBatButton.setEnabled(true);
                    }
                });
            }
        });
        mThread.start();
    }
}
