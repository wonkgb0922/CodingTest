import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
	    int h = Integer.parseInt(st.nextToken());
	    PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
	    int k = Integer.parseInt(br.readLine());
	    int px = 0, py = 0, rx = 0, ry = 0;
	    
	    pq.offer(new Pair(0, h));
	    pq.offer(new Pair(1, w));
	    while(k-- > 0) {
	    	st = new StringTokenizer(br.readLine());
	    	int d = Integer.parseInt(st.nextToken());
	    	int v = Integer.parseInt(st.nextToken());
	    	pq.offer(new Pair(d, v));
	    }
	    while(!pq.isEmpty()) {
	    	Pair p = pq.poll();
	    	if(p.first == 0) {
	    		ry = Math.max(ry, p.second - py);
	    		py = p.second;
	    	}
	    	else {
	    		rx = Math.max(rx, p.second - px);
	    		px = p.second;
	    	}
	    }
	    System.out.println(rx * ry);
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
	public int compareTo(Pair p) {
		return Integer.compare(this.second, p.second);
	}
}
