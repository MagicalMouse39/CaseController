package it.magicorp.casecontroller;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.findViewById(R.id.testRed).setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                String urlString = "http://192.168.1.125"; // URL to call
                String data = "255:0:0"; //data to post
                OutputStream out = null;

                try {
                    URL url = new URL(urlString);
                    HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
                    out = new BufferedOutputStream(urlConnection.getOutputStream());

                    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out, "UTF-8"));
                    writer.write(data);
                    writer.flush();
                    writer.close();
                    out.close();

                    urlConnection.connect();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
            }
        });
    }
}
