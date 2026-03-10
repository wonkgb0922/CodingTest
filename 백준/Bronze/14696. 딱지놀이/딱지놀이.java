import java.io.*;
import java.util.*;

public class Main {
	static int a[];
	static int b[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        int m;
        boolean f;
        
        for(int t = 1; t <= n; t++) {
        	a = new int[4];
        	b = new int[4];
        	f = false;
        	st = new StringTokenizer(br.readLine());
        	m = Integer.parseInt(st.nextToken());
        	while(m-- > 0)
        		a[Integer.parseInt(st.nextToken()) - 1]++;
        	st = new StringTokenizer(br.readLine());
        	m = Integer.parseInt(st.nextToken());
        	while(m-- > 0)
        		b[Integer.parseInt(st.nextToken()) - 1]++;
        	for(int i = 3; i >= 0; i--) {
        		if(a[i] > b[i]) {
        			f = true;
        			sb.append("A");
        			break;
        		}
        		else if(a[i] < b[i]) {
        			f = true;
        			sb.append("B");
        			break;
        		}
        	}
        	if(!f)
        		sb.append("D");
        	sb.append("\n");
        }
        System.out.println(sb);
        br.close();
    }
}
