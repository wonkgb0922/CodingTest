import java.util.*;
import java.io.*;

public class Solution {
    static int n, m;
    static int p[] = new int[25], s[] = new int[25];
    static int dp[][];
    static StringBuilder sb = new StringBuilder();
    static int sol(int idx, int cost) {
        if(idx == m) return 0;
        if(dp[idx][cost] > 0) return dp[idx][cost];
        dp[idx][cost] = sol(idx + 1, cost);
        if(cost + p[idx] <= n)
            dp[idx][cost] = Math.max(dp[idx][cost], sol(idx + 1, cost + p[idx]) + s[idx]);
        return dp[idx][cost];
    }

    static void track(int idx, int cost) {
        if(idx == m) {
            return;
        }
        if(dp[idx][cost] == dp[idx + 1][cost]) {
            // idx를 passing한 경우이다.
            track(idx + 1, cost);
        }
        else {
            sb.append(idx).append(" ");
            track(idx + 1, cost + p[idx]);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            for(int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                p[i] = Integer.parseInt(st.nextToken());
                s[i] = Integer.parseInt(st.nextToken());
            }
            dp = new int[m + 1][n + 1];
            int res = sol(0, 0);

            sb.append("#").append(t).append(" ");
            track(0, 0);
            sb.append(res).append("\n");
        }
        System.out.println(sb);
    }
}
