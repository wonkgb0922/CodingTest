import java.util.*;
import java.io.*;

public class Solution {
    static int n, m;
    static int p[];
    static int cnt;
    static long res;

    static int find(int a) {
        if(p[a] == 0) return a;
        return p[a] = find(p[a]);
    }

    static void merge(int a, int b, int w) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        p[a] = b;
        res += w;
        cnt++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        PriorityQueue<Node> pq;

        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            p = new int[n + 1];
            pq = new PriorityQueue<>();

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                pq.offer(new Node(Integer.parseInt(st.nextToken()),
                        Integer.parseInt(st.nextToken()),
                        Integer.parseInt(st.nextToken())));
            }
            res = 0;
            cnt = 1;

            while(!pq.isEmpty() && cnt < n) {
                Node node = pq.poll();
                merge(node.v, node.u, node.w);
            }
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
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
