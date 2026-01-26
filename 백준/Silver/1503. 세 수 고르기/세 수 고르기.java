import java.io.*;
import java.util.*;

public class Main {
	static boolean no[] = new boolean[1002];
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        if(m > 0) st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++) {
        	no[Integer.parseInt(st.nextToken())] = true;
        }
        int res = Integer.MAX_VALUE;
        
        for(int i = 1; i <= 1001; i++) {
        	if(no[i]) continue;
        	for(int j = i; j <= 1001; j++) {
            	if(no[j]) continue;
        		for(int k = j; k <= 1001; k++) {
                	if(no[k]) continue;
                	res = Math.min(res, Math.abs(n - (i * j * k)));
        		}
        	}
        }
        System.out.println(res);
        br.close();
    }
}
