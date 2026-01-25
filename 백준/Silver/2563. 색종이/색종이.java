import java.io.*;
import java.util.*;

public class Main {
	static int ary[][] = new int[100][100];
	
    public static void main(String[] args) throws Exception {
    	Set<Pair> s = new HashSet<Pair>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int r, c;
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
        	st = new StringTokenizer(br.readLine());
        	r = Integer.parseInt(st.nextToken());
        	c = Integer.parseInt(st.nextToken());
        	for(int j = 0; j < 10; j++) {
        		if(r + j >= 100) break;
        		for(int k = 0; k < 10; k++) {
        			if(c + k >= 100) break;
        			s.add(new Pair(r + j, c + k));
        		}
        	}
        }
        System.out.println(s.size());
        br.close();
    }
}
class Pair{
	int first;
	int second;
	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
	
	@Override
	public int hashCode() {
		return first * 100 + second;
	}

	@Override
	public boolean equals(Object obj) {
		Pair other = (Pair) obj;
		if (first != other.first)
			return false;
		if (second != other.second)
			return false;
		return true;
	}
}


