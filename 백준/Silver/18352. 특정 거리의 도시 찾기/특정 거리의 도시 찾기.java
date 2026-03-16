import java.util.*;
import java.io.*;

public class Main {
	static int n, m, k, x;
	static ArrayList<Integer>[] edge;
	static boolean visited[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		edge = new ArrayList[n + 1];
		visited = new boolean[n + 1];
		for(int i = 1; i <= n; i++)
			edge[i] = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			edge[Integer.parseInt(st.nextToken())].add(Integer.parseInt(st.nextToken()));
		}
		Queue<Integer> q = new ArrayDeque<>();
		PriorityQueue<Integer> res = new PriorityQueue<>();
		q.offer(x);
		int qsize, p, level = 0;
		while(!q.isEmpty()) {
			qsize = q.size();
			while(qsize-- > 0) {
				p = q.poll();
				if(visited[p]) continue;
				visited[p] = true;
				if(level == k) {
					res.offer(p);
					continue;
				}
				for(int it : edge[p]) {
					if(!visited[it])
						q.offer(it);
				}
			}
			level++;
		}
		if(res.isEmpty()) System.out.println(-1);
		while(!res.isEmpty())
			System.out.println(res.poll());
	}
}
