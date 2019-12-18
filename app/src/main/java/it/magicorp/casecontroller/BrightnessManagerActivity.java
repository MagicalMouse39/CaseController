package it.magicorp.casecontroller;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.larswerkman.holocolorpicker.OpacityBar;

import java.util.AbstractMap;

import it.magicorp.casecontroller.utils.ColorUtils;
import it.magicorp.casecontroller.utils.HttpUtils;

public class BrightnessManagerActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        this.setContentView(R.layout.activity_brightness);

        final OpacityBar opacitySetter = this.findViewById(R.id.brightnessSetter);

        opacitySetter.setColor(ColorUtils.currentColor != 0 ? ColorUtils.currentColor : -48384);

        opacitySetter.setOnOpacityChangedListener(new OpacityBar.OnOpacityChangedListener()
        {
            @Override
            public void onOpacityChanged(int opacity)
            {
                ((TextView) BrightnessManagerActivity.this.findViewById(R.id.brightnessVal)).setText((int)(((float)opacity / 255) * 100) + "%");
            }
        });

        Button setBrightness = this.findViewById(R.id.setText);

        setBrightness.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                HttpUtils.post(new AbstractMap.SimpleEntry<String, Object>("brightness", opacitySetter.getOpacity()));
            }
        });
    }
}
