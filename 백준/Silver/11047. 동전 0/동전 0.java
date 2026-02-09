import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int[] ary = new int[n];
		for(int i = 1; i <= n; i++)
			ary[n - i] = Integer.parseInt(br.readLine());
		int res = 0;
		for(int i = 0; i < n; i++) {
			res += k / ary[i];
			k %= ary[i];
		}
		System.out.println(res);
	}
}