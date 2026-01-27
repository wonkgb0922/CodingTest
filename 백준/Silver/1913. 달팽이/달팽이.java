import java.io.*;
import java.util.*;

public class Main {
	static int dir[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int ary[][] = new int[n][n];
        int val = n * n;
        int i = 0, j = 0, d = 0;
        int ki = 0, kj = 0;
        while(val > 0) {
        	ary[i][j] = val;
        	if(val == m) {
        		ki = i + 1;
        		kj = j + 1;
        	}
        	int ii = i + dir[d][0];
        	int jj = j + dir[d][1];
        	if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
        		if(ary[ii][jj] != 0) {
        			d = (d + 1) % 4;
        		}
        	}
        	else
    			d = (d + 1) % 4;
        	i += dir[d][0];
        	j += dir[d][1];
        	val--;
        }
        for(i = 0; i < n; i++) {
        	for(j = 0; j < n; j++) {
        		sb.append(ary[i][j]).append(" ");
        	}
        	sb.append("\n");
        }
        sb.append(ki).append(" ").append(kj);
        System.out.println(sb);   	
    }
}