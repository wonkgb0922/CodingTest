import java.util.*;
import java.io.*;

public class Main {
	static int n, m, k;
	static int p[];
	
	static void merge(int a, int b) {
		if(p[a] == b) return;
		
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
		for(int i = 1; i <= n; i++)
			p[i] = -1;
		st = new StringTokenizer(br.readLine());
		int s;
		for(int i = 0; i < m; i++) {
			 v = Integer.parseInt(st.nextToken());
			 s = v - 1;
			 while(s > 0) {
				 if(p[s] > 0 && p[s] < v) break;
				 p[s] = v;
				 s--;
			 }
		}
//		for(int i = 1; i <= n; i++) {
//			 System.out.print(p[i] + " ");
//		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < k ; i++) {
			v = Integer.parseInt(st.nextToken());
			sb.append(p[v]).append("\n");
			p[v] = p[p[v]];
		}
		System.out.println(sb);
	}
}
