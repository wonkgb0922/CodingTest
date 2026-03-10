import java.io.*;
import java.util.*;

public class Main {
    static int ary[];
    static int dp[][];
    static int n, m;
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ary = new int[n];
        dp = new int[n][m + 1];
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j <= m; j++) {
        		dp[i][j] = Integer.MIN_VALUE;
        	}
        }
        for(int i = 0; i < n; i++)
        	ary[i] = Integer.parseInt(br.readLine());
        System.out.println(dfs(0, m));
    }
	static int dfs(int idx, int k) {
		if(k == 0)
			return 0;
		if(idx >= n)
			return -100000000;
		if(dp[idx][k] != Integer.MIN_VALUE)
			return dp[idx][k];
		dp[idx][k] = Math.max(dp[idx][k], dfs(idx + 1, k));
		int sum = 0;
		for(int i = idx; i < n; i++) {
			sum += ary[i];
			dp[idx][k] = Math.max(dp[idx][k], sum + dfs(i + 2, k - 1));
		}
		return dp[idx][k];
	}
}
