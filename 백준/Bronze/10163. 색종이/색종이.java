import java.io.*;
import java.util.*;

public class Main {
	static int ary[][] = new int[1001][1001];
	static int in[] = new int[4];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        
        for(int t = 1; t <= n; t++) {
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < 4; i++) {
        		in[i] = Integer.parseInt(st.nextToken());
        	}
        	for(int i = 0; i < in[2]; i++) {
        		if(i >= 1001) break;
        		for(int j = 0; j < in[3]; j++) {
        			if(j>= 1001) break;
        			ary[in[0] + i][in[1] + j] = t;
        		}
        	}
        }
        int res;
        for(int t = 1; t <= n; t++) {
        	res = 0;
            for(int i = 0; i <= 1000; i++) {
            	for(int j = 0; j <= 1000; j++) {
            		if(ary[i][j] == t) {
            			res++;
            		}
            	}
            }
			sb.append(res).append("\n");
        }
        System.out.println(sb);
        br.close();
        
    }
}

