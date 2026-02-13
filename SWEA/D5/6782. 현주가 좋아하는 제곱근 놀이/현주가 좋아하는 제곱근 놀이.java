import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		long n, res;
		for(int t = 1; t <= T; t++) {
			res = 0;
			n = Long.parseLong(br.readLine());
			while(n > 2) {
				long sn = (long) Math.sqrt(n);
				if(sn * sn < n) {
					sn++;
					res += sn * sn - n;
				}
				res++;
				n = sn;
			}
			sb.append(String.format("#%d %d\n", t, res));
		}
		System.out.println(sb);
	}
}