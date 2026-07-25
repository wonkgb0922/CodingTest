import java.io.*;
import java.util.*;

public class Solution {
    static Set<Integer> edge[];
    static boolean[] visited;
    static int m, s;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = 10;
        edge = new Set[101];
        Queue<Integer> q;
        for(int t = 1; t <= T; t++) {
            int res = 0;
            int lev = 0;
            visited = new boolean[101];
            for(int i = 1; i <= 100; i++)
                edge[i] = new HashSet<>();
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens())
                edge[Integer.parseInt(st.nextToken())].add(Integer.parseInt(st.nextToken()));
            
            visited[s] = true;
            q = new ArrayDeque<>();
            q.offer(s);
            int cur = 1;
            while(!q.isEmpty()) {
                int qsize =  q.size();
                while(qsize-- > 0) {
                    int front = q.poll();
                    if(lev < cur) {
                        lev = cur;
                        res = front;
                    }
                    else if(front > res) res = front;
                    for(int it : edge[front]) {
                        if(visited[it])continue;
                        visited[it] = true;
                        q.offer(it);
                    }
                }
                cur++;
            }
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}