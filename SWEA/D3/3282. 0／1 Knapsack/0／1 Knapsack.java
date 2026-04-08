import java.util.*;
import java.io.*;

public class Solution {
	static int n, k;
	static int c[], v[], dp[][];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			c = new int[n];
			v = new int[n];
			dp = new int[n][k + 1];
			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				v[i] = Integer.parseInt(st.nextToken());
				c[i] = Integer.parseInt(st.nextToken());
			}
			sb.append("#").append(tc).append(" ").append(sol(0, 0)).append("\n");
		}
		System.out.print(sb);
	}
	
	static int sol(int idx, int w) {
		if(w > k) return -2000000000;
		if(idx >= n) return 0;
		if(dp[idx][w] > 0) return dp[idx][w];
		
		dp[idx][w] = Math.max(dp[idx][w], sol(idx + 1, w));
		dp[idx][w] = Math.max(dp[idx][w], sol(idx + 1, w + v[idx]) + c[idx]);
		return dp[idx][w];
	}
}