import java.io.*;
import java.util.*;

public class Main {
	static int ary[][] = new int[6][2];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        
        for(int t = 0; t < n; t++) {
        	st = new StringTokenizer(br.readLine());
        	int s = Integer.parseInt(st.nextToken());
        	int y = Integer.parseInt(st.nextToken());
        	ary[y - 1][s]++;
        }
        int res = 0;
        for(int i = 0; i < 6; i++) {
        	for(int j = 0; j < 2; j++)
        		res += ary[i][j] / k + (ary[i][j] % k > 0 ? 1 : 0);
        }
        System.out.println(res);
        br.close();
    }
}
