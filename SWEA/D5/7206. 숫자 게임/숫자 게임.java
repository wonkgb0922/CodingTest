import java.util.*;
import java.io.*;
 
class Solution
{
	static int dp[] = new int[100000];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int n, res = 0;
        for(int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());
            res = dfs(n, 1, 1, true);
            sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
    static int dfs(int idx, int prev, int cur, boolean comp) {
    	if(comp) {
    		if(idx < 10) return 0;
    		if(dp[idx] > 0) return dp[idx];
    		for(int i = 10; idx / i > 0; i *= 10)
    			dp[idx] = Math.max(dp[idx], dfs(idx, idx / i, idx % i, false));
    	}
    	else {
    		for(int i = 10; prev / i > 0; i *= 10)
    			dp[idx] = Math.max(dp[idx], dfs(idx, prev / i, cur * (prev % i), false));
    		
			dp[idx] = Math.max(dp[idx], dfs(prev * cur, 1, 1, true) + 1);
    	}
		return dp[idx];
    }
}