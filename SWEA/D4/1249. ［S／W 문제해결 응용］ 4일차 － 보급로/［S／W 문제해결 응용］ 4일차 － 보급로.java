import java.util.*;
import java.io.*;

public class Solution {
    static int n;
    static int[][] ary;
    static int[][] dis;

    static int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static final int INF = 1000000000;

    static PriorityQueue<Node> pq;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for(int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());
            ary = new int[n][n];
            dis = new int[n][n];
            pq = new PriorityQueue<>();
            for(int i = 0; i < n; i++) {
                Arrays.fill(dis[i], INF);
                String in = br.readLine();
                for(int j = 0; j < n; j++)
                    ary[i][j] = in.charAt(j) - '0';
            }
            pq.offer(new Node(0, 0, 0));
            while(!pq.isEmpty()) {
                Node top = pq.poll();
                if(dis[top.i][top.j] != INF) continue;
                dis[top.i][top.j] = top.w;
                if(top.i == n - 1 && top.j == n - 1) break;
                for(int d = 0; d < 4; d++) {
                    int ii = top.i + dir[d][0];
                    int jj = top.j + dir[d][1];
                    if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
                        pq.offer(new Node(ii, jj, top.w + ary[ii][jj]));
                    }
                }
            }

            sb.append("#").append(t).append(" ").append(dis[n - 1][n - 1]).append("\n");
        }
        System.out.println(sb);
    }
}

class Node implements Comparable<Node> {
    public Node(int i, int j, int w) {
        this.i = i;
        this.j = j;
        this.w = w;
    }

    @Override
    public int compareTo(Node node) {
        return Integer.compare(this.w, node.w);
    }

    public int i;
    public int j;
    public int w;
}
