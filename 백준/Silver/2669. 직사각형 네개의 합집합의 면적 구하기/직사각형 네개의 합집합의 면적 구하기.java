import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int x1, y1, x2, y2, cnt = 0;
        boolean ary[][] = new boolean[100][100];
        for(int k = 0; k < 4; k++) {
        	st = new StringTokenizer(br.readLine());
        	x1 = Integer.parseInt(st.nextToken());
        	y1 = Integer.parseInt(st.nextToken());
        	x2 = Integer.parseInt(st.nextToken());
        	y2 = Integer.parseInt(st.nextToken());
        	for(int i = y1; i < y2; i++) {
        		for(int j = x1; j < x2; j++) {
        			if(ary[i][j] == false)
        				cnt++;
        			ary[i][j] = true;
        		}
        	}        	
        }
        System.out.println(cnt);
        br.close();
    }
}
