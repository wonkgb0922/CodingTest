import java.util.*;

class Solution {
    static boolean visited[];;
    static Queue<String> q;
    static int n;
    public int solution(String begin, String target, String[] words) {
        n = words.length;
        visited = new boolean[n];
        for(int i = 0; i < n; i++) {
            if(words[i].equals(begin)) {
                visited[i] = true;
                break;
            }
        }
        q = new ArrayDeque<>();
        q.offer(begin);
        int answer = 0;
        boolean solved = false;
        BFS:
        while(!q.isEmpty()) {
            int qsize = q.size();
            while(qsize-- > 0) {
                String front = q.poll();
                System.out.println(front);
                if(front.equals(target)) {
                    solved = true;
                    break BFS;
                }
                for(int i = 0; i < n; i++) {
                    if(visited[i]) continue;
                    int cnt = 0;
                    for(int j = 0; j < words[i].length(); j++) {
                        if(front.charAt(j) != words[i].charAt(j))
                            cnt++;
                        if(cnt == 2)
                            break;
                    }
                    if(cnt == 1) {
                        q.offer(words[i]);
                        visited[i] = true;
                    }
                }
                
            }
            answer++;
        }
        return solved ? answer : 0;
    }
}