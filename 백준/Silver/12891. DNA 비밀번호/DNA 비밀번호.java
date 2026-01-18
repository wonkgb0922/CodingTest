import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main  {
    static int cnt[] = new int[4];
    static int ary[] = new int[4];

    static void push(char c) {
        if (c == 'A') ary[0]++;
        else if (c == 'C') ary[1]++;
        else if (c == 'G') ary[2]++;
        else if (c == 'T') ary[3]++;
    }

    static void pop(char c) {
        if (c == 'A') ary[0]--;
        else if (c == 'C') ary[1]--;
        else if (c == 'G') ary[2]--;
        else if (c == 'T') ary[3]--;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        String str = br.readLine();

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 4; i++) {
            cnt[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < m; i++) {
            push(str.charAt(i));
        }
        int i = 0, j = m - 1, res = 0;
        boolean flag;

        while (true) {
            flag = true;
            for (int k = 0; k < 4; k++) {
                if (cnt[k] > ary[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res++;
            j++;
            if(j >= n) break;
            push(str.charAt(j));
            pop(str.charAt(i));
            i++;
        }
        System.out.println(res);
        br.close();
    }
}