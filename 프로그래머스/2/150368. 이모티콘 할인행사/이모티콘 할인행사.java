class Solution {
    
    // i0% 할인
    static int emoticons[];
    static int ary[];
    static int[][] users;
    static int max1, max2;
    
    static void dfs(int idx) {
        if(idx >= emoticons.length) {
            int sub = 0;
            int val = 0;
            
            for(int i = 0; i < users.length; i++) {
                int sum = 0;
                for(int j = 0; j < ary.length; j++) {
                    if(ary[j] >= users[i][0])
                        sum += emoticons[j] * (100 - ary[j]) / 100;
                }
                if(sum >= users[i][1]) {
                    sub++;
                    sum = 0;
                }
                val += sum;
            }
            if(max1 <= sub) {
                if(max1 == sub)
                    max2 = Math.max(max2, val);
                else
                    max2 = val;
                max1 = sub;       
            }
            return;
        }
        for(int i = 1; i < 5; i++) {
            ary[idx] = i * 10;
            dfs(idx + 1);
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int[2];
        ary = new int[emoticons.length];
        this.emoticons = emoticons;
        this.users = users;
        
        dfs(0);
        answer[0] = max1;
        answer[1] = max2;
        return answer;
    }
}