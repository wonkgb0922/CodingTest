import java.util.*;
import java.io.*;

class Solution
{
	static int n, m;
	static int ary[];
	static int res;
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	ary = new int[n];
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < n; i++)
        		ary[i] = Integer.parseInt(st.nextToken());
        	res = Integer.MAX_VALUE;
        	dfs(0, 0);
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
	
	static void dfs(int idx, int cur) {
		if(cur >= m) {
			res = Math.min(res, cur - m);
            return;
		}
		if(idx >= n) return;
		dfs(idx + 1, cur + ary[idx]);
		dfs(idx + 1, cur);
	}
}