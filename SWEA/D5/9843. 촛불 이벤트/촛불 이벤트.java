import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		long n, l, r, mid = 0, temp;
		boolean find;
		for(int tc = 1; tc <= T; tc++) {
			n = Long.parseLong(br.readLine());
			l = 0;
			r = 2000000000;
			find = false;
			while(l <= r) {
				mid = (l + r) / 2;
				temp = mid * (mid + 1) / 2;
				if(temp < n)
					l = mid + 1;
				else if(temp > n)
					r = mid - 1;
				else {
					find = true;
					break;
				}
			}
			sb.append(String.format("#%d ", tc));
			if(find)
				sb.append(mid);
			else sb.append(-1);
			sb.append("\n");
		}
		System.out.print(sb);
	}
}