import java.io.*;
import java.util.*;
 
public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int in;

        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	int n = Integer.parseInt(st.nextToken());
        	int m = Integer.parseInt(st.nextToken());
        	int s[][] = new int[n + 1][n + 1];
        	for(int i = 1; i <= n; i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j = 1; j <= n; j++) {
            		in = Integer.parseInt(st.nextToken());
            		s[i][j] = s[i - 1][j] + s[i][j - 1] + in - s[i - 1][j - 1];
            	}            	
        	}
        	int res = 0;
        	for(int i = m; i <= n; i++) {
        		for(int j = m; j <= n; j++) {
        			res = Math.max(res, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
        		}
        	}
        	
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}