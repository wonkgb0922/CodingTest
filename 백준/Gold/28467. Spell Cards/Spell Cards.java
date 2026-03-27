import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static ArrayDeque<Long> stack;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        long sum = 0, in, peek;
        stack = new ArrayDeque<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
        	in = Long.parseLong(st.nextToken());
        	while(!stack.isEmpty() && stack.peekLast() <= in) {
        		if(stack.size() == 1) {
    				sum += stack.pollLast() + in;
    				break;
    			}
    			peek = stack.pollLast();
				if(stack.peekLast() < in)
					sum += stack.peekLast() + peek;
				else
					sum += in + peek;
        	}
        	stack.addLast(in);
        	
        }
        while(stack.size() > 1) {
        	peek = stack.pollLast();
        	in = stack.pollLast();
        	sum += peek + in;
        	stack.addLast(Math.max(peek, in));
        }
        System.out.println(sum);
    }
}
