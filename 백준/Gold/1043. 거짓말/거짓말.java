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
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        p = new int[n + 1];
        for(int i = 0; i <= n; i++) 
        	p[i] = -1;
        int m = Integer.parseInt(st.nextToken());
        int v[] = new int[m];
        st = new StringTokenizer(br.readLine());
        int q = Integer.parseInt(st.nextToken());
        for(int i = 0; i < q; i++)
        	merge(0, Integer.parseInt(st.nextToken()));
        
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            q = Integer.parseInt(st.nextToken()) - 1;
            v[i] = Integer.parseInt(st.nextToken());
            while(q-- > 0)
            	merge(v[i], Integer.parseInt(st.nextToken()));
        }
        int res = 0;
        for(int i = 0; i < m; i++)
        	if(find(0) != find(v[i])) res++;        
        System.out.println(res);
    }
}
