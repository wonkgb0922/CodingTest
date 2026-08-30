import java.util.*;
import java.io.*;

public class Solution {
    static int n, m;
    static int p[], s[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int res, state;
        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            p = new int[m];
            s = new int[m];
            for(int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                p[i] = Integer.parseInt(st.nextToken());
                s[i] = Integer.parseInt(st.nextToken());
            }
            res = 0;
            state = 0;
            for(int i = 1; i < (1 << m); i++) {
                int sum = 0, cost = 0;
                for(int j = 0; j < m; j++) {
                    if(((1 << j) & i) > 0) {
                        cost += p[j];
                        sum += s[j];
                    }
                    if(cost > n) {
                        cost -= p[j];
                        sum -= s[j];
                        break;
                    }
                }
                if(res < sum) {
                    res = sum;
                    state = i;
                }
            }
            sb.append("#").append(t).append(" ");
            for(int i = 0; i < m; i++) {
                if((state & (1 << i)) > 0)
                    sb.append(i).append(" ");
            }
            sb.append(res).append("\n");
        }
        System.out.println(sb);
    }
}
