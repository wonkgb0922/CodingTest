import java.util.*;
import java.io.*;

public class Solution {
	static int v, e;
	static Node tree[];
	static int a, b;
	static int root;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		int p, c;
		for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			tree = new Node[v + 1];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < e; i++) {
				p = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				if(tree[p] == null) tree[p] = new Node();
				tree[p].children.add(c);
			}
			root = 1;
			isExist(1);
			sb.append(String.format("#%d %d %d", t, root, preOrder(root)));
			sb.append("\n");
		}
		System.out.println(sb);
	}
	static boolean isExist(int idx) {
		if(idx > v) return false;
		if(idx == a || idx == b) return true;
		if(tree[idx] == null) return false;
		boolean ret = true;
		boolean a = isExist(tree[idx].children.get(0));
		if(tree[idx].children.size() > 1) {
			boolean b = isExist(tree[idx].children.get(1));
			ret =  a || b;
			if (a && b)
				root = idx;
		}
		else ret = a;
		
		return ret;
	}
	static int preOrder(int idx) {
		if(idx > v) return 0;
		if(tree[idx] == null) return 1;
		int ret = 0;
		for(int it : tree[idx].children) {
			ret += preOrder(it);
		}
		return ret + 1;
	}
}

class Node {
	ArrayList<Integer> children;
	Node() {
		children = new ArrayList<>();
	}
}