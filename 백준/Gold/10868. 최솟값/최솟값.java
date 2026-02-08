import java.util.*;
import java.io.*;

class Main
{
	static int n;
	static int seg[];
	
	static void update() {
		for(int i = n - 1; i >= 0; i--)
			seg[i] = Math.min(seg[i << 1], seg[i << 1 | 1]);
	}
	static int query(int l, int r) {
		int ret = Integer.MAX_VALUE;
		l += n;
		r += n;
		while(l < r) {
			if((l & 1) > 0)
				ret = Math.min(ret, seg[l++]);
			if((r & 1) > 0)
				ret = Math.min(ret, seg[--r]);
			l /= 2;
			r /= 2;
		}
		return ret;
	}
	
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        seg = new int[n * 2];
        int m = Integer.parseInt(st.nextToken());
        int a, b;
        
        for(int i = 0; i < n; i++)
        	seg[n + i] = Integer.parseInt(br.readLine());
        update();
        for(int i = 0; i < m; i++) {
        	st = new StringTokenizer(br.readLine());
        	a = Integer.parseInt(st.nextToken()) - 1;
        	b = Integer.parseInt(st.nextToken());
        	sb.append(query(a, b)).append("\n");
        }
        System.out.println(sb);
    }
}