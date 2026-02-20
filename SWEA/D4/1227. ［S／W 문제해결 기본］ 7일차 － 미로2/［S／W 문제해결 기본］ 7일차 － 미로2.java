import java.util.*;
import java.io.*;
 
class Solution
{
	static final int n = 100;
	static int ary[][];
	static int dir[][] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = 10;
        int tc;
        int si = 0, sj = 0, res;
        String in;
        for(int t = 1; t <= T; t++) {
        	tc = Integer.parseInt(br.readLine());
        	ary = new int[n][n];
        	for(int i = 0; i < n; i++) {
        		in = br.readLine();
        		for(int j = 0; j < n; j++) {
        			ary[i][j] = in.charAt(j) - '0';
        			if(ary[i][j] == 2) {
        				si = i;
        				sj = j;
        			}
        		}
        	}
        	res = (dfs(si, sj)) ? 1 : 0;
        	sb.append(String.format("#%d %d\n", tc, res));
        }
        System.out.println(sb);
    }
    static boolean dfs(int i, int j) {
    	if(ary[i][j] == 3)
    		return true;
    	ary[i][j] = 1;
    	for(int d = 0;d < 4; d++) {
    		int ii = i + dir[d][0];
    		int jj = j + dir[d][1];
    		if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
    			if(ary[ii][jj] != 1) {
    				if(dfs(ii, jj))
    					return true;
    			}
    		}
    	}
    	ary[i][j] = 0;
    	return false;
    }
}