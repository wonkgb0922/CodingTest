import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static long f[];
	
	static void add(int i, long val) {
		while(i <= n) { 
			f[i] += val;
			i += (i & -i);
		}
	}
	
	static long sum(int i) {
		long sum = 0;
		while(i > 0) {
			sum += f[i];
			i -= (i & -i);
		}
		return sum;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		f = new long[n + 1];
		int ary[] = new int[n + 1];
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) {
			ary[i] = Integer.parseInt(st.nextToken());
			add(i, ary[i] - ary[i - 1]);
		}
		int m = Integer.parseInt(br.readLine());
		int command, a, b, c;
		
		while(m-- > 0) {
			st = new StringTokenizer(br.readLine());
			command = Integer.parseInt(st.nextToken());
			if(command == 1) {
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				add(a, c);
				add(b + 1, -c);
			}
			else {
				a = Integer.parseInt(st.nextToken());
				long r = sum(a);
				sb.append(r).append("\n");
			}
		}
		System.out.print(sb);
	}
}