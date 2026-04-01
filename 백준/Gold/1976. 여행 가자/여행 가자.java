import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int p[];
	
	static int find(int a) {
		if(p[a] < 0) return a;
		return p[a] = find(p[a]);
	}
	
	static void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		p[a] = b;
	}
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        p = new int[n + 1];
        for(int i = 0; i <= n; i++)
        	p[i] = -1;
        int m = Integer.parseInt(br.readLine()) - 1;
        for(int i = 1; i <= n; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j = 1; j <= n; j++ ) {
        		if(Integer.parseInt(st.nextToken()) == 1)
        			merge(i, j);
        	}
        }
        st = new StringTokenizer(br.readLine());
        int r = find(Integer.parseInt(st.nextToken()));
        while(m-- > 0) {
        	if(r != find(Integer.parseInt(st.nextToken()))) {
        		System.out.println("NO");
        		return;
        	}
        }
        System.out.print("YES");
    }
}