package it.magicorp.casecontroller.utils;

import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.LinkedHashMap;
import java.util.Map;

public class HttpUtils
{
    public static void post(final Map.Entry<String, Object>... args)
    {
        new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                try {
                    for (Map.Entry<String, Object> arg : args) {
                        URL url = new URL("http://192.168.1.125");
                        Map<String, Object> params = new LinkedHashMap<>();
                        params.put(arg.getKey(), arg.getValue());
                        StringBuilder postData = new StringBuilder();
                        for (Map.Entry<String, Object> param : params.entrySet()) {
                            if (postData.length() != 0) postData.append('&');
                            postData.append(URLEncoder.encode(param.getKey(), "UTF-8"));
                            postData.append('=');
                            postData.append(URLEncoder.encode(String.valueOf(param.getValue()), "UTF-8"));
                        }

                        byte[] postDataBytes = postData.toString().getBytes("UTF-8");

                        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                        conn.setRequestMethod("POST");
                        conn.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
                        conn.setRequestProperty("Content-Length", String.valueOf(postDataBytes.length));
                        conn.setDoOutput(true);
                        conn.getOutputStream().write(postDataBytes);

                        Reader in = new BufferedReader(new InputStreamReader(conn.getInputStream(), "UTF-8"));

                        for (int c; (c = in.read()) >= 0; )
                            System.out.print((char) c);
                    }
                }
                catch(Exception ex)
                {
                    ex.printStackTrace();
                }
            }
        }).start();
    }
}
