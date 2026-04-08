import java.io.*;
import java.util.*;

public class Main {
	static final int INF = (int)1e8;
	static int n, m;
	static ArrayList<Node> e[];
	static int dis[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(br.readLine());
        int u, v, w;
        e = new ArrayList[n + 1];
        dis = new int[n + 1];
        for(int i = 1; i <= n; i++) {
        	dis[i] = INF;
        	e[i] = new ArrayList<>();
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i = 0; i < m; i++) {
        	st = new StringTokenizer(br.readLine());
        	v = Integer.parseInt(st.nextToken());
        	u = Integer.parseInt(st.nextToken());
        	w = Integer.parseInt(st.nextToken());
        	Node node = new Node(v, u, w);
        	e[v].add(node);
        	if(v == s)
        		pq.offer(node);
        }
        dis[s] = 0;
        while(!pq.isEmpty()) {
        	Node peek = pq.poll();
        	if(dis[peek.u] == INF) {
        		dis[peek.u] = peek.w;
            	for(Node node : e[peek.u]) {
            		if(dis[node.u] == INF)
                		pq.offer(new Node(node.v, node.u, node.w + dis[peek.u]));
            	}
        	}
        }
        for(int i = 1; i <= n; i++)
        	sb.append((dis[i] == INF) ? "INF" : dis[i]).append("\n");
        System.out.print(sb);
    }
}

class Node implements Comparable<Node> {
	int v;
	int u;
	int w;
	public Node(int v, int u, int w) {
		this.v = v;
		this.u = u;
		this.w = w;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.w, o.w);
	}
}