import okhttp3.*;
import org.json.JSONArray;
import org.json.JSONObject;
import java.io.IOException;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class Main
{
    public static final MediaType JSON = MediaType.get("application/json; charset=utf-8");
    public static final OkHttpClient client = new OkHttpClient();

    public static void main(String[] args) throws IOException {

        int id = 0;

        FileWriter DataFile = new FileWriter("src/Data/DataTEST.txt");

        //for(int i = 0; i < 474; i++){
        for(int i = 0; i < 1; i++){ //TEST

            String query = "fields name, rating, genres.name; where id > " + id + " & genres != null & rating != null; sort id asc; limit 500;";

            RequestBody body = RequestBody.create(query, JSON);
            Request request = new Request.Builder()
                    .url("https://api.igdb.com/v4/games")
                    .post(body)
                    .addHeader("Client-ID", "cw78i5gcd2w1zbi0h5fjxdsy8axzvj")
                    .addHeader("Authorization", "Bearer i4lf90y3a9qlkf0w9ysudzi7t3t401")
                    .build();

            try (Response response = client.newCall(request).execute()) {
                String responseData = response.body().string();

                //update id
                id += 500;

                DataFile.write(responseData);
                DataFile.flush();
                //System.out.println(responseData);
            }
        }
        DataFile.close();
    }
}