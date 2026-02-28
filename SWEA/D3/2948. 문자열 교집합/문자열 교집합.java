import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		HashSet<String> s = new HashSet<>();
		String in;
		int n, m, res;
		for(int t = 1; t <= T; t++) {
			res = 0;
			s.clear();
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++)
				s.add(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < m; i++) {
				in = st.nextToken();
				if(s.contains(in)) res++;
			}
			sb.append(String.format("#%d %d\n", t, res));
		}
		System.out.println(sb);
	}
}
