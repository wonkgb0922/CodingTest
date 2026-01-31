import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int j = Integer.parseInt(st.nextToken());
        int i = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(br.readLine());
        
        int dir = t / m;
        if(dir % 2 == 0) j += t % m;
        else j = (m - t % m) - j;
        
        if(j > m) j = 2 * m - j;
        if(j < 0) j *= -1;
        
        dir = t / n;
        if(dir % 2 == 0) i += t % n;
        else i = (n - t % n) - i;
        
        if(i > n) i = 2 * n - i;
        if(i < 0) i *= -1;
        System.out.println(j + " " + i);
        br.close();
    }
}
