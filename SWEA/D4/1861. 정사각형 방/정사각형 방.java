import java.util.*;
import java.io.*;

class Solution
{
	static int n;
	static int ary[];
	static int dp[];
	static int dir[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
    	int cnt, max, res = 0;

        boolean find;
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	dp = new int[n * n];
        	ary = new int[n * n];
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++)
        			ary[Integer.parseInt(st.nextToken()) - 1] = i * n + j;
        	}
        	dp[0] = 1;
        	for(int idx = 1; idx < n * n; idx++) {
        		int i = ary[idx - 1] / n;
        		int j = ary[idx - 1] % n;
        		find = false;
        		for(int k = 0; k < 4; k++) {
        			int ii = i + dir[k][0];
        			int jj = j + dir[k][1];
        			if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
        				if(ary[idx] == ii * n + jj) {
        					dp[idx] = dp[idx - 1] + 1;
        					find = true;
        					break;
        				}
        			}
        		}
    			if(!find) dp[idx] = dp[idx - 1];
        	}
        	cnt = 1;
        	max = 0;
        	for(int idx = n * n - 1; idx > 0; idx--) {
        		if(dp[idx] == dp[idx - 1]) {
        			if(max <= cnt) {
        				max = cnt;
        				res = idx;
        			}
        			cnt = 1;
        		}
        		else cnt++;
        	}
        	if(max <= cnt) {
        		max = cnt;
				res = 0;
        	}
        	
        	sb.append(String.format("#%d %d %d\n", t, res + 1, max));
        }
        System.out.println(sb);
    }
}
