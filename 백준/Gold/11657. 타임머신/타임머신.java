import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static ArrayList<Node> edge;
	static long dis[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        edge = new ArrayList<>();
        dis = new long[n + 1];
        for(int i = 2; i <= n; i++)
        	dis[i] = Integer.MAX_VALUE;
        while(m-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	edge.add(new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        for(int i = 1; i < n; i++) {
        	for(Node node : edge) {
        		if(dis[node.s] == Integer.MAX_VALUE) continue;
        		dis[node.e] = Math.min(dis[node.e], dis[node.s] + node.w);
        	}
        }
        boolean flag = false;
        for(Node node : edge) {
    		if(dis[node.s] == Integer.MAX_VALUE) continue;
    		if(dis[node.e] > dis[node.s] + node.w) {
    			flag = true;
    			break;
    		}
    	}
        if(flag)
        	sb.append("-1");
        else {
            for(int i = 2; i <= n; i++) {
            	sb.append((dis[i] == Integer.MAX_VALUE) ? -1 : dis[i]).append("\n");
            }
        }
        System.out.print(sb);
    }
}

class Node {
	int s;
	int e;
	long w;
	public Node(int s, int e, long w) {
		this.s = s;
		this.e = e;
		this.w = w;
	}
}