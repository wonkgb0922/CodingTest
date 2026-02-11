import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		int res, step;
		String in;
		for(int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			res = 0;
			int nn = n / 2;
			for(int i = 0; i < n; i++) {
				in = br.readLine();
				step = Math.abs(nn - i);
				for(int j = step; j < n - step; j++) {
					res += in.charAt(j) - '0';
				}
			}
			sb.append(String.format("#%d %d\n", t, res));
		}
		System.out.println(sb);
	}
}