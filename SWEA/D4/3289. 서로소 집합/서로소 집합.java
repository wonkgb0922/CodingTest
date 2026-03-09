import java.util.*;
import java.io.*;

public class Solution {
	static int p[];
	
	static int find(int v) {
		if(p[v] == 0) return v;
		return p[v] = find(p[v]);
	}
	static void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		p[a] = b;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		int n, m, a, b, c;
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			p = new int[n + 1];
			sb.append(String.format("#%d ", tc));
			for(int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				if(a == 0) merge(b, c);
				else sb.append((find(b) == find(c)) ? 1 : 0);
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}