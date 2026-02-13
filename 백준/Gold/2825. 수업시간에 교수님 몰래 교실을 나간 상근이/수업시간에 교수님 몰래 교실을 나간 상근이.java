import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		long visited[] = new long[1 << 10];
		String in;
		long res = 0;
		int cur;
		while(n-- > 0) {
			cur = 0;
			in = br.readLine();
			for(int i = 0; i < in.length(); i++) {
				int bias = in.charAt(i) - '0';
				cur |= 1 << bias;
			}
			visited[cur]++;
		}
		for(int i = 0; i < 1 << 10; i++) {
			res += visited[i] * (visited[i] - 1) / 2;
			for(int j = i + 1; j < 1 << 10; j++) {
				if((i & j) > 0) res += visited[i] * visited[j];
			}
		}
		System.out.println(res);
	}
}