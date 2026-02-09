import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		int l = 1, r = k, mid, cnt;
		while(l <= r) {
			mid = (l + r) / 2;
			cnt = 0;
			for(int i = 1; i <= n; i++)
				cnt += Math.min(n, mid / i);
			if(cnt < k)
				l = mid + 1;
			else
				r = mid - 1;
		}
		System.out.println(r + 1);
	}
}