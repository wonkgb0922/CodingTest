import java.util.*;

class Solution {
    static int dis[];
    static List<Node> edge[];
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static final int INF = 1000000000;
    
    public int solution(int N, int[][] road, int K) {
        int answer = 1;
        dis = new int[N];
        edge = new List[N];
        for(int i = 0; i < N; i++)
            edge[i] = new ArrayList<>();
        
        Arrays.fill(dis, INF);
        for(int i = 0; i < road.length; i++) {
            road[i][0]--;
            road[i][1]--;
            edge[road[i][0]].add(new Node(road[i][1], road[i][2]));
            edge[road[i][1]].add(new Node(road[i][0], road[i][2]));
        }
        dis[0] = 0;
        for(int i = 0; i < edge[0].size(); i++)
            pq.offer(edge[0].get(i));
        while(!pq.isEmpty()) {
            Node top = pq.poll();
            if(dis[top.v] != INF) continue;
            if(top.w > K) break;
            dis[top.v] = top.w;
            answer++;
            for(Node node : edge[top.v])
                pq.offer(new Node(node.v, node.w + top.w));
        }
        return answer;
    }
}

class Node implements Comparable<Node> {
    public Node(int v, int w) {
        this.v = v;
        this.w = w;
    }
    
    @Override
    public int compareTo(Node node) {
        return Integer.compare(this.w, node.w);
    }
    
    public int v;
    public int w;
    
}