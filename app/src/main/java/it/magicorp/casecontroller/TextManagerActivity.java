package it.magicorp.casecontroller;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import java.util.AbstractMap;
import java.util.Map;

import it.magicorp.casecontroller.utils.HttpUtils;

public class TextManagerActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        this.setContentView(R.layout.activity_text);

        final EditText editText = this.findViewById(R.id.phraseGen);

        Button setTextBtn = this.findViewById(R.id.setText);

        setTextBtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                HttpUtils.Post(new AbstractMap.SimpleEntry<String, Object>("phrase", editText.getText().toString().toUpperCase() + ":-48384"));
            }
        });
    }
}
