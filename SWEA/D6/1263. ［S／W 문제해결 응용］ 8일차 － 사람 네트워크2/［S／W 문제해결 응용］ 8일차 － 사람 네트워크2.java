import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int n, dis[][], res, sum;
        for(int tc = 1; tc <= T; tc++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	dis = new int[n][n];
        	for(int i = 0; i < n; i++) {
        		for(int j = 0; j < n; j++ ) {
        			dis[i][j] = (Integer.parseInt(st.nextToken()) > 0) ? 1 : 100000000;
        			if(i == j) dis[i][j] = 0;
        		}
        	}
        	for(int k = 0; k < n; k++) {
        		for(int i = 0; i < n; i++) {
        			for(int j = 0; j < n; j++) {
        				dis[i][j] = Math.min(dis[i][j], dis[i][k] + dis[k][j]);
        			}
        		}
        	}
        	res = Integer.MAX_VALUE;
        	for(int i = 0; i < n; i++) {
        		sum = 0;
    			for(int j = 0; j < n; j++)
    				sum += (dis[i][j] >= 100000000) ? 0 : dis[i][j];
    			res = Math.min(res, sum);
    		}
        	sb.append("#").append(tc).append(" ").append(res).append("\n");        	
        }
        System.out.print(sb);
    }
}
