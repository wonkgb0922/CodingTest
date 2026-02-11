import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		boolean isIncreasing;
		int increasing, decreasing, prev, res, cur;
		for(int t = 1; t <= T; t++) {
			int n = sc.nextInt();
			prev = 0;
			res = 0;
			increasing = 0;
			decreasing = 1;
			isIncreasing = true;
			for(int i = 0; i < n; i++) {
				cur = sc.nextInt();
				if(prev < cur) {
					if(isIncreasing) increasing++;
					else {
						isIncreasing = true;
						res += increasing * decreasing;
						increasing = 2;
					}
				}
				else {
					if(!isIncreasing) decreasing++;
					else {
						isIncreasing = false;
						increasing--;
						decreasing = 1;
					}
				}
				prev = cur;
			}
			if(!isIncreasing) {
				res += increasing * decreasing;
			}
			sb.append(String.format("#%d %d\n", t, res));
		}
		System.out.println(sb);
	}
}