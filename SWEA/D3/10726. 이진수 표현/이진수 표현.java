import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int n, m, target;
        String res;
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	target = (1 << n) - 1;
        	if((m & target) == target)
        		res = "ON";
        	else
        		res = "OFF";
        	sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}
