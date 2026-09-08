import java.util.*;

class Solution {
    static int p[];
    
    static int find(int a) {
        if(p[a] == 0) return a;
        return p[a] = find(p[a]);
    }
    
    static void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        p[a] = b;
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        p = new int[n + 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(computers[i][j] == 1) merge(i + 1, j + 1);
            }
        }
        for(int i = 1; i <= n; i++)
            if(p[i] == 0) answer++;
        
        return answer;
    }
}