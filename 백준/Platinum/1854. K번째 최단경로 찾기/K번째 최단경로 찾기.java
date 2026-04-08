import java.io.*;
import java.util.*;

public class Main {
	static final int INF = (int)1e8;
	static int n, m, k;
	static ArrayList<Node> e[];
	static int dis[];
	static int visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int u, v, w;
        e = new ArrayList[n + 1];
        dis = new int[n + 1];
        visited = new int[n + 1];
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
        	Node node = new Node(u, w);
        	e[v].add(node);
        	if(v == 1)
        		pq.offer(node);
        }
        dis[1] = 0;
        visited[1] = 1;
        while(!pq.isEmpty()) {
        	Node peek = pq.poll();
        	if(visited[peek.v] < k) {
        		visited[peek.v]++;
        		dis[peek.v] = peek.w;
            	for(Node node : e[peek.v]) {
            		if(visited[node.v] < k)
                		pq.offer(new Node(node.v, node.w + dis[peek.v]));
            	}
        	}
        }
        for(int i = 1; i <= n; i++)
        	sb.append((visited[i] < k) ? -1 : dis[i]).append("\n");
        System.out.print(sb);
    }
}

class Node implements Comparable<Node> {
	int v;
	int w;
	public Node(int v, int w) {
		this.v = v;
		this.w = w;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.w, o.w);
	}
}