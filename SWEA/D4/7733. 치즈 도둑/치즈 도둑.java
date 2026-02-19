import java.util.*;
import java.io.*;

class Solution
{
	static int ary[][];
	static boolean visited[][];
	static int dir[][] = {{0 ,1}, {0, -1}, {1, 0}, {-1, 0}};
	static int n;
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int max, res, cnt;
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	ary = new int[n][n];
        	max = 0;
        	res = 1;
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++) {
        			ary[i][j] = Integer.parseInt(st.nextToken());
        			max = Math.max(ary[i][j], max);
        		}
        	}
        	for(int k = 1; k < max; k++) {
        		visited = new boolean[n][n];
        		cnt = 0;
        		for(int i = 0; i < n; i++) {
            		for(int j = 0; j < n; j++) {
            			if(!visited[i][j]) {
                			visited[i][j] = true;
                			if(ary[i][j] > k) {
                				dfs(i, j, k);
                				cnt++;
                			}
            			}
            		}
            	}
        		res = Math.max(res, cnt);
        	}
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
	static void dfs(int i, int j, int k) {
		for(int d = 0; d < 4; d++) {
			int ii = i + dir[d][0];
			int jj = j + dir[d][1];
			if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
				if(!visited[ii][jj] && ary[ii][jj] > k) {
					visited[ii][jj] = true;
					dfs(ii, jj, k);
				}
			}
		}
	}
}
