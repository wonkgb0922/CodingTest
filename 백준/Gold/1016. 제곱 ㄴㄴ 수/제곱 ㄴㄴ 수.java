import java.io.*;
import java.util.*;

public class Main {
	static boolean isN[];
	static long min, max;
	static int n, res;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		min = Long.parseLong(st.nextToken());
		max = Long.parseLong(st.nextToken());
		n = (int)(max - min) + 1;
		isN = new boolean[n];
		long sq, start, temp;
		for(int i = 2; ; i++) {
			sq = (long)i * i;
			start = min / sq + ((min % sq > 0) ? 1 : 0);
			temp = sq * start;
			if(sq > max) break;
			while(min <= temp && temp <= max) {
				isN[(int)(temp - min)] = true;
				temp += sq;
			}
		}
		for(int i = 0; i < n; i++)
			if(!isN[i]) res++;
		System.out.println(res);
	}
}
