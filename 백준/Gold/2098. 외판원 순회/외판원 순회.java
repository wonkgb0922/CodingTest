import java.util.*;
import java.io.*;

class Main
{
	static int n;
	static int dp[][];
	static int w[][];
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        n = Integer.parseInt(br.readLine());
        w = new int[n][n];
        dp = new int[n][1 << n];
        for(int i = 0; i < n; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j = 0; j < n; j++)
        		w[i][j] = Integer.parseInt(st.nextToken());
        }
        System.out.println(sol(0, 1));
    }
	static int sol(int idx, int state) {
		if(dp[idx][state] != 0) return dp[idx][state];
		if(state == (1 << n) - 1) {
			if(w[idx][0] != 0) return w[idx][0];
			return 1000000000;
		}
		
		dp[idx][state] = 1000000000;
		for(int i = 0; i < n; i++) {
			if((state & (1 << i)) > 0 || w[idx][i] == 0) continue;
			dp[idx][state] = Math.min(dp[idx][state], sol(i, state | (1 << i)) + w[idx][i]);
		}
		return dp[idx][state];
	}
}
