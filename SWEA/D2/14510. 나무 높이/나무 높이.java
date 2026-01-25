import java.util.Scanner;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution
{
	static int ary[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int n, m, res, oddCnt, max, even;
        
        for(int t = 1; t <= T; t++) {
            res = 0;
            n = Integer.parseInt(br.readLine());
            ary = new int[n];
            max = 0;
            oddCnt = 0;
            even = 0;
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++) {
                ary[i] = Integer.parseInt(st.nextToken());
                max = Math.max(max, ary[i]);
            }
            
            for(int i = 0; i < n; i++) {
                if(max == ary[i]) continue;
                if((max - ary[i]) % 2 == 1) {
                	oddCnt++;
                	ary[i]++;
                }
                even += max - ary[i];
            }
            even -= oddCnt * 2;
            res = oddCnt * 2;
            if(even < 0) {
            	res -= 1; 
            }
            else if (even > 0){
            	int timesThree = even / 3;
            	res += (timesThree * 2) + (even % 3);
            }
            
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
        br.close();
    }
}