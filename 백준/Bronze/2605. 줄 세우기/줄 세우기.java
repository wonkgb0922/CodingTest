import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        List<Integer> l = new LinkedList<Integer>();
        int n, c;
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) {
            c = Integer.parseInt(st.nextToken());
            l.add(c, i);
        }
        Collections.reverse(l);
        for(int it : l)
        	sb.append(it).append(" ");
        System.out.println(sb);
        br.close();
    }
}