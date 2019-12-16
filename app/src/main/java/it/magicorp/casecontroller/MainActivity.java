package it.magicorp.casecontroller;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import java.util.AbstractMap;

public class MainActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btn = this.findViewById(R.id.testRed);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                HttpUtils.Post(new AbstractMap.SimpleEntry<String, Object>("colour", "255:0:0"));
            }
        });
    }
}
