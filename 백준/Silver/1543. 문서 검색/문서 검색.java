import java.io.*;
import java.util.*;
 
public class Main {
	static List<Integer>[] map;
	static boolean visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String f = br.readLine();
        int cnt = 0, j = 0, ii = 0;
        
        for(int i = 0; i < s.length(); i++) {
        	ii = i;
        	while(j < f.length() && ii < s.length() && s.charAt(ii) == f.charAt(j)) {
        		ii++;
        		j++;
        	}
        	if(j == f.length()) {
        		i = ii - 1;
        		cnt++;
        	}
        	j = 0;
        }
        System.out.println(cnt);
    }
}