package it.magicorp.casecontroller;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class TcpClient extends Thread
{
    private Socket client;

    private DataOutputStream out;
    private BufferedReader in;

    @Override
    public void run()
    {
        try
        {
            this.client = new Socket("192.168.1.125", 80);
            this.out = new DataOutputStream(client.getOutputStream());
            this.in = new BufferedReader(new InputStreamReader(client.getInputStream()));
        }
        catch (Exception ex)
        {
            this.disconnect();
        }
    }

    public void disconnect()
    {
        try
        {
            this.out.close();
            this.in.close();
            this.client.close();
        }
        catch (Exception ex)
        {

        }
    }

    public void write(String message)
    {
        try
        {
            this.out.writeChars(message);
        }
        catch (Exception ex)
        {
            this.disconnect();
        }
    }
}
