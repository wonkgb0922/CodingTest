import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		int n, m, c1, c2, l, r, mid, min, cnt = 0;
		int a[], b[];
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			c1 = Integer.parseInt(st.nextToken());
			c2 = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			a = new int[n];
			b = new int[m];
			for(int i = 0; i < n; i++)
				a[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < m; i++)
				b[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(b);
			min = Integer.MAX_VALUE;
			for(int i = 0; i < n; i++) {
				l = 0;
				r = m - 1;
				while(l < r) {
					mid = (l + r) / 2 + 1;
					if(b[mid] < a[i])
						l = mid;
					else
						r = mid - 1;
				}
				int t = Math.abs(b[l] - a[i]);
				if(min > t) {
					min = t;
					cnt = 1;
				}
				else if(min == t) cnt++;
				if(l < m - 1) {
					t = Math.abs(b[l + 1] - a[i]);
					if(min > t) {
						min = t;
						cnt = 1;
					}
					else if(min == t) cnt++;
				}
			}
			sb.append(String.format("#%d %d %d\n", tc, (long)min + Math.abs(c1 - c2), cnt));
		}
		System.out.println(sb);
	}
}
