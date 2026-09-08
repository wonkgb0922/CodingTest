import java.util.*;

class Solution {
    static int n;
    static int p[];
    static int res;
    static int cnt = 1;
    
    static int find(int v) {
        if(p[v] < 0) return v;
        return p[v] = find(p[v]);
    }
    
    static void merge(int a, int b, int w) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        p[b] += p[a];
        p[a] = b;
        cnt++;
        res += w;
    }
    public int solution(int N, int[][] costs) {
        n = N;
        p = new int[n];
        for(int i = 0; i < n; i++)
            p[i] = -1;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        
        for(int i = 0; i < costs.length; i++) {
             pq.offer(new Node(costs[i][0], costs[i][1], costs[i][2]));
        }
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            merge(node.v, node.u, node.w);
        }
        
        return res;
    }
}

class Node implements Comparable<Node> {
    public Node(int v, int u, int w) {
        this.v = v;
        this.u = u;
        this.w = w;
    }
    public int compareTo(Node node) {
        return Integer.compare(this.w, node.w);
    }
    
    public int v;
    public int u;
    public int w;
    
}