import java.util.*;
import java.io.*;

public class Main {
	static int dp[], n;
	static Pair ary[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		ary = new Pair[n];
		dp = new int[n];
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			ary[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		System.out.println(sol(0));
	}
	static int sol(int idx) {
		if(idx >= n) return 0;
//		if(idx == n - 1) return ary[idx].second;
		if(dp[idx] > 0) return dp[idx];
		dp[idx] = sol(idx + 1);
		if(idx + ary[idx].first <= n)
			dp[idx] = Math.max(dp[idx], sol(idx + ary[idx].first) + ary[idx].second);
		return dp[idx];
	}
}
class Pair{
	int first;
	int second;
	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
	
}