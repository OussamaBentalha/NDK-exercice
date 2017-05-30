package com.meoagency.android.fibonacci;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends Activity {

    TextView tv;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        new CalculateFibonacci().execute(Long.valueOf(30));
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    private class CalculateFibonacci extends AsyncTask<Long, Integer, String> {

        @Override
        protected String doInBackground(Long... inputs) {
            long input = inputs[0];
            long result, start, stop;
            String out = new String();

            start = System.currentTimeMillis();
            result = FibLib.fibJ(input);
            stop = System.currentTimeMillis();
            out += String.format("Java Recursive [%d] took: %d ms\n", result, stop-start);

            start = System.currentTimeMillis();
            result = FibLib.fibJI(input);
            stop = System.currentTimeMillis();
            out += String.format("Java Iterative [%d] took: %d ms\n", result, stop-start);

            start = System.currentTimeMillis();
            result = FibLib.fibN(input);
            stop = System.currentTimeMillis();
            out += String.format("Native Recursive [%d] took: %d ms\n", result, stop-start);

            start = System.currentTimeMillis();
            result = FibLib.fibNI(input);
            stop = System.currentTimeMillis();
            out += String.format("Native Iterative [%d] took: %d ms", result, stop-start);

            return out;
        }

        @Override
        protected void onPostExecute(String result) {
            // TODO Auto-generated method stub
            super.onPostExecute(result);
            Log.e(getClass().getSimpleName(), result);
        }

    }

    public static class FibLib {
        public static long fibJ (long input) {
            if (input <= 0)
                return 0;
            if (input == 1)
                return 1;
            return fibJ(input-1) +fibJ(input-2);
        }

        public static long fibJI (long input) {
            long previous = -1;
            long result = 1;
            for ( int i = 0; i <= input; i++ ){
                long sum = result + previous;
                previous = result;
                result = sum;
            }
            return result;
        }

        // Native implementation - recursive
        public static native long fibN(long n);

        // Native implementation - iterative
        public static native long fibNI(long n);
    }

}
