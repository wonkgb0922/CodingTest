import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int a, b=1, cnt, res = 3, ta, tb, temp;
        a = Integer.parseInt(br.readLine());
        for(int i = 1; i <= a; i++) {
        	cnt = 2;
        	ta = a;
        	tb = i;
        	while(ta - tb >= 0) {
        		temp = ta - tb;
        		ta = tb;
        		tb = temp;
        		cnt++;
        	}
        	if(res < cnt) {
        		b = i;
        		res = cnt;
        	}
        }
        sb.append(res).append("\n");
        sb.append(a).append(" ").append(b).append(" ");
        while(a - b >= 0) {
        	temp = a - b;
        	a = b;
        	b = temp;
        	sb.append(temp).append(" ");
        }
        System.out.println(sb);
        br.close();
    }
}
