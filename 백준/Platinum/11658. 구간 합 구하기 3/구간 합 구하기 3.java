import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static long f[][];
	
	static void add(int i, int j, long val) {
		val -= sum(i, j) - sum(i - 1, j) - sum(i, j - 1) + sum(i - 1, j - 1);
		for(int ii = i; ii <= n; ii += (ii & -ii)) {
			for(int jj = j; jj <= n; jj += (jj & -jj)) {
				f[ii][jj] += val;
			}
		}
	}
	
	static long sum(int i, int j) {
		long sum = 0;
		for(int ii = i; ii >= 1; ii -= (ii & -ii)) {
			for(int jj = j; jj >= 1; jj -= (jj & -jj))
				sum += f[ii][jj];
		}
		return sum;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		f = new long[n + 1][n + 1];
		
		for(int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= n; j++) {
				add(i, j, Integer.parseInt(st.nextToken()));
			}
		}
		int command, x1, y1, x2, y2, val;
		
		while(m-- > 0) {
			st = new StringTokenizer(br.readLine());
			command = Integer.parseInt(st.nextToken());
			if(command == 1) {
				x1 = Integer.parseInt(st.nextToken()) - 1;
				y1 = Integer.parseInt(st.nextToken()) - 1;
				x2 = Integer.parseInt(st.nextToken());
				y2 = Integer.parseInt(st.nextToken());
				long area = sum(x2, y2) - sum(x2, y1) - sum(x1, y2) + sum(x1, y1);
				sb.append(area).append("\n");
			}
			else {
				x1 = Integer.parseInt(st.nextToken());
				y1 = Integer.parseInt(st.nextToken());
				val = Integer.parseInt(st.nextToken());
				add(x1, y1, val);
			}
		}
		System.out.print(sb);
	}
}