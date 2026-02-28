import java.util.*;
import java.io.*;

public class Main {
	static boolean comp[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		comp = new boolean[10000001];
		int i, j;
		comp[1] = true;
		for(i = 2; i <= 10000000; i++) {
			if(comp[i]) continue;
			for(j = 2; i * j <= 10000000; j++)
				comp[i * j] = true;
		}
		for(i = n;; i++) {
			if(comp[i]) continue;
			
			if(isPal(i)) {
				System.out.println(i);
				break;
			}
		}
	}
	static boolean isPal(int n) {
		String s = n + "";
		int i = 0, j = s.length() - 1;
		while(i < j) {
			if(s.charAt(i) != s.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}
}
