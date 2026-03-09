import java.util.*;
import java.io.*;

public class Solution {
	static int p[];
	static int dir[][] = {{1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
	static int n, res;
	static boolean isZero[][];
	static char ary[][];
	static int find(int v) {
		if(p[v] < 0) return v;
		return p[v] = find(p[v]);
	}
	static void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		res--;
		p[b] += p[a];
		p[a] = b;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		int ii, jj;
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			ary = new char[n][n];
			isZero = new boolean[n][n];
			p = new int[n * n];
			res = n * n;
			for(int i = 0; i < n; i++)
				ary[i] = br.readLine().toCharArray();
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					p[i * n + j] = -1;
					if(ary[i][j] == '*')
						res--;
					else
						Zero(i, j);
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(!isZero[i][j] | ary[i][j] == '*') continue;
					for(int d = 0; d < 8; d++) {
						ii = i + dir[d][0];
						jj = j + dir[d][1];
						if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
							if(ary[ii][jj] == '*' || (!isZero[ii][jj] && p[find(ii * n + jj)] < -1)) continue;
							merge(i * n + j, ii * n + jj);
						}
					}
				}
			}
			sb.append(String.format("#%d %d\n", tc, res));
		}
		System.out.print(sb);
	}
	static void Zero(int i, int j) {
		int ii, jj;
		for(int d = 0; d < 8; d++) {
			ii = i + dir[d][0];
			jj = j + dir[d][1];
			if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
				if(ary[ii][jj] == '*') {
					isZero[i][j] = false;
					return;
				}
			}
		}
		isZero[i][j] = true;
	}
}