package com.mochazi.easylog;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.mochazi.easylog.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'easylog' library on application startup.
    static {
        System.loadLibrary("easylog");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // 用途：新建的线程可以避免Android UI线程冲突
        // 步骤1：采用匿名类，直接 创建 线程类的实例
        new Thread("native-main") {
            // 步骤2：复写run（），内容 = 定义线程行为
            @Override
            public void run() {
                // 步骤3：通过 线程对象 控制线程的状态，如 运行、睡眠、挂起  / 停止
                MainFromJNI();
            }
        }.start();
    }

    /**
     * A native method that is implemented by the 'easylog' native library,
     * which is packaged with this application.
     */
    public native void MainFromJNI();
}