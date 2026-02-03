import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int cnt[] = new int[10001];
        while(n-- > 0)
        	cnt[Integer.parseInt(br.readLine())]++;
        for(int i = 0; i < 10001; i++)
        	while(cnt[i]-- > 0)
        		sb.append(i).append("\n");
        System.out.println(sb);
    }
}