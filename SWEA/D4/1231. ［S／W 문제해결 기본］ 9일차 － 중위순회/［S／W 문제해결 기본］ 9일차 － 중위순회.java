import java.util.*;
import java.io.*;

public class Solution {
	static int n;
	static char tree[];
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = 10;
		for(int t = 1; t <= T; t++) {
			sb.append(String.format("#%d ", t));
			n = Integer.parseInt(br.readLine());
			tree = new char[n + 1];
			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				int v = Integer.parseInt(st.nextToken());
				tree[v] = st.nextToken().charAt(0);
			}
			preOrder(1);
			sb.append("\n");
		}
		System.out.println(sb);
	}
	static void preOrder(int idx) {
		if(idx > n) return;
		if(tree[idx] == 0) return;
		preOrder(idx * 2);
		sb.append(tree[idx]);
		preOrder(idx * 2 + 1);
	}
}