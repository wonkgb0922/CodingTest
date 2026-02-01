import java.io.*;
import java.util.*;

public class Main {
	static int rear[] = {5, 3, 4, 1, 2, 0};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int ary[][] = new int[n][6];
        for(int i = 0; i < n; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j = 0; j < 6; j++) {
        		ary[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        int num, res = 0, sum, m, kk = 0;
        for(int k = 1; k <= 6; k++) {
        	num = k;
        	sum = 0;
        	for(int i = 0; i < n; i++) {
        		for(int j = 0; j < 6; j++) {
        			// find num
        			if(ary[i][j] == num) {
        				kk = j;
        				break;
        			}
        		}
        		if(Math.max(ary[i][kk], ary[i][rear[kk]]) == 6) {
        			if(Math.min(ary[i][kk], ary[i][rear[kk]]) == 5)
        				m = 4;
        			else m = 5;
        		}
        		else m = 6;
        		sum += m;
        		num = ary[i][rear[kk]];
        	}
        	res = Math.max(res, sum);
        }
        System.out.println(res);
        br.close();
    }
}
