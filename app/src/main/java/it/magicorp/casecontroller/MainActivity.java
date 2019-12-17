package it.magicorp.casecontroller;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(final Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        this.setContentView(R.layout.activity_main);


        Button colourManager = this.findViewById(R.id.colourManager);

        colourManager.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                MainActivity.this.startActivity(new Intent(MainActivity.this, ColourManagerActivity.class));
            }
        });

        Button textManager = this.findViewById(R.id.textManager);

        textManager.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                MainActivity.this.startActivity(new Intent(MainActivity.this, TextManagerActivity.class));
            }
        });
    }
}
