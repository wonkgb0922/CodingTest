import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static String s;
	static int res = Integer.MIN_VALUE;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        LinkedList<int[]> l = new LinkedList<int[]>();
        int in;
        int res[] = new int[n];
        for(int i = 0; i < n; i++) {
        	in = Integer.parseInt(st.nextToken());
        	while(!l.isEmpty() && l.peek()[1] < in) {
        		res[l.pop()[0]] = in;
        	}
    		l.addFirst(new int[] {i, in});
        }
        while(!l.isEmpty()) {
    		res[l.pop()[0]] = -1;
        }
        for(int i = 0; i < n; i++)
        	sb.append(res[i]).append(" ");
        System.out.println(sb);
        br.close();
    }
}
