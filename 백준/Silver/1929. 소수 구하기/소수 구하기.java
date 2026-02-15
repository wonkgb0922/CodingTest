import java.util.*;
import java.io.*;

public class Main {
	static boolean comp[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		comp = new boolean[n + 1];
		for(int i = 2; i <= n; i++) {
			if(comp[i] == true) continue;
			for(int j = 2; i * j <= n; j++)
				comp[i * j] = true;
		}
		comp[1] = true;
		for(int i = m; i <= n; i++) {
			if(comp[i] == false)
				sb.append(i).append("\n");
		}
		System.out.println(sb);
	}
}
