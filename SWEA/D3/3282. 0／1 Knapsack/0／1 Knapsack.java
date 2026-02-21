import java.util.*;
import java.io.*;
 
class Solution
{
	static int n;
	static int k;
	static int dp[][];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int v, c;
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	k = Integer.parseInt(st.nextToken());
        	dp = new int[n][k + 1];
    		st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
        	for(int i = v; i <= k; i++)
    			dp[0][i] = c;
        	for(int i = 1; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
    			v = Integer.parseInt(st.nextToken());
    			c = Integer.parseInt(st.nextToken());
        		for(int j = 1; j <= k; j++) {
        			dp[i][j] = dp[i - 1][j];
        			if(j - v >= 0)
        				dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - v] + c);
        		}
        	}
        	sb.append(String.format("#%d %d\n", t, dp[n - 1][k]));
        }
        System.out.println(sb);
    }
}