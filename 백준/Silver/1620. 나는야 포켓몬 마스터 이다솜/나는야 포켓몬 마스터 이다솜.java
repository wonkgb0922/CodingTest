import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Map<String, String> map = new HashMap<>();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String in;
        for(int i = 0; i < n; i++) {
            in = br.readLine();
            map.put(Integer.toString(i + 1), in);
            map.put(in, Integer.toString(i + 1));
        }
        for(int i = 0; i < m; i++) {
            in = br.readLine();
            bw.write(map.get(in) + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
