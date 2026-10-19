import java.util.*;
import java.io.*;

public class Solution {
    static int n, m, res;
    static int dis[];

    static final int INF = 1000000000;
    static List<Node> edge[];
    static PriorityQueue<Node> pq;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        Scanner scan = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int T = scan.nextInt();
        for (int t = 1; t <= T; t++) {
            n = scan.nextInt();
            m = scan.nextInt();

            res = INF;
            dis = new int[n];
            edge = new List[n];
            for(int i = 0; i < n; i++)
                edge[i] = new ArrayList<>();

            for(int i = 0; i < m; i++) {
                int s = scan.nextInt() - 1;
                int e = scan.nextInt() - 1;
                int c = scan.nextInt();
                edge[s].add(new Node(e, c));
            }

            for(int i = 0; i < n; i++) {
                // dis 초기화
                Arrays.fill(dis, INF);
                dis[i] = 0;
                // pq 초기화
                pq = new PriorityQueue<>();

                for(Node node : edge[i])
                    pq.offer(node);

                while(!pq.isEmpty()) {
                    Node top = pq.poll();

                    if(top.v == i) {
                        // 싸이클 존재
                        res = Math.min(res, top.c);
                        break;
                    }
                    dis[top.v] = top.c;
                    for(Node node : edge[top.v]) {
                        if(dis[node.v] == INF || node.v == i)
                            pq.offer(new Node(node.v, top.c + node.c));
                    }
                }

            }
            if(res == INF) res = -1;
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}

class Node implements Comparable<Node> {
    public Node(int v, int c) {
        this.v = v;
        this.c = c;
    }

    @Override
    public int compareTo(Node node) {
        return Integer.compare(this.c, node.c);
    }
    public int v;
    public int c;
}