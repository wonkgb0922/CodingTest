import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        LinkedList<Integer> l = new LinkedList<Integer>();
        int res = 0;
        int c = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine());
        int d, f;
        for(int i = 0; i < n + 1; i++) {
        	st = new StringTokenizer(br.readLine());
        	d = Integer.parseInt(st.nextToken());
        	f = Integer.parseInt(st.nextToken());
        	int m = 0;
        	if(d == 1 || d == 4)
        		m = (d / 4) * c + f;
        	else
        		m = 2 * c + (d - 1) * r - f;
        	l.addFirst(m);
        }
        int cur = l.removeFirst();
        int max = 2 * r + 2 * c;
    	for(int p : l) {
            int a = Math.max(cur, p);
            int b = Math.min(cur, p);
    		res += Math.min(a - b, max + b - a);
    	}
        System.out.println(res);
        br.close();
    }
}