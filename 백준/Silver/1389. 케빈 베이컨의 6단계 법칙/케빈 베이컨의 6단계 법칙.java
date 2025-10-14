import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 987654321;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] ary = new int[n + 1][n + 1];
        for(int i = 0; i <=n; i++) {
            for(int j = 0; j<= n; j++) {
                ary[i][j] = INF;
                if(i == j) ary[i][j] = 0;
            }
        }
        for(int i = 0; i < m ; i++) {
            st = new StringTokenizer(br.readLine());
            int in1 = Integer.parseInt(st.nextToken());
            int in2 = Integer.parseInt(st.nextToken());

            ary[in1][in2] = 1;
            ary[in2][in1] = 1;
        }

        for(int k = 1; k <= n; k++) {
            for(int i = 1;i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(ary[i][j] > ary[i][k] + ary[k][j])
                        ary[i][j] = ary[i][k] + ary[k][j];
                }
            }
        }
        int max = INF, sum;
        int maxi = 0;
        for(int i = 1; i <=n; i++) {
            sum = 0;
            for(int j = 1; j <= n; j++) {
                sum += ary[i][j];
            }
            if(max > sum) {
                max = sum;
                maxi = i;
            }
        }
        bw.write(Integer.toString(maxi));
        bw.flush();
        bw.close();
        br.close();
    }
}
