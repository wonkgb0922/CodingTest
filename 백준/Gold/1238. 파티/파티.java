import java.util.*;
import java.io.*;

public class Main {
	static int n, m, x;
	static ArrayList<Node>[] edge;
	static ArrayList<Node>[] reversedEdge;
	static int times[], reversedTimes[];
	static boolean visited[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		int v, u, w, cnt, max = 0;
		edge = new ArrayList[n + 1];
		reversedEdge = new ArrayList[n + 1];
		times = new int[n + 1];
		reversedTimes = new int[n + 1];
		visited = new boolean[n + 1];
		for(int i = 1; i <= n; i++) {
			edge[i] = new ArrayList<>();
			reversedEdge[i] = new ArrayList<>();
		}
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			u = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			edge[v].add(new Node(u, w));
			reversedEdge[u].add(new Node(v, w));
		}
		PriorityQueue<Node> pq = new PriorityQueue<>();
		
		cnt = 1;
		for(Node node : edge[x])
			pq.add(node);
		visited[x] = true;
		while(!pq.isEmpty()) {
			Node t = pq.poll();
			if(visited[t.endV]) continue;
			visited[t.endV] = true;
			times[t.endV] = t.w;
			cnt++;
			if(cnt == n) break;
			for(Node node : edge[t.endV]) {
				if(!visited[node.endV])
					pq.add(new Node(node.endV, times[t.endV] + node.w));
			}
		}
//		System.out.println();
//		for(int i = 1; i <= n; i++) 
//			System.out.print(times[i] + " ");
//		System.out.println("\n");
		
		visited = new boolean[n + 1];
		visited[x] = true;
		pq.clear();
		for(Node node : reversedEdge[x])
			pq.add(node);
		cnt = 1;
		while(!pq.isEmpty()) {
			Node t = pq.poll();
			if(visited[t.endV]) continue;
			visited[t.endV] = true;
			max = Math.max(max, times[t.endV] + t.w);
			reversedTimes[t.endV] = t.w;
			cnt++;
			if(cnt == n) break;
			for(Node node : reversedEdge[t.endV]) {
				if(!visited[node.endV])
					pq.add(new Node(node.endV, reversedTimes[t.endV] + node.w));
			}
		}
		System.out.println(max);
	}
}
class Node implements Comparable<Node> {
	int endV;
	int w;
	public Node(int endV, int w) {
		this.endV = endV;
		this.w = w;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.w, o.w);
	}
}