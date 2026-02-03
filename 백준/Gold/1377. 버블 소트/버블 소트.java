import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ary[] = new int[n], sorted[] = new int[n];
        int in;
        int index[] = new int[1000001];
        
        for(int i = 0; i < n; i++) {
        	in = Integer.parseInt(br.readLine());
        	ary[i] = in;
        	sorted[i] = in;
        }
        Arrays.sort(sorted);
        for(int i = 0; i < n; i++)
        	index[sorted[i]] = i;
        int res = 1;
        for(int i = 0; i < n; i++)
        	res = Math.max(res, i - index[ary[i]] + 1);
        System.out.println(res);

    }
}