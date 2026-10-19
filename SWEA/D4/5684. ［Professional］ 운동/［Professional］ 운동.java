import java.util.*;
import java.io.*;

public class Solution {
    static int n, m, res;
    static int dis[];
    static boolean visited[];

    static final int INF = 4000001;
    static List<Node> edge[];
    static PriorityQueue<Node> pq;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            res = INF;
            visited = new boolean[n];
            dis = new int[n];
            edge = new List[n];
            for(int i = 0; i < n; i++)
                edge[i] = new ArrayList<>();

            for(int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken()) - 1;
                int e = Integer.parseInt(st.nextToken()) - 1;
                int c = Integer.parseInt(st.nextToken());
                edge[s].add(new Node(e, c));
            }

            for(int i = 0; i < n; i++) {
                // dis 초기화
                Arrays.fill(dis, INF);
                Arrays.fill(visited, false);
                // pq 초기화
                pq = new PriorityQueue<>();

                pq.offer(new Node(i, 0));
                while(!pq.isEmpty()) {
                    Node top = pq.poll();

                    if(top.v == i && top.c != 0) {
                        // 싸이클 존재
                        res = Math.min(res, top.c);
                        break;
                    }
                    visited[top.v] = true;
                    for(Node node : edge[top.v]) {
                        if((!visited[node.v] || node.v == i) && node.c + top.c < dis[node.v]) {
                            dis[node.v] = node.c + top.c;
                            pq.offer(new Node(node.v, top.c + node.c));
                        }
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