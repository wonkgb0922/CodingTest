import java.util.*;
import java.io.*;

public class Solution {
	static int v, e;
	static int p[];
	
	static int find(int a) {
		if(p[a] < 0) return a;
		return p[a] = find(p[a]);
	}
	static void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		p[a] += p[b];
		p[b] = a;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		long res;
		PriorityQueue<Edge> pq = new PriorityQueue<>();;
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			p = new int[v + 1];
			pq.clear();
			for(int i = 0; i < e; i++) {
				st = new StringTokenizer(br.readLine());
				pq.offer(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Long.parseLong(st.nextToken())));
			}
			for(int i = 1; i <= v; i++)
				p[i] = -1;
			res = 0;
			while(!pq.isEmpty()) {
				Edge edge = pq.poll();
				if(find(edge.start) == find(edge.end)) continue;
				merge(edge.start, edge.end);
				res += edge.w;
				if(p[1] == -1 * v) break;
			}
			sb.append(String.format("#%d %d\n", tc, res));
		}
		System.out.print(sb);
	}
}
class Edge implements Comparable<Edge> {
	int start;
	int end;
	long w;
	public Edge(int start, int end, long w) {
		this.start = start;
		this.end = end;
		this.w = w;
	}
	@Override
	public int compareTo(Edge o) {
		return Long.compare(this.w, o.w);
	}
}