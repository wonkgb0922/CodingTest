class Solution {
    static int ary[];
    static int n, cnt = 0;

    static boolean valid(int idx, int val) {
        for (int i = 0; i < n; i++) {
            if (ary[i] != 0)
                if (Math.max(idx - i, i - idx) == Math.max(val - ary[i], ary[i] - val))
                    return false;
        }
        return true;
    }

    static void dfs(int idx, int val) {
        ary[idx] = val;

        if (val == n) cnt++;
        for (int i = 0; i < n; i++) {
            if (ary[i] == 0 && valid(i, val + 1))
                dfs(i, val + 1);
        }
        ary[idx] = 0;
    }

    public int solution(int N) {
        int answer = 0;
        
        n = N;
        ary = new int[n];
        for (int i = 0; i < n; i++)
		    dfs(i, 1);
        answer = cnt;
        return answer;
    }
}