import java.util.*;
import java.io.*;
import java.util.function.IntBinaryOperator;

public class Solution {
    static int n;
    static int ary[];
    // 0: 합, 1: 차, 2: 곱, 3: 몫
    static IntBinaryOperator op[] = new IntBinaryOperator[4];
    static int max, min;

    static void sol(int idx, int state, int cur) {
        if(idx == n - 1) {
            max = Math.max(max, cur);
            min = Math.min(min, cur);
            return;
        }
        int diff = (1 << 8) - 1;
        for(int i = 0; i < 4; i++) {
            if((diff & (state >> (i * 8))) > 0)
                sol(idx + 1, state - (1 << (i * 8)), op[i].applyAsInt(cur, ary[idx + 1]));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        op[0] = Integer::sum;
        op[1] = (a, b) -> a - b;
        op[2] = (a, b) -> a * b;
        op[3] = (a, b) -> a / b;
        for(int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            int state = 0;
            for(int i = 0; i < 4; i++)
                state |= Integer.parseInt(st.nextToken()) << i * 8;
            st = new StringTokenizer(br.readLine());
            ary = new int[n];
            for(int i = 0; i < n; i++)
                ary[i] = Integer.parseInt(st.nextToken());
            max = Integer.MIN_VALUE;
            min = Integer.MAX_VALUE;
            sol(0, state, ary[0]);
            sb.append("#").append(t).append(" ").append(max - min).append("\n");
        }
        System.out.println(sb);
    }
}
