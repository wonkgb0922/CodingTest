import java.io.*;
import java.util.*;
 
public class Solution {
	static char[] ary;
	static List<Integer> map[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = 10;
        int n, v;
        char exp;
        
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	map = new List[n];
        	ary = new char[n];
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		v = Integer.parseInt(st.nextToken()) - 1;
        		if(map[v] == null)
        			map[v] = new LinkedList<Integer>();
        		ary[v] = st.nextToken().charAt(0);
        		if(st.hasMoreTokens())
        			map[v].add(Integer.parseInt(st.nextToken()) - 1);
        		if(st.hasMoreTokens())
        			map[v].add(Integer.parseInt(st.nextToken()) - 1);
        	}
        	sb.append("#").append(t).append(" ").append(isValid(0) ? 1 : 0).append("\n");
        }
        System.out.println(sb);
        
    }
    static boolean isValid(int v) {
    	if(ary[v] >= '0' && ary[v] <= '9') {
    		if(!map[v].isEmpty())
    			return false;
    	}
    	else {
    		if(map[v].isEmpty())
    			return false;
    	}
    	for(int i = 0; i < map[v].size(); i++) {
    		if(!isValid(map[v].get(i)))
    			return false;
    	}
    	return true;
    }
}