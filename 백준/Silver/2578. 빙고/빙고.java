import java.io.*;
import java.util.*;

public class Main {
	static boolean ary[][] = new boolean[5][5];
	
	static int getBingo(int i, int j) {
		int cnt[] = new int[4];
		int res = 0;
		
		for(int k = 0; k < 5; k++) {
			if(ary[i][k])
				cnt[0]++;
			if(ary[k][j])
				cnt[1]++;
			if(i == j) {
				if(ary[k][k]) cnt[2]++;
			}
			if(i + j == 4) {
				if(ary[k][4-k]) cnt[3]++;
			}
		}
		for(int k = 0; k < 4; k++) {
			if(cnt[k] == 5) res++;
		}
		
		return res;
	}
	
    public static void main(String[] args) throws Exception {
    	Map<Integer, Pair> m = new HashMap<Integer, Pair>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int c, cnt = 0;
        int res = 0;
        for(int i = 0; i < 5; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j = 0; j < 5; j++) {
        		c = Integer.parseInt(st.nextToken());
        		m.put(c, new Pair(i, j));
        	}
        }
        
        for(int i = 0; i < 5; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j = 1; j <= 5; j++) {
        		c = Integer.parseInt(st.nextToken());
        		Pair p = m.get(c);
        		ary[p.first][p.second] = true;
        		if(cnt >= 3) continue;
        		cnt += getBingo(p.first, p.second);
        		res = i * 5 + j;
        	}
        }
        System.out.println(res);
        br.close();
    }
}
class Pair {
	int first;
	int second;
	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}
