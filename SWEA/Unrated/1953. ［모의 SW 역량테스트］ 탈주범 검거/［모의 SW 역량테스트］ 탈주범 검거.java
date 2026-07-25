import java.io.*;
import java.util.*;

public class Solution {
    static boolean[][] visited;
    static int n, m, r, c, l;
    static List<Integer>[] tunnel = new List[8];
    static Set<Integer>[] connect = new Set[4];
    static int dir[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static int ary[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        Queue<Pos> q;
        // 각 터널 별로 탐색할 수 있는 방향을 지정
        for(int i = 0; i < 8; i++)
            tunnel[i] = new ArrayList<>();
        tunnel[1].addAll(Arrays.asList(0, 1, 2, 3));
        tunnel[2].addAll(Arrays.asList(0, 1));
        tunnel[3].addAll(Arrays.asList(2, 3));
        tunnel[4].addAll(Arrays.asList(1, 2));
        tunnel[5].addAll(Arrays.asList(0, 2));
        tunnel[6].addAll(Arrays.asList(0, 3));
        tunnel[7].addAll(Arrays.asList(1, 3));

        // 각 방향 별로 다음에 연결될 터널의 모양을 지정
        for(int i = 0; i < 4; i++)
            connect[i] = new HashSet<>();
        connect[0].addAll(Arrays.asList(1, 2, 4, 7));
        connect[1].addAll(Arrays.asList(1, 2, 5, 6));
        connect[2].addAll(Arrays.asList(1, 3, 6, 7));
        connect[3].addAll(Arrays.asList(1, 3, 4, 5));

        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
            ary = new int[n][m];
            for(int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < m; j++)
                    ary[i][j] = Integer.parseInt(st.nextToken());
            }
            q = new ArrayDeque<>();
            visited = new boolean[n][m];
            q.offer(new Pos(r, c));
            visited[r][c] = true;
            int level = 1;
            int res = 0;
            while(!q.isEmpty()) {
                int qsize = q.size();
                while(qsize-- > 0) {
                    res++;
                    Pos front = q.poll();
                    int type = ary[front.i][front.j];
                    for(int d : tunnel[type]) {
                        int ii = front.i + dir[d][0];
                        int jj = front.j + dir[d][1];
                        if(ii < 0 || ii >= n || jj < 0 || jj >= m
                                || visited[ii][jj] || ary[ii][jj] == 0) continue;
                        if(!connect[d].contains(ary[ii][jj])) continue;
                        visited[ii][jj] = true;
                        q.offer(new Pos(ii, jj));
                    }
                }
                if(level == l) break;
                level++;
            }
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}

class Pos {
    public Pos(int i, int j) {
        this.i = i;
        this.j = j;
    }
    public int i;
    public int j;
}
