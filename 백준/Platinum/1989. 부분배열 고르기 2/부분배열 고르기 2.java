import java.util.Arrays;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main
{
	static long s[];
	static int seg[];
	static int n;
	static long res = -1;
	static int resi = 0, resj = 0;
	
	static void initSeg() {
		for(int i = n - 1; i >= 0; i--) {
			seg[i] = Math.min(seg[i << 1], seg[i << 1 | 1]);
		}
	}
	
	static int min(int l, int r) {
		int ret = Integer.MAX_VALUE;
		l += n;
		r += n;
		while(l < r) {
			if ((l & 1) > 0)
				ret = Math.min(ret, seg[l++]);
			if ((r & 1) > 0)
				ret = Math.min(ret, seg[--r]);
			l /= 2;
			r /= 2;
		}
		return ret;
	}
	static void sol(int l, int r) {
		if(l == r) return;
		long ress = min(l, r)*(s[r] - s[l]);
		if(res < ress) {
			res = ress;
			resi = l + 1;
			resj = r;
		}
		int mid = l;
		long localMin = s[l + 1] - s[l];
		for(int i = l; i < r; i++) {
			if(s[i + 1] - s[i] < localMin) {
				localMin = s[i + 1] - s[i];
				mid = i;
			}
		}
		sol(l, mid);
		sol(mid + 1, r);
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int in;
        s = new long[n + 1];
        seg = new int[n * 2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i = 1; i <= n; i++) {
        	in = Integer.parseInt(st.nextToken());
        	s[i] = s[i - 1] + in;
    		seg[n + i - 1] = in;
        }
    	initSeg();
    	sol(0, n);
    	System.out.println(res);
    	System.out.printf("%d %d", resi, resj);
        
        br.close();
    }
}