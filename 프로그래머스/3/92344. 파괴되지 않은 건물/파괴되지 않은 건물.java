class Solution {
    static int[][] ary;
    static int n, m;
    public int solution(int[][] board, int[][] skill) {
        n = board.length;
        m = board[0].length;
        ary = new int[n + 1][m + 1];
        
        int r1, r2, c1, c2, d;
        for(int i = 0; i < skill.length; i++) {
            d = skill[i][5];
            if(skill[i][0] == 1) d *= -1;
            r1 = skill[i][1];
            c1 = skill[i][2];
            r2 = skill[i][3];
            c2 = skill[i][4];
            ary[r1][c1] += d;
            ary[r1][c2 + 1] -= d;
            ary[r2 + 1][c1] -= d;
            ary[r2 + 1][c2 + 1] += d;
        }
        for(int i = 1; i <= m; i++)
            ary[0][i] += ary[0][i - 1];
        for(int i = 1; i <= n; i++)
            ary[i][0] += ary[i - 1][0];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) 
                ary[i][j] = ary[i - 1][j] + ary[i][j - 1] - ary[i - 1][j - 1] + ary[i][j];
        }
        int answer = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ary[i][j] + board[i][j] > 0)
                    answer++;
            }
        }
        return answer;
    }
    
    static void print() {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                System.out.print(ary[i][j] + " ");
            }
            System.out.println();
        }
    }
}