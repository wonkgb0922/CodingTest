import java.io.*;
import java.util.*;
 
public class Solution {
	static String map[] = new String[16];
	static boolean visited[][];
	static int dir[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = 10;
        int si = 0, sj = 0;
        
        while(T-- > 0) {
        	int t = Integer.parseInt(br.readLine());
        	int res = 0;
        	for(int i = 0; i < 16; i++) {
        		map[i] = br.readLine();
        		for(int j = 0; j < 16; j++) {
        			if(map[i].charAt(j) == '2') {
        				si = i;
        				sj = j;
        			}
        		}
        	}
        	visited = new boolean[16][16];
        	visited[si][sj] = true;
        	if(dfs(si, sj)) 
        		res = 1;
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
    static boolean dfs(int i, int j) {
    	if(map[i].charAt(j) == '3')
    		return true;
    	
    	for(int k = 0; k < 4; k++) {
    		int ii = i + dir[k][0];
    		int jj = j + dir[k][1];
    		if(ii >= 0 && ii < 16 && jj >= 0 && jj < 16) {
    			if(map[ii].charAt(jj) != '1' && !visited[ii][jj]) {
    				visited[ii][jj] = true;
    				if(dfs(ii, jj))
    					return true;
    			}
    		}
    	}
    	return false;
    }
}