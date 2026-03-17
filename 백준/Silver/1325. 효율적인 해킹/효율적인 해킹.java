import java.util.*;
import java.io.*;

public class Main {
	static int n, m;
	static ArrayList<Integer>[] edge;
	static boolean visited[];
	static int res[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		edge = new ArrayList[n + 1];
		res = new int[n + 1];
		for(int i = 1; i <= n; i++)
			edge[i] = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			edge[Integer.parseInt(st.nextToken())].add(Integer.parseInt(st.nextToken()));
		}
		Queue<Integer> q = new ArrayDeque<>();
		int p, max = 0;
		for(int i = 1; i <= n; i++) {
			visited = new boolean[n + 1];
			q.clear();
			q.offer(i);
			visited[i] = true;
			while(!q.isEmpty()) {
				p = q.poll();
				visited[p] = true;
				for(int it : edge[p]) {
					if(!visited[it]) {
						visited[it] = true;
						res[it]++;
						q.offer(it);
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) 
			max = Math.max(max, res[i]);
		for(int i = 1; i <= n; i++) 
			if(res[i] == max)
				sb.append(i).append(" ");
		System.out.println(sb);
	}
}
