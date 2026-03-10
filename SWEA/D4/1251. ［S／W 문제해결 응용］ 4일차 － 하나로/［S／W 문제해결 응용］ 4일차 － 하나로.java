import java.util.*;
import java.io.*;

public class Solution {
	static int n, cnt;
	static double e;
	static boolean visited[];
	static long[] x, y;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		long res;
		PriorityQueue<Edge> pq;
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			visited = new boolean[n];
			x = new long[n];
			y = new long[n];
			pq = new PriorityQueue<>();
			res = 0;
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++)
				x[i] = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++) {
				y[i] = Integer.parseInt(st.nextToken());
				if(i > 0)
					pq.offer(new Edge((x[0] - x[i]) * (x[0] - x[i]) + 
							(y[0] - y[i]) * (y[0] - y[i]), i));
			}
			visited[0] = true;
			e = Double.parseDouble(br.readLine());
			cnt = 1;
			while(!pq.isEmpty()) {
				Edge edge = pq.poll();
				if(visited[edge.dest]) continue;
				visited[edge.dest] = true;
				cnt++;
				res += edge.w;
				for(int i = 1; i < n; i++) {
					if(visited[i]) continue;
					pq.offer(new Edge((x[edge.dest] - x[i]) * (x[edge.dest] - x[i]) +
							(y[edge.dest] - y[i]) * (y[edge.dest] - y[i]), i));
				}
				if(cnt == n) break;
			}
			sb.append(String.format("#%d %d\n", tc, Math.round(res * e)));
		}
		System.out.print(sb);
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