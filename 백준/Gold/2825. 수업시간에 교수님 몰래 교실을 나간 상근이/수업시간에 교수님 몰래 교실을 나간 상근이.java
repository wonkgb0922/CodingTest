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
			res += visited[cur];
			for(int i = 0; i < 1 << 10; i++) {
				if((i & cur) > 0)
					visited[i]++;
			}
		}
		System.out.println(res);
	}
}