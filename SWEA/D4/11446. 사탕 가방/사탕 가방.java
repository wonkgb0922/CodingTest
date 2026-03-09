import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		int n;
		long m, l, r, mid, sum;
		long ary[];
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Long.parseLong(st.nextToken());
			st = new StringTokenizer(br.readLine());
			ary = new long[n];
			for(int i = 0; i < n; i++)
				ary[i] = Long.parseLong(st.nextToken());
			l = 0;
			r = 1000000000000000001L;
			while(l < r) {
				mid = (l + r) / 2 + 1;
				if(mid == 0) break;
				sum = 0;
				for(int i = 0; i < n; i++)
					sum += ary[i] / mid;
				if(m <= sum) l = mid;
				else r = mid - 1;
			}
			sb.append(String.format("#%d %d\n", tc, r));
		}
		System.out.println(sb);
	}
}
