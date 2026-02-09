import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int ary[] = new int[n];
		int l = 0, r = 0;
		for(int i = 0; i < n; i++) {
			ary[i] = Integer.parseInt(st.nextToken());
			l = Math.max(l, ary[i]);
			r += ary[i];
		}
		int sum, cnt, mid;
		while(l <= r) {
			mid = (l + r) / 2;
			sum = 0;
			cnt = 0;
			for(int i = 0; i < n; i++) {
				if(sum + ary[i] > mid) {
					sum = 0;
					cnt++;
				}
				sum += ary[i];
			}
			if(sum > 0) cnt++;
			if(cnt <= m)
				r = mid - 1;
			else l = mid + 1;
		}		
		System.out.println(r + 1);
	}
}