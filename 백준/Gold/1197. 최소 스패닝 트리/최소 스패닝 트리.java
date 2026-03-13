import java.util.*;
import java.io.*;

public class Main {
	static ArrayList<Node>[] edge;
	static boolean visited[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		int cnt, v, u, c, res = 0;
		Node node;
		PriorityQueue<Node> pq = new PriorityQueue<>();
		edge = new ArrayList[n + 1];
		visited = new boolean[n + 1];
		for(int i = 1; i <= n; i++)
			edge[i] = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			u = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			edge[v].add(new Node(u, c));
			edge[u].add(new Node(v, c));
		}
		for(Node e : edge[1])
			pq.offer(e);
		visited[1] = true;
		cnt = 1;
		while(!pq.isEmpty()) {
			node = pq.poll();
			if(visited[node.idx]) continue;
			visited[node.idx] = true;
			res += node.w;
			cnt++;
			if(cnt == n) break;
			for(Node e : edge[node.idx]) {
				if(!visited[e.idx])
					pq.offer(e);
			}
		}
		System.out.println(res);
	}
}

class Node implements Comparable<Node> {
	int idx;
	int w;
	public Node(int idx, int w) {
		this.idx = idx;
		this.w = w;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.w, o.w);
	}
}