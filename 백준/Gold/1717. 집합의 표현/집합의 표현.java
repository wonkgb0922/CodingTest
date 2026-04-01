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
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        p = new int[n + 1];
        for(int i = 0; i <= n; i++)
        	p[i] = -1;
        int m = Integer.parseInt(st.nextToken());
        while(m-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	if(Integer.parseInt(st.nextToken()) == 0)
        		merge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        	else {
        		if(find(Integer.parseInt(st.nextToken())) == find(Integer.parseInt(st.nextToken())))
        				sb.append("YES\n");
        		else
        			sb.append("NO\n");
        	}
        }
        System.out.print(sb);
    }
}