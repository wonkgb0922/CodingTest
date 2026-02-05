import java.util.*;
import java.io.*;

class Main
{
	static int n;
	static List<Integer>[] e;
	static boolean visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        e = new List[n];
        visited = new boolean[n];
        int a, b;
        while(m-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	a = Integer.parseInt(st.nextToken());
        	b = Integer.parseInt(st.nextToken());
        	if(e[a] == null)
        		e[a] = new LinkedList<>();
        	if(e[b] == null)
        		e[b] = new LinkedList<>();
        	e[a].add(b);
        	e[b].add(a);
        }
        boolean res = false;
        for(int i = 0; i < n; i++) {
        	if(e[i] == null) continue;
			visited[i] = true;
        	res = sol(i, 1);
			visited[i] = false;
        	if(res) break;
        }
        System.out.println(res ? 1 : 0);
        br.close();
    }
    static boolean sol(int idx, int depth) {
    	if(depth == 5) return true;
    	if(e[idx] == null) return false;
    	for(int it : e[idx]) {
    		if(!visited[it]) {
    			visited[it] = true;
    			if(sol(it, depth + 1)) return true;
    			visited[it] = false;
    		}
    	}
    	return false;
    }
}