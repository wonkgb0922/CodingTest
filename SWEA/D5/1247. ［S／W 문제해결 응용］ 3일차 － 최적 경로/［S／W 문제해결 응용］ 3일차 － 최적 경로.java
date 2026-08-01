import java.io.*;
import java.util.*;

public class Solution {
    static int dp[][][];
    static Pos ary[];
    static Pos start, end;
    static int n;
    static final int INF = 1000000000;

    static int sol(int idx, int prev, int state) {
        if(idx >= n) return getDis(ary[prev], end);
        if(dp[idx][prev][state] < INF) return dp[idx][prev][state];
        for(int i = 1; i <= n; i++) {
            if((state & (1 << i)) > 0) continue;
            dp[idx][prev][state] = Math.min(dp[idx][prev][state],
                    sol(idx + 1, i, state | (1 << i)) + getDis(ary[prev], ary[i]));
        }
        return dp[idx][prev][state];
    }

    static int getDis(Pos p1, Pos p2) {
        return Math.abs(p1.i - p2.i) + Math.abs(p1.j - p2.j);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        dp = new int[11][11][1 << 11];
        ary = new Pos[11];
        for (int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            ary[0] = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            end = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            for(int i = 0; i < n; i++) {
                ary[i + 1] = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= n; j++)
                    Arrays.fill(dp[i][j], INF);
            }
//            Arrays.fill(dp[n], INF);
            sb.append("#").append(t).append(" ").append(sol(0, 0, 1)).append("\n");
        }
        System.out.println(sb);
    }
}

class Pos {
    public Pos(int i, int j) {
        this.i = i;
        this.j = j;
    }
    public int i;
    public int j;
}