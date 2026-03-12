import java.util.*;
import java.io.*;

public class Solution {
	static int n, k;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		String s;
		HashSet<String> set;
		TreeSet<Integer> pq;
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			s = br.readLine();
			set = new HashSet<>();
			pq = new TreeSet<>(Collections.reverseOrder());
			while(!set.contains(s)) {
				set.add(s);
				for(int i = 0; i < n; i += n / 4)
					pq.add(Integer.parseInt(s.substring(i, i + n / 4), 16));
				s = s.substring(1).concat(s.charAt(0)+"");
			}
			Iterator<Integer> it = pq.iterator();
			while(--k > 0) it.next();
			sb.append("#").append(tc).append(" ").append(it.next()).append("\n");
		}
		System.out.println(sb);
	}
}