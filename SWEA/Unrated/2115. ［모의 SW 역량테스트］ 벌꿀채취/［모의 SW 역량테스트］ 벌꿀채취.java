import java.util.*;
import java.io.*;

class Solution
{
	static int c;
	static int ary[][];
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int n, m, res;
        int[][] r;

        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	c = Integer.parseInt(st.nextToken());
        	ary = new int[n][n];
        	r = new int[n][n - m + 1];
        	res = 0;
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++)
        			ary[i][j] = Integer.parseInt(st.nextToken());
        	}
        	for(int i = 0; i < n; i++) {
        		for(int j = 0; j < n - m + 1; j++) {
        			for(int k = 0; k < m; k++)
            			r[i][j] = Math.max(r[i][j], dfs(i, j + k, 0, 0, m - k - 1));
        		}
        	}
        	for(int i = 0; i < n; i++) {
        		for(int j = 0; j < n - m + 1; j++) {
        			for(int k = i; k < n; k++) {
        				for(int l = 0; l < n - m + 1; l++) {
        					if(i == k)
        						if(l > j + m || l + m > j) continue;
        					res = Math.max(res, r[i][j] + r[k][l]);
        				}
        			}
        		}
        	}
        	sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
	
	static int dfs(int i, int j, int C, int val, int depth) {
		C += ary[i][j];
		if(C > c) return 0;

		val += ary[i][j] * ary[i][j];
		if(depth == 0) return val;
		
		int ret = val;
		for(int k = 1; k <= depth; k++) {
			ret = Math.max(ret, dfs(i, j + k, C, val, depth - k));
		}
		return ret;
	}
}
