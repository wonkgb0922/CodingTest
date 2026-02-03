import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static String s;
    static int res = Integer.MIN_VALUE;
    
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        s = br.readLine();

        int now = s.charAt(0) - '0';
        if(n == 1)
        	res = now;
        
        for(int i = 2; i < s.length(); i += 2) {
        	dfs(i, s.charAt(i - 1), now);
        	now = operate(now, s.charAt(i - 1), s.charAt(i) - '0');
        }
        System.out.println(res);
    }
	
	static void dfs(int idx, char exp, int cur) {
		int now = s.charAt(idx) - '0';
		if(idx == s.length() - 1) {
			now = operate(cur, exp, now);
			res = Math.max(res, now);
			return;
		}
		if(idx + 2 < s.length()) {
			dfs(idx + 2, s.charAt(idx + 1), operate(cur, exp, now));
			now = operate(now, s.charAt(idx + 1), s.charAt(idx + 2) - '0');
			if(idx + 2 == s.length() - 1) {
				now = operate(cur, exp, now);
				res = Math.max(res, now);
			}
		}
		if(idx + 4 < s.length())
			dfs(idx + 4, s.charAt(idx + 3), operate(cur, exp, now));

	}
	
	static int operate(int o1, char exp, int o2) {
		switch(exp) {
		case '+':
			return o1 + o2;
		case '-':
			return o1 - o2;		
		}
		return o1 * o2;
	}
}
