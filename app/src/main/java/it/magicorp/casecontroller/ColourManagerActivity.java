package it.magicorp.casecontroller;

import android.graphics.drawable.GradientDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.larswerkman.holocolorpicker.ColorPicker;
import com.larswerkman.holocolorpicker.OpacityBar;

import java.util.AbstractMap;

import it.magicorp.casecontroller.utils.ColorUtils;
import it.magicorp.casecontroller.utils.HttpUtils;

public class ColourManagerActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        this.setContentView(R.layout.activity_colour);

        final ColorPicker colorPicker = this.findViewById(R.id.colorPicker);
        final Button setColorBtn = this.findViewById(R.id.setColor);
        final OpacityBar opacityBar = this.findViewById(R.id.opacityBar);
        final TextView opacityVal = this.findViewById(R.id.opacityVal);

        colorPicker.setColor(-48384);
        colorPicker.setNewCenterColor(-48384);
        colorPicker.setOldCenterColor(-48384);

        opacityBar.setColor(-48384);

        opacityVal.setTextColor(-48384);

        colorPicker.setOnColorChangedListener(new ColorPicker.OnColorChangedListener()
        {
            @Override
            public void onColorChanged(int color)
            {
                ColorUtils.currentColor = color;
                opacityBar.setColor(color);
                GradientDrawable gd = new GradientDrawable();
                gd.setStroke(15, color);
                gd.setCornerRadius(15);
                setColorBtn.setBackground(gd);
                opacityVal.setTextColor(color);
                setColorBtn.setTextColor(color);

                //Toast.makeText(ColourManagerActivity.this.getBaseContext(), color + "", Toast.LENGTH_LONG).show();
            }
        });

        opacityBar.setOnOpacityChangedListener(new OpacityBar.OnOpacityChangedListener()
        {
            @Override
            public void onOpacityChanged(int opacity)
            {
                ((TextView)ColourManagerActivity.this.findViewById(R.id.opacityVal)).setText((int)(((float)opacity / 255) * 100) + "%");
            }
        });

        setColorBtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                int[] rgb = ColorUtils.fromIntToRGB(opacityBar.getColor());
                HttpUtils.post(new AbstractMap.SimpleEntry<String, Object>("colour", rgb[0] + ":" + rgb[1] + ":" + rgb[2]), new AbstractMap.SimpleEntry<String, Object>("brightness", opacityBar.getOpacity()));
            }
        });
    }
}
