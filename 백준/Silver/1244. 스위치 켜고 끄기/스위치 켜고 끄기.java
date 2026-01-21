import java.io.*;
import java.util.StringTokenizer;

public class Main  {
    static int ary[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        ary = new int[n];
        for(int i = 0; i < n; i++) {
            ary[i] = Integer.parseInt(st.nextToken());
        }
        int m = Integer.parseInt(br.readLine());
        int g, k;
        while(m-- > 0) {
            st = new StringTokenizer(br.readLine());
            g = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            if(g == 1) {
                for(int i = 1; k * i <= n; i++) {
                    turnSwitch(k * i - 1);
                }
            }
            else {
                k--;
                turnSwitch(k);
                for(int i = 1; i < n; i++) {
                    if(k - i < 0 || k + i >= n)
                        break;
                    if(ary[k + i] != ary[k - i])
                        break;
                    turnSwitch(k + i);
                    turnSwitch(k - i);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            sb.append(ary[i]).append(" ");
            if((i+ 1) % 20 == 0) sb.append("\n");
        }
        System.out.println(sb);
    }
    static void turnSwitch(int idx) {
        ary[idx] = (ary[idx] + 1) % 2;
    }
}