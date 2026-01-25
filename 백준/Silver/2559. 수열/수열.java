import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int res = Integer.MIN_VALUE;
        st = new StringTokenizer(br.readLine());
        int s[] = new int[n + 1];
        for(int i = 1; i <= n; i++)
        	s[i] = s[i - 1] + Integer.parseInt(st.nextToken());
        for(int i = m; i <=n; i++)
        	res = Math.max(res, s[i] - s[i - m]);
        System.out.println(res);
        br.close();
    }
}