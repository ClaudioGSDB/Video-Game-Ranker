import okhttp3.*;
import java.io.IOException;


import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        String client_id = "cw78i5gcd2w1zbi0h5fjxdsy8axzvj";
        String client_secret = "xqylb47exhur1foy07sfy4jsu50ywm";
        POST: https://id.twitch.tv/oauth2/token?client_id=cw78i5gcd2w1zbi0h5fjxdsy8axzvj&client_secret=xqylb47exhur1foy07sfy4jsu50ywm&grant_type=client_credentials
        try
        {
            URL url = new URL("https://www.metaweather.com/api/location/search/?query=London");
            System.out.println("Hello world!");
        }
        catch (Exception e)
        {

        }
    }
}