import java.util.*;
import java.io.*;

class Main
{
	static int n;
	static List<Integer>[] e;
	static boolean visited[];	
	static StringBuilder sb = new StringBuilder();
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken()) - 1;
        e = new List[n];
        visited = new boolean[n];
        int a, b;
        for(int i = 0; i < n; i++)
        	e[i] = new ArrayList<>();
        while(m-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	a = Integer.parseInt(st.nextToken()) - 1;
        	b = Integer.parseInt(st.nextToken()) - 1;
        	e[a].add(b);
        	e[b].add(a);
        }
        for(int i = 0; i < n; i++)
        	Collections.sort(e[i]);
        visited[v] = true;
        sol(v);
        sb.append("\n");
        visited = new boolean[n];
        Queue<Integer> q = new ArrayDeque<>();
        visited[v] = true;
        q.offer(v);
        while(!q.isEmpty()) {
        	int t = q.poll();
        	sb.append(t + 1).append(" ");
        	for(int it : e[t]) {
        		if(!visited[it]) {
        			visited[it] = true;
        			q.offer(it);
        		}
        	}
        }
        System.out.println(sb);
        br.close();
    }
    static void sol(int idx) {
    	sb.append(idx + 1).append(" ");
    	for(int it : e[idx]) {
    		if(!visited[it]) {
    			visited[it] = true;
    			sol(it);
    		}
    	}
    }
    
}