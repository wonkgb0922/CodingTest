import java.util.*;
import java.io.*;

class Solution
{
	static int n;
	static int l;
	static int dp[][];
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int s[] = new int[20], k[] = new int[20];
        
    	dp = new int[21][10001];
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	l = Integer.parseInt(st.nextToken());
        	for(int i = 1; i <= n; i++) {
        		for(int j = 0; j <= l; j++)
        			dp[i][j] = 0;
        	}
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		s[i] = Integer.parseInt(st.nextToken());
        		k[i] = Integer.parseInt(st.nextToken());
        	}
        	for(int i = 1; i <= n; i++) {
        		for(int j = 0; j <= l; j++) {
        			dp[i][j] = dp[i - 1][j];
        			if(j >= k[i - 1])
        				dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - k[i - 1]] + s[i - 1]);
        		}
        	}
        	sb.append('#').append(t).append(' ').append(dp[n][l]).append('\n');
        }
        System.out.println(sb);
    }
}