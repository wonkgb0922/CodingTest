import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static boolean visited[];
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        int idx;
        visited = new boolean[1 << n];

        String in = br.readLine();
        int p1 = 0;
        for(int i = 0; i < n; i++)
        	p1 += (in.charAt(i) == '1') ? (1 << (n - i - 1)) : 0;
		int pn = p1;
		int rpn, next = 0;
        while(true) {
        	rpn = (~pn) & ((1 << n) - 1);
        	visited[pn] = true;
        	visited[rpn] = true;
    		for(int i = 32 - Integer.numberOfLeadingZeros(pn); i < n; i++)
    			sb.append(0);
    		if(pn > 0)
    			sb.append(Integer.toBinaryString(pn));
    		sb.append("\n");
    		for(int i = 32 - Integer.numberOfLeadingZeros(rpn); i < n; i++)
    			sb.append(0);
    		if(rpn > 0)
    			sb.append(Integer.toBinaryString(rpn));
    		sb.append("\n");
    		idx = 0;
    		while(idx < n) {
        		next = pn ^ (1 << idx);
        		if(!visited[next]) break;
        		idx++;
    		}
    		if(idx == n) break;
    		pn = next;
        }
		System.out.print(sb);
    }
}
