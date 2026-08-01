import java.io.*;
import java.util.*;

public class Solution {
    static double dp[][];
    static double ary[][];
    static int n;

    static double sol(int idx, int state) {
        if(idx >= n) return 1;
        if(dp[idx][state] >= 0) return dp[idx][state];
        for(int i = 0; i < n; i++) {
            if((state & (1 << i)) > 0) continue;
            dp[idx][state] = Math.max(dp[idx][state], sol(idx + 1, state | (1 << i)) * ary[idx][i]);
        }
        return dp[idx][state];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());
            dp = new double[n][1 << n];
            ary = new double[n][n];
            for(int i = 0; i < n; i++) {
                Arrays.fill(dp[i], -1);
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; j++)
                    ary[i][j] = Integer.parseInt(st.nextToken()) / 100.0;
            }
            sb.append("#").append(t).append(" ").append(String.format("%.6f", sol(0, 0) * 100)).append("\n");
        }
        System.out.println(sb);
    }
}
