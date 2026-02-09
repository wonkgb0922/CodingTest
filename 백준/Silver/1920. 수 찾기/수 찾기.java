import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		int ary[] = new int[n];
		for(int i = 0; i < n; i++)
			ary[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(ary);
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++)
			sb.append((Arrays.binarySearch(ary, Integer.parseInt(st.nextToken())) >= 0) ? 1 : 0).append("\n");
		System.out.println(sb);
	}
}