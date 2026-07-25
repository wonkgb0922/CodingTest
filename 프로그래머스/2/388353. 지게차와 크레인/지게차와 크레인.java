import java.util.*;

class Solution {
    static int n;
    static int m;
    static Set<Pos> containers[];
    static boolean isNone[][];
    static int dir[][] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    static boolean visited[][];
    static Queue<Pos> q;
    
    public int solution(String[] storage, String[] requests) {
        n = storage.length;
        m = storage[0].length();
        isNone = new boolean[n][m];
        containers = new Set[26];
        for(int i = 0; i < 26; i++)
            containers[i] = new HashSet<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                containers[storage[i].charAt(j) - 'A'].add(new Pos(i, j));
        }
        int answer = n * m;
        for(String req : requests) {
            char target = req.charAt(0);
            if(req.length() == 1) {
                // bfs를 돌면 되는데..
                visited = new boolean[n][m];
                q = new ArrayDeque<>();
                for(int i = 0; i < n; i++) {
                    q.offer(new Pos(i, 0));
                    q.offer(new Pos(i, m - 1));
                    visited[i][0] = true;
                    visited[i][m - 1] = true;
                }
                for(int i = 1; i < m - 1; i++) {
                    q.offer(new Pos(0, i));
                    q.offer(new Pos(n - 1, i));
                    visited[0][i] = true;
                    visited[n - 1][i] = true;
                }
                while(!q.isEmpty()) {
                    Pos front = q.poll();
                    // 해당 위치에 물류가 있으면 빼오고, 없으면 계속 탐색
                    if(isNone[front.i][front.j]) {
                        // 탐색
                        for(int d = 0; d < 4; d++) {
                            int ii = front.i + dir[d][0];
                            int jj = front.j + dir[d][1];
                            if(ii < 0 || ii >= n || jj < 0 || jj >= m
                              || visited[ii][jj]) continue;
                            visited[ii][jj] = true;
                            q.offer(new Pos(ii, jj));
                        }
                    }
                    else {
                        // 물류가 맞나요?
                        if(storage[front.i].charAt(front.j) == target) {
                            isNone[front.i][front.j] = true;
                            answer--;
                        }
                    }
                }
            }
            else {
                for(Pos pos : containers[target - 'A']) {
                    if(isNone[pos.i][pos.j]) continue;
                    isNone[pos.i][pos.j] = true;
                    answer--;
                }
                containers[target - 'A'].clear();
            }
        }
        
        return answer;
    }
}

class Pos {
    public Pos(int i, int j) {
        this.i = i;
        this.j = j;
    }
    @Override
    public int hashCode() {
        return i * 100 + j;
    }
    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj instanceof Pos p) {
            return this.i == p.i && this.j == p.j;
        }
        return false;
    }
    public int i;
    public int j;
    
}