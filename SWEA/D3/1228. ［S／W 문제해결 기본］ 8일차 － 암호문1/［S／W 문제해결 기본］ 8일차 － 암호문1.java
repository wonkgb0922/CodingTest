import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = 10;
        int in;
        for(int t = 1; t <= T; t++) {
        	LinkedList<Integer> l = new LinkedList<>();
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            while(n-- > 0) {
            	in = Integer.parseInt(st.nextToken());
            	l.addLast(in);
            }
            int m = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < m; i++) {
            	LinkedList<Integer> temp = new LinkedList<>();
            	st.nextToken();
                int index = Integer.parseInt(st.nextToken());
                int k = Integer.parseInt(st.nextToken());
                while(k-- > 0) {
                	in = Integer.parseInt(st.nextToken());
                	temp.add(in);                	
                }
                l.addAll(index, temp);
            }
            sb.append("#").append(t);
            int idx = 1;
            for(int i : l) {
            	sb.append(" ").append(i);
            	if(idx > 9) break;
            	idx++;
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
