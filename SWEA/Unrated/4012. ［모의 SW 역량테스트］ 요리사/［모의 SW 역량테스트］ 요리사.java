import java.util.*;
import java.io.*;

class Solution
{
	static int n, m;
	static int ary[][];
	static int res;
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int in;
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	ary = new int[n][n];
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++) {
        			in = Integer.parseInt(st.nextToken());
        			ary[i][j] += in;
        			ary[j][i] += in;
        		}
        	}
        	res = Integer.MAX_VALUE;
        			
        	dfs(1, 1);
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
	static void dfs(int idx, int state) {
		if(Integer.bitCount(state) == n / 2) {
			int sa = 0, sb = 0;
			for(int i = 0; i < n - 1; i++) {
				for(int j = i + 1; j < n; j++) {
					int comb = (1 << i) | (1 << j);
					if((comb & state) == comb)
						sa += ary[i][j];
					else if((comb & state) == 0)
						sb += ary[i][j];
				}
			}
			
			res = Math.min(res, Math.abs(sb - sa));
			return;
		}
		if(idx > n - 1) return;
		if(n - idx + Integer.bitCount(state) < n / 2) return;
		
		dfs(idx + 1, state);
		dfs(idx + 1, state | (1 << idx));
	}
}
