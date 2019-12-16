package it.magicorp.casecontroller;

import android.os.AsyncTask;
import android.os.Bundle;
import android.app.Activity;
import android.widget.EditText;
import android.widget.Button;
import android.view.View;
import android.widget.Toast;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.client.methods.HttpPost;
import java.util.List;
import java.util.ArrayList;
import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.HttpResponse;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class HttpPostUtils extends AsyncTask<String, String, String>
{
    public HttpPostUtils()
    {

    }

    @Override
    protected void onPreExecute()
    {
        super.onPreExecute();
    }

    @Override
    protected String doInBackground(String... params) {
        try
        {
            HttpClient client = new HttpClient();
            HttpPost post = new HttpPost("http://www.yoursite.it/script.php");

            List<NameValuePair> pairs = new ArrayList<NameValuePair>(2);
            post.setEntity(new UrlEncodedFormEntity(pairs));

            response = client.execute(post);
//
            if(response != null) {
                String res=response.toString();
                res= res.replaceAll("\\s+","");
                if(!res.equals("failed"))
                {
                    Toast.makeText(this, "Username o password errati!", Toast.LENGTH_LONG).show();
                }
                else
                {
                    Toast.makeText(this, "Login effettuato", Toast.LENGTH_LONG).show();
                }
            } else {
                Toast.makeText(this, "Impossibile completare la richiesta", Toast.LENGTH_LONG).show();
            }

        }
        catch(Exception e)
        {
//
            Toast.makeText(MainActivity.this,e.getMessage(),Toast.LENGTH_LONG).show();

        }
    }
    }
}
