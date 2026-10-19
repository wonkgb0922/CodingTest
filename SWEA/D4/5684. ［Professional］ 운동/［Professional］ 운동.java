import java.util.*;
import java.io.*;

public class Solution {
    static int n, m, res;
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
                Arrays.fill(visited, false);
                // pq 초기화
                pq = new PriorityQueue<>();

                pq.offer(new Node(i, 0));
                while(!pq.isEmpty()) {
                    Node top = pq.poll();
                    if(top.v[0] == i && top.v[1] != 0) {
                        // 싸이클 존재
                        res = Math.min(res, top.v[1]);
                        break;
                    }
                    visited[top.v[0]] = true;
                    for(Node node : edge[top.v[0]]) {
                        if(!visited[node.v[0]] || node.v[0] == i)
                            pq.offer(new Node(node.v[0], top.v[1] + node.v[1]));
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
        this.v[0] = v;
        this.v[1] = c;
    }

    @Override
    public int compareTo(Node node) {
        return Integer.compare(this.v[1], node.v[1]);
    }
    public int v[] = new int[2];
}