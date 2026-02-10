import java.util.*;
import java.io.*;

class Solution
{
	static int n;
	static int q[];
	static int res;
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	q = new int[n];
        	res = 0;
        	for(int i = 0; i < n; i++)
        		queen(0, i);
        	
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
	
	static void queen(int idx, int c) {
		if(!available(idx, c))
			return;
		
		if(idx == n - 1) {
			res++;
			return;
		}
		q[idx] = c;
		for(int i = 0; i < n; i++)
			queen(idx + 1, i);
	}
	
	static boolean available(int idx, int c) {
		for(int i = 0; i < idx; i++) {
			if(q[i] == c) return false;
			if(idx - i == Math.abs(q[i] - c)) return false;
		}
		return true;
	}
}
