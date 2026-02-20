import java.util.*;
import java.io.*;
 
class Solution
{
	static int n;
	static int ary[][];
	static int dir[][] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
	static int res;
	static boolean visited[];
	static int si, sj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	ary = new int[n][n];
        	res = -1;
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++)
        			ary[i][j] = Integer.parseInt(st.nextToken()) - 1;
        	}
        	for(int i = 0; i < n - 1; i++) {
        		for(int j = 1; j < n - 1; j++) {
                	visited = new boolean[100];
                	si = i;
                	sj = j;
                	visited[ary[i][j]] = true;
        			res = Math.max(res, dfs(i, j, 0, 0));
        		}
        	}
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
    static int dfs(int i, int j, int d, int depth) {
    	if(si == i && sj == j && d == 3)
    		return depth;
    	int ret = -1;
    	int ni = i + dir[d][0];
    	int nj = j + dir[d][1];
    	if(ni >= 0 && ni < n && nj >= 0 && nj < n) {
    		if(!visited[ary[ni][nj]] || (ni == si && nj == sj)) {
    			visited[ary[ni][nj]] = true;
    			ret = Math.max(ret, dfs(ni, nj, d, depth + 1));
    			if(ni != si || nj != sj)
    				visited[ary[ni][nj]] = false;
    		}
    	}
    	if(d < 3) {
    		ni = i + dir[d + 1][0];
        	nj = j + dir[d + 1][1];
        	if(ni >= 0 && ni < n && nj >= 0 && nj < n) {
        		if(!visited[ary[ni][nj]] || (ni == si && nj == sj)) {
        			visited[ary[ni][nj]] = true;
        			ret = Math.max(ret, dfs(ni, nj, d + 1, depth + 1));
        			if(ni != si || nj != sj)
        				visited[ary[ni][nj]] = false;
        		}
        	}
    	}
    	return ret;
    }
}