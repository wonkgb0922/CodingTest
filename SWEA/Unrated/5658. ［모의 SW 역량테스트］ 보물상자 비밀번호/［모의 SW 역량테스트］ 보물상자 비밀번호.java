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
		Queue<String> q;
		HashSet<String> set;
		TreeSet<Integer> pq;
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			s = br.readLine();
			set = new HashSet<>();
			q = new ArrayDeque<>();
			pq = new TreeSet<>(Collections.reverseOrder());
			q.add(s);
			while(!set.contains(q.peek())) {
				s = q.poll();
				set.add(s);
				for(int i = 0; i < n; i += n / 4)
					pq.add(Integer.parseInt(s.substring(i, i + n / 4), 16));
				
				q.add(s.substring(1).concat(s.charAt(0)+""));
			}
			Iterator<Integer> it = pq.iterator();
			while(--k > 0) it.next();
			sb.append("#").append(tc).append(" ").append(it.next()).append("\n");
		}
		System.out.println(sb);
	}
}