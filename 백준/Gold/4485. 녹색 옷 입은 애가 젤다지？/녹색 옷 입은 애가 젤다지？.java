import java.io.*;
import java.util.*;
 
public class Main {
	static int dir[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        PriorityQueue<Node> pq;
        int t = 1, n, i, j, next;
        int ary[], dis[];
        Node v;
        while(true) {
        	n = Integer.parseInt(br.readLine());
        	if(n == 0) break;
            ary = new int[n * n];
            dis = new int[n * n];
            pq = new PriorityQueue<>();
            for(i = 0 ; i < n; i++) {
                st = new StringTokenizer(br.readLine());
            	for(j = 0; j < n; j++) {
            		ary[i * n + j] = Integer.parseInt(st.nextToken());
            		dis[i * n + j] = Integer.MAX_VALUE;
            	}
            }
            dis[0] = ary[0];
            pq.offer(new Node(ary[0], 0));
            while(!pq.isEmpty()) {
            	v = pq.poll();
            	i = v.idx / n;
            	j = v.idx % n;
            	for(int k = 0; k < 4; k++) {
            		int ii = i + dir[k][0];
            		int jj = j + dir[k][1];
            		next = ii * n + jj;
            		if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
            			if(dis[next] > dis[v.idx] + ary[next]) {
            				dis[next] = dis[v.idx] + ary[next];
                			pq.offer(new Node(ary[next], next));
            			}
            		}
            	}
            }
            sb.append("Problem ").append(t++).append(": ").append(dis[n * n - 1]).append("\n");
        }
        System.out.println(sb);
    }
}

class Node implements Comparable<Node> {
	int val;
	int idx;
	Node(int val, int idx) {
		this.val = val;
		this.idx = idx;
	}
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.val, o.val);
	}
}