import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String in = br.readLine();
        Integer ary[] = new Integer[in.length()];
        for(int i = 0; i < in.length(); i++)
        	ary[i] = in.charAt(i) - '0';
        Arrays.sort(ary, Collections.reverseOrder());
        for(int it : ary)
        	sb.append(it);
        System.out.println(sb);
    }
}