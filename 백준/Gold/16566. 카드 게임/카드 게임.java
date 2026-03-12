import java.util.*;
import java.io.*;

public class Main {
	static int n, m, k;
	static int p[];
	
	static int find(int v) {
		if(p[v] <= 0) return v;
		return p[v] = find(p[v]);
	}
	
	static void merge(int a) {
		int pa = find(a);
		p[pa] = find(pa + 1);
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		p = new int[n + 1];
		int v;
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			p[i] = i + 1;
		p[n] = 0;
		for(int i = 0; i < m; i++)
			p[Integer.parseInt(st.nextToken())] = 0;
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < k ; i++) {
			v = Integer.parseInt(st.nextToken());
			sb.append(find(v + 1)).append("\n");
			merge(v + 1);
		}
		System.out.println(sb);
	}
}