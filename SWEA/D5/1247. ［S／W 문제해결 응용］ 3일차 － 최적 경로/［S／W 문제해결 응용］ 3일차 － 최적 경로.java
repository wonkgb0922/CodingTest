import java.util.*;
import java.io.*;

public class Solution {
	static int n;
	static int x[], y[];
	static int res, state;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			x = new int[n + 2];
			y = new int[n + 2];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n + 2; i++) {
				x[i] = Integer.parseInt(st.nextToken());
				y[i] = Integer.parseInt(st.nextToken());
			}
			state = 1;
			res = Integer.MAX_VALUE;
			dfs(0, 0);
			sb.append(String.format("#%d %d\n", tc, res));
		}
		System.out.print(sb);
	}
	static void dfs(int idx, int dis) {
		if(Integer.bitCount(state) == n + 1) {
			res = Math.min(res, dis + getDis(idx, 1));
			return;
		}
		if(dis >= res) return;
		for(int i = 2; i < n + 2; i++) {
			if((state & (1 << i)) == 0) {
				state ^= (1 << i);
				dfs(i, dis + getDis(idx, i));
				state ^= (1 << i);
			}
		}
	}
	static int getDis(int v, int u) {
		return Math.abs(x[v] - x[u]) + Math.abs(y[v] - y[u]);
	}
}