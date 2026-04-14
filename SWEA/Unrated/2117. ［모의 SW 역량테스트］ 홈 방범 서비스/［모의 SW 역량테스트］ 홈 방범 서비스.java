import java.io.*;
import java.util.*;

public class Solution {
	static int n, m, ary[][];
	static int dir[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int res;
        for(int tc = 1; tc <= T; tc++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
            ary = new int[n][n];
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++)
        			ary[i][j] = Integer.parseInt(st.nextToken());
        	}
        	res = 0;
        	for(int i = 0; i < n; i++)
        		for(int j = 0; j < n; j++)
                	res = Math.max(res, count(i, j));
        	sb.append("#").append(tc).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
    
    static int count(int i, int j) {
    	int ret = 0, cnt;
    	for(int k = 0; k <= n * 2; k++) {
    		cnt = 0;
    		for(int ii = Math.max(0, i - k); ii < Math.min(n, i + k + 1); ii++) {
    			for(int jj = Math.max(0, j - k); jj < Math.min(n, j + k + 1); jj++) {
    				if(Math.abs(ii - i) + Math.abs(jj - j) <= k)
    					cnt += ary[ii][jj];
    			}
    		}
    		if(cnt * m >= (k + 1) * (k + 1) + k * k)
    			ret = Math.max(ret, cnt);
		}
    	return ret;
    }
}
