package com.meoagency.android.codinggame;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Arrays;

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

        participants_ET = (EditText) findViewById(R.id.particiants);
        prix_ET = (EditText) findViewById(R.id.prix);

        budget1_ET = (EditText) findViewById(R.id.budget1);
        budget2_ET = (EditText) findViewById(R.id.budget2);
        budget3_ET = (EditText) findViewById(R.id.budget3);

        button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*String partString = participants_ET.getText().toString();
                participants = (int) Integer.valueOf(partString);*/
                participants = 3;

                String prixStr = prix_ET.getText().toString();
                prix = (int) Integer.valueOf(prixStr);

                String budgetStr = budget1_ET.getText().toString();
                budget1 = (int) Integer.valueOf(budgetStr);

                budgetStr = budget2_ET.getText().toString();
                budget2 = (int) Integer.valueOf(budgetStr);

                budgetStr = budget3_ET.getText().toString();
                budget3 = (int) Integer.valueOf(budgetStr);

                int[] resultat = codingGame(participants, prix, new int[]{budget1, budget2, budget3});

                Toast.makeText(getApplicationContext(), "Resultat : " + Arrays.toString(resultat), Toast.LENGTH_SHORT).show();
            }
        });
    }

    public native int[] codingGame(int participants, int prix, int[] budgets);

}
