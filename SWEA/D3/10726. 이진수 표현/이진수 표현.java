import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int n, m, bin;
        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            bin = (1 << n) - 1;
            sb.append("#").append(t).append(" ");
            if((bin & m) == bin)
                sb.append("ON\n");
            else
                sb.append("OFF\n");
        }
        System.out.println(sb);
    }
}
