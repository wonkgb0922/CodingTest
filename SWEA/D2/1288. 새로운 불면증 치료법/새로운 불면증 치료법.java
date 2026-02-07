import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int cur, target = (1 << 10) - 1, op, k;
        for(int t = 1; t <= T; t++) {
        	int n = Integer.parseInt(br.readLine());
        	cur = 0;
        	k = 1;
        	for(;cur < target;k++) {
         		op = n * k;
         		while(op > 0) {
         			cur |= (1 << (op % 10));
         			op /= 10;
         		}
        	}
        	k--;
        	sb.append("#").append(t).append(" ").append(n * k).append("\n");

        }
        System.out.println(sb);
    }
}
