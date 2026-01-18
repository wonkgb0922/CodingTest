import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main  {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int ary[] = new int[n], res = 0;
        for(int i = 0; i < n; i++) {
            ary[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(ary);
        int i = 0, j = n - 1;

        while(i < j) {
            if(ary[i] + ary[j] == m) {
                res++;
                i++;
                j--;
            }
            else if(ary[i] + ary[j] < m) {
                i++;
            }
            else j--;
        }
        System.out.println(res);
        br.close();
    }
}