import java.util.*;
import java.io.*;

public class Main {
	static int p[];

	static int find(int a) {
		if(p[a] == 0) return a;
		return p[a] = find(p[a]);
	}
	
	static void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		p[a] = b;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		int v, u, c, res = 0;
		Node node;
		PriorityQueue<Node> pq = new PriorityQueue<>();
		p = new int[n + 1];
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			u = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			pq.offer(new Node(v, u, c));
		}
		int cnt = 1;
		while(!pq.isEmpty()) {
			node = pq.poll();
			if(find(node.a) == find(node.b)) continue;
			merge(node.a, node.b);
			res += node.w;
			cnt++;
			if(cnt == n) break;
		}
		System.out.println(res);
	}
}

class Node implements Comparable<Node> {
	int a;
	int b;
	int w;
	public Node(int a, int b, int w) {
		this.a = a;
		this.b = b;
		this.w = w;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.w, o.w);
	}
}