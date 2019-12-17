package it.magicorp.casecontroller.utils;

public class ColorUtils
{
    public static int[] fromIntToRGB(int color)
    {
        int[] rgb = new int[3];

        rgb[2] = (color)&0xFF;
        rgb[1] = (color>>8)&0xFF;
        rgb[0] = (color>>16)&0xFF;

        return rgb;
    }
}
