class Solution {
    static int queen[];
    static boolean visited[];
    // 대각선
    static boolean visited1[];
    static boolean visited2[];
    static int n;
    
    static int dfs(int idx) {
        if(idx == n) return 1;
        int ret = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] || visited1[i + idx] || visited2[i - idx + n]) continue;
            queen[idx] = i;
            visited[i] = true;
            visited1[i + idx] = true;
            visited2[i - idx + n] = true;
            ret += dfs(idx + 1);
            visited[i] = false; 
            visited1[i + idx] = false;
            visited2[i - idx + n] = false;
        }
        return ret;
    }
    public int solution(int N) {
        int answer = 0;
        n = N;
        queen = new int[n];
        visited = new boolean[n];
        visited1 = new boolean[2 * n];
        visited2 = new boolean[2 * n];
        answer = dfs(0);
        return answer;
    }
}