import java.util.*;
import java.io.*;

public class Solution {
	static long res;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		int a, b, k, sum;
		for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			sum = a + b;
			res = (pow(k, sum) * a) % sum;
			if(res > sum / 2) res = sum - res;
			sb.append(String.format("#%d %d\n", t, res));
		}
		System.out.println(sb);
	}
	static long pow(int k, int mod) {
		long ret = 1;
        long num = 2;
        while (k > 0) {
            if ((k & 1) > 0)
                ret = (ret * num) % mod;
            num = (num * num) % mod;
            k /= 2;
        }
        return ret;
	}
}
