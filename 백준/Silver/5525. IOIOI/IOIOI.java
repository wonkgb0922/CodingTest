import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int cnt = 0;
        String s = br.readLine();

        boolean find = false;
        int j = 0;
        for(int i = 0; i < m - 2 * n;) {
            if(find) {
                int interval = n * 2 + 1;
                if(i + interval + 1 >= m) break;
                if(s.charAt(i + interval) == 'O') {
                    if(s.charAt(i + interval + 1) == 'I') {
                        cnt++;
                        i+=2;
                    }
                    else {
                        i += interval;
                        find = false;
                    }
                }
                else {
                    i += interval;
                    find = false;
                }
            }
            else {
                if(s.charAt(i) == 'O') {
                    i++;
                    continue;
                }
                for(j = 0; j < n; j++) {
                    if(s.charAt(i + j*2 + 1) == 'I') break;
                    if(s.charAt(i + j*2 + 2) == 'O') break;
                }
                if(j == n) {
                    cnt++;
                    find = true;
                }
                else i++;
            }
        }

        bw.write(cnt+"");
        bw.flush();
        bw.close();
        br.close();
    }
}
