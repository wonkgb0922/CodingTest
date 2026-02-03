import java.io.*;
import java.util.*;
 
public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int n, m, i, j, res;
        int ary[];
        
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	st = new StringTokenizer(br.readLine());
        	ary = new int[n];
        	for(i = 0; i < n; i++)
        		ary[i] = Integer.parseInt(st.nextToken());
        	Arrays.sort(ary);
        	i = 0;
        	j = n - 1;
        	res = -1;
        	while(i < j) {
        		if(ary[i] + ary[j] <= m) {
        			res = Math.max(res, ary[i] + ary[j]);
        			i++;
        		}
        		else j--;
        	}
        	sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}