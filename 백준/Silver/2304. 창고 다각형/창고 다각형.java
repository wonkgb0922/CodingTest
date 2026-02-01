import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        
        int n = Integer.parseInt(br.readLine());
        int pos, val;
        while(n-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	pos = Integer.parseInt(st.nextToken());
        	val = Integer.parseInt(st.nextToken());
        	pq.offer(new Pair(pos, val));
        }
        Pair p = pq.poll();
        int l = p.first, r = p.first;
        int res = p.second;
        while(!pq.isEmpty()) {
        	p = pq.poll();
        	if(p.first < l) {
        		res += (l - p.first) * p.second;
        		l = p.first;
        	}
        	if(r < p.first) {
        		res += (p.first - r) * p.second;
        		r = p.first;
        	}
        }
        System.out.println(res);
        br.close();
    }
}

class Pair implements Comparable<Pair> {
	int first;
	int second;
	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
	public int compareTo(Pair o) {
		return Integer.compare(o.second, this.second);
	}
}