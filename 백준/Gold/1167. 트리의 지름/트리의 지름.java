import java.util.*;
import java.io.*;

public class Main {
	static Queue<Integer> q = new ArrayDeque<>();
	static int dis[];
	static ArrayList<Node>[] l;
	static boolean visited[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		l = new ArrayList[n];
		dis = new int[n];
		visited = new boolean[n];
		int v, v2;
		for(int i = 0; i < n; i++)
			l[i] = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken()) - 1;
			while((v2 = Integer.parseInt(st.nextToken())) > 0)
				l[v].add(new Node(v2 - 1, Integer.parseInt(st.nextToken())));
		}
		bfs(0);
		int idx = 0;
		for(int i = 0; i < n; i++) {
			visited[i] = false;
			if(dis[idx] < dis[i])
				idx = i;
		}
		dis = new int[n];
		bfs(idx);
		idx = 0;
		for(int i = 0; i < n; i++)
			if(dis[idx] < dis[i])
				idx = i;
		System.out.println(dis[idx]);
	}
	static void bfs(int idx) {
		q.clear();
		q.offer(idx);
		visited[idx] = true;
		while(!q.isEmpty()) {
			int t = q.poll();
			for(Node it : l[t]) {
				if(!visited[it.v]) {
					visited[it.v] = true;
					dis[it.v] = it.w + dis[t];
					q.offer(it.v);
				}
			}
		}
	}
}

class Node {
	int v;
	int w;
	Node(int v, int w) {
		this.v = v;
		this.w = w;
	}
}