import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int in, n, max, oddCnt, left, res;
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	oddCnt = 0;
        	max = 0;
        	left = 0;
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < n; i++) {
        		in = Integer.parseInt(st.nextToken());
        		left += in;
        		max = Math.max(max, in);
        		if((in & 1) > 0)
        			oddCnt++;
        	}
        	if((max & 1) > 0)
        		oddCnt = n - oddCnt;
        	left = (max * n) - left;
        	left -= oddCnt * 3;
        	res = oddCnt * 2;
        	if(left < 0) res--;
        	else if(left > 0) {
            	int timesThree = left / 3;
            	res += (timesThree * 2) + (left % 3);
        	}
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }

}