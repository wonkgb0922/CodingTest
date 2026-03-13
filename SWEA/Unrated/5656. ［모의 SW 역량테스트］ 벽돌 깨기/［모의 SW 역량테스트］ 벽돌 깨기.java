import java.util.*;
import java.io.*;

public class Solution {
	static int n, w, h, dep, res, min;
	static int ary[][];
	static int dir[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			ary = new int[h][w];
			min = h * w;
			res = 0;
		
			for(int i = 0; i < h; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < w; j++) {
					ary[i][j] = Integer.parseInt(st.nextToken());
					if(ary[i][j] > 0) res++;
				}
			}
			for(int i = 0; i < w; i++)
				dfs(i);
			sb.append("#").append(tc).append(" ").append(min).append("\n");
		}
		System.out.println(sb);
	}
	static void dfs(int idx) {
		if(dep == n) {
			min = Math.min(min, res);
			return;
		}
		dep++;
		int i, j = 0, ii, jj, kk;
		while(j < h && ary[j][idx] == 0) j++;
		if(j < h) {
			int c = 0;
			int prev[][] = new int[h][];
			for (i = 0; i < h; i++) {
				prev[i] = ary[i].clone();
			}
			Queue<Integer> q = new ArrayDeque<>();
			q.add(j * w + idx);
			while(!q.isEmpty()) {
				int node = q.poll();
				i = node / w;
				j = node % w;
				kk = ary[i][j];
				if(ary[i][j] > 0) c++;
				ary[i][j] = 0;
				for(int k = 1; k < kk; k++) {
					for(int d = 0; d < 4; d++) {
						ii = i + dir[d][0] * k;
						jj = j + dir[d][1] * k;
						
						if(ii >= 0 && ii < h && jj >= 0 && jj < w) {
							if(ary[ii][jj] > 0)
								q.add(ii * w + jj);
						}
					}
				}
				
			}
			// 블럭 내리기
			for(int l = 0; l < w; l++) {
				i = h - 1;
				j = h - 1;
				while (j >= 0 && ary[j][l] > 0) j--;
				i = j - 1;
				while(true) {
					while(i >= 0 && ary[i][l] == 0) i--;
					if(i < 0) break;
					ary[j][l] = ary[i][l];
					ary[i][l] = 0;
					j--;
					i--;
				}
			}
			res -= c;
			for(int l = 0; l < w; l++)
				dfs(l);
			res += c;
			ary = prev;
		}
		else {
			for(int l = 0; l < w; l++)
				dfs(l);
		}
		dep--;
	}
}
