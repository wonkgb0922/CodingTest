import java.io.*;
import java.util.*;

public class Main {
	static int n, l;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		ArrayDeque<Node> dq = new ArrayDeque<>();
		st = new StringTokenizer(br.readLine());
		int in;
		
		for(int i = 0; i < n; i++) {
			in = Integer.parseInt(st.nextToken());
			while(!dq.isEmpty()) {
				if(dq.peek().idx + l <= i) dq.poll();
				else break;
			}
			if(dq.isEmpty())
				dq.push(new Node(in ,i));
			else {
				if(dq.peek().val >= in) {
                    dq = new ArrayDeque<>();
					dq.addFirst(new Node(in, i));
                }
				else {
					while(dq.peekLast().val >= in)
						dq.pollLast();
					dq.addLast(new Node(in, i));
				}
			}
			sb.append(dq.peek().val).append(" ");
		}
		System.out.print(sb);
	}
}

class Node {
	int val;
	int idx;
	public Node(int val, int idx) {
		this.val = val;
		this.idx = idx;
	}
}