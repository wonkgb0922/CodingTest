import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static int p[], dis[];
	static int find(int v) {
		if(p[v] <= 0) return v;
		find(p[v]);
		dis[v] += dis[p[v]];
		p[v] = find(p[v]);
		return p[v];
	}
	static void merge(int a, int b) {
		dis[a] += Math.abs(a - b) % 1000;
		p[a] = b;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		String com;
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			p = new int[n + 1];
			dis = new int[n + 1];
			while(true) {
				st = new StringTokenizer(br.readLine());
				com = st.nextToken();
				if(com.equals("O")) break;
				else if(com.equals("E")) {
					int v = Integer.parseInt(st.nextToken());
					find(v);
					sb.append(dis[v]).append("\n");
				}
				else
					merge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
		}
		System.out.println(sb);
	}
}
