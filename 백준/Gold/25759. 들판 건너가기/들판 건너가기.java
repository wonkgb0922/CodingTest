import java.io.*;
import java.util.*;

public class Main {
	static int ary[], dp[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		ary = new int[n];
		dp = new int[101];
		for(int i = 0; i < n; i++)
			ary[i] = Integer.parseInt(st.nextToken());
		for(int i = 1; i <= 100; i++)
			dp[i] = -1;
		System.out.println(sol(n - 1));
	}
	static int sol(int idx) {
		if(idx == 0)
			return 0;
        if(dp[ary[idx]] >= 0) return dp[ary[idx]];
		dp[ary[idx - 1]] = sol(idx - 1);
		for(int i = 1; i <= 100; i++) {
			if(dp[i] >= 0)
				dp[ary[idx]] = Math.max(dp[ary[idx]], dp[i] + (ary[idx] - i) * (ary[idx] - i));
		}
		return dp[ary[idx]];
	}
}