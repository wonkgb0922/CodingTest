import java.util.*;
import java.io.*;

class Main
{
	static int n;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        Set<String> s = new HashSet<>();
        String in;
        int res = 0;

        while(n-- > 0) {
        	in = br.readLine();
        	if("ENTER".equals(in)) {
        		res += s.size();
        		s.clear();
        	}
        	else
        		s.add(in);
        }
        System.out.println(res + s.size());
    }
    
}