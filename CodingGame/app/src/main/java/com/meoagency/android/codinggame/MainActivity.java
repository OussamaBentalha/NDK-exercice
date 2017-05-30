package com.meoagency.android.codinggame;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    EditText participants_ET;
    EditText prix_ET;
    EditText budget1_ET;
    EditText budget2_ET;
    EditText budget3_ET;

    Button button;

    int participants, prix, budget1, budget2, budget3;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //participants_ET = (EditText) findViewById(R.id.particiants);
        prix_ET = (EditText) findViewById(R.id.prix);

        budget1_ET = (EditText) findViewById(R.id.budget1);
        budget2_ET = (EditText) findViewById(R.id.budget2);
        budget3_ET = (EditText) findViewById(R.id.budget3);

        button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //participants = Integer.getInteger(participants_ET.getText().toString());
                prix = Integer.getInteger(prix_ET.getText().toString());
                budget1 = Integer.getInteger(budget1_ET.getText().toString());
                budget2 = Integer.getInteger(budget2_ET.getText().toString());
                budget3 = Integer.getInteger(budget3_ET.getText().toString());
                Toast.makeText(getApplicationContext(), "OK"+participants, Toast.LENGTH_SHORT).show();
            }
        });

        // Example of a call to a native method
        /*TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());*/
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
