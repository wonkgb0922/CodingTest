import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int res = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		while(n-- > 0)
			pq.offer(Integer.parseInt(br.readLine()));
		while(pq.size() > 1) {
			int t = pq.poll() + pq.poll();
			res += t;
			pq.offer(t);
		}
		System.out.println(res);
	}
}