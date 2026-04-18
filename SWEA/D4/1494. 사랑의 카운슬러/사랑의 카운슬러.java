import java.util.*;
import java.io.*;

public class Solution {
	static int ary[][];
	static int n, fn, cnt;
	static long res;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		ary = new int[20][2];
		for (int tc = 1; tc <= T; tc++) {
			res = Long.MAX_VALUE;
			n = Integer.parseInt(br.readLine());
			fn = n >> 1;
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				ary[i][0] = Integer.parseInt(st.nextToken());
				ary[i][1] = Integer.parseInt(st.nextToken());
			}
			cnt = 1;
			sol(1, ary[0][0], ary[0][1]);
			sb.append("#").append(tc).append(" ").append(res).append("\n");
		}
		System.out.print(sb);
	}
	
	static void sol(int idx, long f, long s) {
		if (idx + fn - cnt > n) return;
		if (idx == n) {
			long temp = f * f + s * s;
			res = Math.min(res, temp);
			return;
		}

		sol(idx + 1, f - ary[idx][0], s - ary[idx][1]);
		if (cnt < fn) {
			cnt++;
			sol(idx + 1, f + ary[idx][0], s + ary[idx][1]);
			cnt--;
		}
	}
}