import java.io.*;
import java.util.*;
 
public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = 10;
        int t, i, j, s = 0;
        int ary[][] = new int[100][100];
        
        while(T-- > 0) {
        	t = Integer.parseInt(br.readLine());
        	for(i = 0; i < 100; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(j = 0; j < 100; j++) {
        			ary[i][j] = Integer.parseInt(st.nextToken());
        			if(ary[i][j] == 2)
        				s = j;
        		}
        	}
        	i = 99;
        	j = s;
        	while(i > 0) {
    			ary[i][j] = 0;
        		if(j + 1 < 100 && ary[i][j + 1] == 1)
        			j++;
        		else if(j - 1 >= 0 && ary[i][j - 1] == 1)
        			j--;
        		else
        			i--;
        	}
            sb.append("#").append(t).append(" ").append(j).append("\n");
        }        
        System.out.println(sb);
    }
}
