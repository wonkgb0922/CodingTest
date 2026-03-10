import java.util.*;
import java.io.*;

public class Solution {
	static int n;
	static double e;
	static int p[];
	static long[] x, y;
	
	static int find(int a) {
		if(p[a] < 0) return a;
		return p[a] = find(p[a]);
	}
	static void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		p[b] = a;
		p[a]--;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		long res;
		PriorityQueue<Edge> pq;
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			p = new int[n];
			x = new long[n];
			y = new long[n];
			pq = new PriorityQueue<>();
			res = 0;
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++) {
				p[i] = -1;
				x[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++) {
				y[i] = Integer.parseInt(st.nextToken());
				if(i > 0)
					pq.offer(new Edge((x[0] - x[i]) * (x[0] - x[i]) + 
							(y[0] - y[i]) * (y[0] - y[i]), i));
			}
			e = Double.parseDouble(br.readLine());
			while(!pq.isEmpty()) {
				Edge edge = pq.poll();
				if(find(edge.dest) == find(0)) continue;
				merge(0, edge.dest);
				res += edge.w;
				for(int i = 1; i < n; i++) {
					if(find(i) == find(edge.dest)) continue;
					pq.offer(new Edge((x[edge.dest] - x[i]) * (x[edge.dest] - x[i]) +
							(y[edge.dest] - y[i]) * (y[edge.dest] - y[i]), i));
				}
				if(p[0] == -1 * n) break;
			}
			sb.append(String.format("#%d %d\n", tc, Math.round(res * e)));
		}
		System.out.println(sb);
	}
}
class Edge implements Comparable<Edge> {
	long w;
	int dest;
	public Edge(long w, int dest) {
		this.w = w;
		this.dest = dest;
	}
	@Override
	public int compareTo(Edge o) {
		return Long.compare(this.w, o.w);
	}
}