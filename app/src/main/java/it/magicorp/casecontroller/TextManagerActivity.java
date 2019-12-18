package it.magicorp.casecontroller;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import com.larswerkman.holocolorpicker.ColorPicker;

import java.util.AbstractMap;

import it.magicorp.casecontroller.utils.ColorUtils;
import it.magicorp.casecontroller.utils.HttpUtils;

public class TextManagerActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        this.setContentView(R.layout.activity_text);

        final EditText editText = this.findViewById(R.id.phraseGen);

        final ColorPicker colorPicker = this.findViewById(R.id.textColorPicker);

        Button setTextBtn = this.findViewById(R.id.setText);

        setTextBtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                int[] rgb = ColorUtils.fromIntToRGB(colorPicker.getColor());
                HttpUtils.post(new AbstractMap.SimpleEntry<String, Object>("phrase", editText.getText().toString().toUpperCase() + ":" + rgb[0] + ":" + rgb[1] + ":" + rgb[2]));
            }
        });
    }
}
