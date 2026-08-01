import java.io.*;
import java.util.*;

public class Solution {
    static int dp[][];
    static int ary[][];
    static int n, l;

    static int sol(int idx, int cur) {
        if(idx >= n) return 0;
        if(dp[idx][cur] > 0) return dp[idx][cur];
        dp[idx][cur] = sol(idx + 1, cur);
        if(cur + ary[idx][1] <= l)
            dp[idx][cur] = Math.max(dp[idx][cur], sol(idx + 1, cur + ary[idx][1]) + ary[idx][0]);
        return dp[idx][cur];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
            dp = new int[n][l + 1];
            ary = new int[n][2];
            for(int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                ary[i][0] = Integer.parseInt(st.nextToken());
                ary[i][1] = Integer.parseInt(st.nextToken());
            }
            sb.append("#").append(t).append(" ").append(sol(0, 0)).append("\n");
        }
        System.out.println(sb);
    }
}
