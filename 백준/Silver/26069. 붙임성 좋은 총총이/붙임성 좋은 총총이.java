import java.util.*;
import java.io.*;

class Main
{
	static int n;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        Set<String> s = new HashSet<>();
        String[] in;
        
        s.add("ChongChong");
        while(n-- > 0) {
        	in = br.readLine().split(" ");
        	if(s.contains(in[0]))
        		s.add(in[1]);
        	if(s.contains(in[1]))
        		s.add(in[0]);
        }
        System.out.println(s.size());
    }
    
}