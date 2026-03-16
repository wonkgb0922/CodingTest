import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n = Long.parseLong(br.readLine());
		long res = n;
		for(int i = 2; i <= Math.sqrt(n);i++) {
			if(n % i == 0) {
				res -= res / i;
				while(n % i == 0) n /= i;	
			}
		}
		if(n > 1) {
			res -= res / n;
		}
		System.out.println(res);
	}
}
