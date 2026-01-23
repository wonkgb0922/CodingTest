import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n, m, a, b, res = 0, cnt;
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        boolean ary[][] = new boolean[n][n];

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            ary[a - 1][b - 1] = true;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n ;j++) {
                for(int k = 0; k < n; k++) {
                	if(ary[j][i] && ary[i][k])
                		ary[j][k] = true;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cnt = 0;
            for(int j = 0; j < n; j++) {
            	if(i == j) continue;
                if(ary[i][j] || ary[j][i]) cnt++;
            }
            if(cnt == n - 1) res++;
        }

        System.out.println(res);
    }
}