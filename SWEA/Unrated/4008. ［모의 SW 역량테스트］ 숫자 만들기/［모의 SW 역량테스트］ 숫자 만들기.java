import java.util.*;
import java.util.function.IntBinaryOperator;
import java.io.*;

public class Solution {	
	static int n;
	static int ary[];
	static int max, min;
	static IntBinaryOperator op[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		op = new IntBinaryOperator[4];
		op[0] = Integer::sum;
		op[1] = Math::subtractExact;
		op[2] = Math::multiplyExact;
		op[3] = (i1, i2) -> i1 / i2;
		int state;		
		for(int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			state = 0;
			ary = new int[n];
			max = Integer.MIN_VALUE;
			min = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 4; i++)
				state |= Integer.parseInt(st.nextToken()) << i * 8;
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; i++)
				ary[i] = Integer.parseInt(st.nextToken());
			
			sol(0, state, ary[0]);
			sb.append(String.format("#%d %d\n", t, max - min));
		}
		System.out.println(sb);
	}
	static void sol(int idx, int state, int cur) {
		if(idx == n - 1) {
			max = Math.max(max, cur);
			min = Math.min(min, cur);
		}
		int diff = (1 << 8) - 1;
		for(int i = 0; i < 4; i++) {
			if((diff & (state >> (i * 8))) > 0)
				sol(idx + 1, state - (1 << (i * 8)), op[i].applyAsInt(cur, ary[idx + 1]));
		}
	}
}