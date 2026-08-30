class Solution {
    static int n, m;
    static int[] ary;
    static int[][] users;
    static int[] emoticons;
    static int max1, max2;
    
    static void dfs(int idx) {
        if(idx == m) {
            int cnt1 = 0, cnt2 = 0, sum;
            
            for(int i = 0; i < n; i++) {
                sum = 0;
                for(int j = 0; j < m; j++) {
                    if(ary[j] < users[i][0]) continue;
                    sum += emoticons[j] * (100 - ary[j]) / 100;
                }
                if(sum >= users[i][1])
                    cnt1++;
                else
                    cnt2 += sum;                
            }
            if(max1 <= cnt1) {
                if(max1 < cnt1)
                    max2 = cnt2;
                else max2 = Math.max(max2, cnt2);
                max1 = cnt1;
            }
            return;
        }
        for(int i = 1; i <= 4; i++) {
            ary[idx] = i * 10;
            dfs(idx + 1);
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int[2];
        n = users.length;
        m = emoticons.length;
        
        ary = new int[m];
        this.users = users;
        this.emoticons = emoticons;
        
        dfs(0);
        answer[0] = max1;
        answer[1] = max2;
        return answer;
    }
}