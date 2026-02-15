import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split("-");
		String[] p;
		int res = 0, cur;
		for(int i = 0; i < s.length; i++) {
			p = s[i].split("\\+");
			cur = 0;
			for(int j = 0; j < p.length; j++)
				cur += Integer.parseInt(p[j]);
			if(i == 0) res = cur;
			else res -= cur;
		}
		System.out.println(res);
	}
}
