import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static boolean visited[];
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        int cnt = 0;
        visited = new boolean[1 << n];
//        sb = new StringBuilder(1 << n);
        String in = br.readLine();
        int p = 0;
        for(int i = 0; i < n; i++) {
        	p += (in.charAt(i) == '1') ? (1 << (n - i - 1)) : 0;
        }
        while(true) {
        	visited[p] = true;
    		for(int i = 32 - Integer.numberOfLeadingZeros(p); i < n; i++)
    			sb.append(0);
    		if(p > 0)
    			sb.append(Integer.toBinaryString(p));
    		sb.append("\n");
    		p = ~p;
    		p &= ((1 << n) - 1);
    		int idx = 0;
    		int next = p;
    		while(visited[next] && idx < n) {
    			if(((p >> idx) & 1) > 0)
    				next = p & ~(1 << idx);
    			else
    				next = p | (1 << idx);
    			next &= ((1 << n) - 1);
    			idx++;
    		}

    		if(idx >= n) break;
    		p = next;
        }
		System.out.print(sb);
    }
}
