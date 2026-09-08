import java.util.*;

class Solution {
    static int n;
    static Map<Long, Long> p = new HashMap<>();
    
    static long find(long a) {
        Long b = p.get(a);
        if(b == null) return a;
        p.put(a, find(b));
        return p.get(a);
    }
    
    static void merge(long a, long b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        p.put(a, b);
    }
    
    public long[] solution(long k, long[] room) {
        n = room.length;
        long[] answer = new long[n];
        for(int i = 0; i < n; i++) {
            answer[i] = find(room[i]);
            merge(room[i], answer[i] + 1);
        }
        return answer;
    }
}