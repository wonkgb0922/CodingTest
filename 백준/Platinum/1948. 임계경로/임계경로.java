import java.io.*;
import java.util.*;

public class Main {
	static int n, m, start, end;
	static List<Node>[] e;
	static int[] dp;
	static boolean visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        e = new List[n + 1];
        dp = new int[n + 1];
        visited = new boolean[n + 1];
        int v, u, w;
        for(int i = 1; i <= n; i++)
        	e[i] = new ArrayList<>();
        m = Integer.parseInt(br.readLine());
        for(int i = 0; i < m; i++) {
        	st = new StringTokenizer(br.readLine());
        	v = Integer.parseInt(st.nextToken());
        	u = Integer.parseInt(st.nextToken());
        	w = Integer.parseInt(st.nextToken());
        	e[u].add(new Node(v, w));  	
        }
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());
        int res = sol(end), cnt = 0;
        
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(end);
        while(!q.isEmpty()) {
        	v = q.poll();
        	for(Node it : e[v]) {
        		if(dp[v] == dp[it.idx] + it.w) {
        			cnt++;
        			if(!visited[it.idx]) {
            			q.offer(it.idx);
            			visited[it.idx] = true;
        			}
        		}
        	}
        }
        
        sb.append(res).append("\n").append(cnt);
        System.out.print(sb);
    }
    static int sol(int idx) {
    	if(idx == start)
    		return 0;
    	if(dp[idx] > 0) return dp[idx];
    	for(Node it : e[idx])
    		dp[idx] = Math.max(dp[idx], sol(it.idx) + it.w);
    	return dp[idx];
    }
}

class Node {
	int idx;
	int w;
	public Node(int idx, int w) {
		this.idx = idx;
		this.w = w;
	}	
}
