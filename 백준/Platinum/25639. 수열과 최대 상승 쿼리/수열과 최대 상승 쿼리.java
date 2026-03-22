import java.util.*;
import java.io.*;

public class Main {	
	static int n, size;
	static Node t[];
	
	static void set(int p, int val) {
		p += size;
		t[p].max = val;
		t[p].min = val;
		t[p].res = 0;
		// update
		while((p >>= 1) > 0) {
			t[p].res = Math.max(t[p << 1 | 1].max - t[p << 1].min,
					Math.max(t[p << 1].res, t[p << 1 | 1].res));
			t[p].max = Math.max(t[p << 1].max, t[p << 1 | 1].max);
			t[p].min = Math.min(t[p << 1].min, t[p << 1 | 1].min);
		}
	}
	
	static int query(int l, int r) {
		int res = -1;
		l += size;
		r += size;
		Node left = new Node(), right = new Node();
		while(l <= r) {
			if((l & 1) > 0) {
				left.res = Math.max(t[l].max - left.min,
						Math.max(left.res, t[l].res));
				left.max = Math.max(left.max, t[l].max);
				left.min = Math.min(left.min, t[l].min);				
				l++;
			}
			if((r & 1) == 0) {
				right.res = Math.max(right.max - t[r].min,
						Math.max(right.res, t[r].res));
				right.max = Math.max(right.max, t[r].max);
				right.min = Math.min(right.min, t[r].min);				
				r--;
			}
			r >>= 1;
			l >>= 1;
		}
		
		res = Math.max(right.max - left.min,
				Math.max(left.res, right.res));
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		
		size = 131072;
		t = new Node[size * 2];
		for(int i = 1; i < size * 2; i++)
			t[i] = new Node();
		
		st = new StringTokenizer(br.readLine());
		int q, a, b;
		for(int i = 0; i < n; i++) {
			q = Integer.parseInt(st.nextToken());
			set(i, q);
		}
		int m = Integer.parseInt(br.readLine());
		while(m-- > 0) {
			st = new StringTokenizer(br.readLine());
			q = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken()) - 1;
			b = Integer.parseInt(st.nextToken());
			if(q == 1)
				set(a, b);
			else
				sb.append(query(a, b - 1)).append("\n");
		}
		System.out.print(sb);
	}
}

class Node {
	int min = 1000000001;
	int max = -1000000001;
	int res = -1;
	Node() {}
	Node(int min, int max, int res) {
		this.min = min;
		this.max = max;
		this.res = res;
	}
}