import java.io.*;
import java.util.*;

public class Main {
	static int ma, mb, mc;
	static boolean visited[][];
	static TreeSet<Integer> res = new TreeSet<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        ma = Integer.parseInt(st.nextToken());
        mb = Integer.parseInt(st.nextToken());
        mc = Integer.parseInt(st.nextToken());
        
        visited = new boolean[ma + 1][mb + 1];
        visited[0][0] = true;
        dfs(0, 0, mc);
        for(int it : res)
        	sb.append(it).append(" ");
        System.out.println(sb);
        
    }
    static void dfs(int a, int b, int c) {
    	if(a == 0)
    		res.add(c);
    	int diff = ma - a;
    	int d;
    	if(diff > 0) {
    		d = Math.min(diff, b);
    		if(!visited[a + d][b - d]) {
				visited[a + d][b - d] = true;
				dfs(a + d, b - d, c);
			}
    		d = Math.min(diff, c);
    		if(!visited[a + d][b]) {
				visited[a + d][b] = true;
				dfs(a + d, b, c - d);
			}
    	}
    	diff = mb - b;
    	if(diff > 0) {
    		d = Math.min(diff, a);
    		if(!visited[a - d][b + d]) {
				visited[a - d][b + d] = true;
				dfs(a - d, b + d, c);
			}
    		d = Math.min(diff, c);
    		if(!visited[a][b + d]) {
				visited[a][b + d] = true;
				dfs(a, b + d, c - d);
			}
    	}
    	diff = mc - c;
    	if(diff > 0) {
    		d = Math.min(diff, a);
			if(!visited[a - d][b]) {
				visited[a - d][b] = true;
				dfs(a - d, b, c + d);
			}
    		d = Math.min(diff, b);
			if(!visited[a][b - d]) {
				visited[a][b - d] = true;
				dfs(a, b - d, c + d);
			}
    	}
    }
}
