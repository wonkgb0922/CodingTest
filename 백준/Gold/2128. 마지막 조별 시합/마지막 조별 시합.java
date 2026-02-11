import java.util.*;
import java.io.*;

public class Main {	
	static int ary[];
	static int n, d, k;
	static int res;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int cnt = 0, m;
		
		n = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		ary = new int[n];
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			if(m == 0) cnt++;
			while(m-- > 0)
				ary[i] |= (1 << (Integer.parseInt(st.nextToken()) - 1));
		}
		dfs(0, 0, 0);
		System.out.println(res + cnt);
	}
	
	static void dfs(int idx, int state, int cnt) {
		if(d - idx + cnt < k)
			return;
		if(cnt >= k) {
			int sum = 0;
			for(int i = 0; i < n; i++) {
				if((ary[i] & state) > 0) {
					if(Integer.bitCount(ary[i] | state) == k)
						sum++;
				}
					
			}
			res = Math.max(res, sum);
			return;
		}
		
		if(idx < d) {
			dfs(idx + 1, state, cnt);
			dfs(idx + 1, state | (1 << idx), cnt + 1);
		}
    }
}