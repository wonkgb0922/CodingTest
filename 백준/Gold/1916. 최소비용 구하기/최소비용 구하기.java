import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static boolean visited[];
	static ArrayList<Node>[] edge;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		int v, u, w, res = 0;
		visited = new boolean[n + 1];
		edge = new ArrayList[n + 1];
		for(int i = 1; i <= n; i++) {
			edge[i] = new ArrayList<>();
		}
		while(m-- > 0) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			u = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			edge[v].add(new Node(u, w));
		}
		st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		u = Integer.parseInt(st.nextToken());
		PriorityQueue<Node> pq = new PriorityQueue<>();
		for(Node node : edge[v])
			pq.offer(node);
		while(!pq.isEmpty()) {
			Node t = pq.poll();
			if(visited[t.endIdx]) continue;
			visited[t.endIdx] = true;
			if(t.endIdx == u) {
				res = t.w;
				break;
			}
			for(Node node : edge[t.endIdx]) {
				if(!visited[node.endIdx])
					pq.offer(new Node(node.endIdx, node.w + t.w));
			}
		}
		System.out.println(res);
	}
}

class Node implements Comparable<Node> {
	int endIdx;
	int w;
	public Node(int endIdx, int w) {
		this.endIdx = endIdx;
		this.w = w;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.w, o.w);
	}	
}