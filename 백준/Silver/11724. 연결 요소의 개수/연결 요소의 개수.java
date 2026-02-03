import java.io.*;
import java.util.*;
 
public class Main {
	static List<Integer>[] map;
	static boolean visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v, e;
        map = new List[n];
        visited = new boolean[n];
        while(m-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	v = Integer.parseInt(st.nextToken()) - 1;
        	e = Integer.parseInt(st.nextToken()) - 1;
        	if(map[v] == null)
        		map[v] = new LinkedList<>();
        	map[v].add(e);
        	if(map[e] == null)
        		map[e] = new LinkedList<>();
        	map[e].add(v);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
        	if(map[i] == null) {
        		cnt++;
        		continue;
        	}
        	if(!visited[i]) {
        		visited[i] = true;
        		cnt += dfs(i);
        	}
        }
        System.out.println(cnt);
    }
    static int dfs(int v) {
    	for(int it : map[v]) {
    		if(!visited[it]) {
    			visited[it] = true;
    			dfs(it);
    		}
    	}
    	return 1;
    }
}