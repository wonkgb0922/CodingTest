import java.util.*;
import java.io.*;

class Main
{
	static int n;
	static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for(int i = 2; i < 8; i++)
        	dfs(1, i);
        System.out.println(sb);
        br.close();
    }
    static void dfs(int idx, int cur) {
    	if(isPrime(cur)) {
    		if(idx < n) {
    			for(int i = 1; i <= 9; i+=2)
        			dfs(idx + 1, cur * 10 + i);
    		}
    		else
    			sb.append(cur).append("\n");
    	}
    }
    
    static boolean isPrime(int num) {
    	if(num == 2) return true;
    	if((num & 1) == 0) return false;
    	for(int i = 2; i <= Math.sqrt(num); i++) {
			if(num % i == 0)
				return false;
		}
    	return true;
    }
}