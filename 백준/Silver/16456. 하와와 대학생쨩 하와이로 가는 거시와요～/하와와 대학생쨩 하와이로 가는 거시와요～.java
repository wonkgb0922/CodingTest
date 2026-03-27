import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int dp[][];
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        dp = new int[n + 1][2];
        
		System.out.print((sol(n, 0) + sol(n, 1)) % 1000000009);
    }
    
    static int sol(int idx, int flag) {
    	if(dp[idx][flag] > 0)
    		return dp[idx][flag];
    	
    	if(idx <= 2) {
    		if(flag == 0) return 1;
    		return 0;
    	}
    	
    	if(flag == 0)
    		dp[idx][flag] = sol(idx - 1, 0) + sol(idx - 1, 1);
    	else
    		dp[idx][flag] = sol(idx - 2, 0);
    	dp[idx][flag] %= 1000000009;
    	return dp[idx][flag];    	
    }
}
