import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int res = 0, in;
		PriorityQueue<Integer> pq1 = new PriorityQueue<>(Collections.reverseOrder());
		PriorityQueue<Integer> pq2 = new PriorityQueue<>();
		while(n-- > 0) {
			in = Integer.parseInt(br.readLine());
			if(in > 1) 
				pq1.offer(in);
			else if(in <= 0)
				pq2.offer(in);
			else
				res += in;
		}
		while(pq1.size() > 1)
			res += pq1.poll() * pq1.poll();	
		if(!pq1.isEmpty())
			res += pq1.poll();
		while(pq2.size() > 1)
			res += pq2.poll() * pq2.poll();	
		if(!pq2.isEmpty())
			res += pq2.poll();
		System.out.println(res);
	}
}