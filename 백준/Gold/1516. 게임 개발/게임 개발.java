import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static List<Integer>[] e;
	static int[] ary, dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        ary = new int[n];
        e = new List[n];
        dp = new int[n];
        int v;
        for(int i = 0; i < n; i++)
        	e[i] = new ArrayList<>();
        for(int i = 0; i < n; i++) {
        	st = new StringTokenizer(br.readLine());
        	ary[i] = Integer.parseInt(st.nextToken());
        	while(true) {
        		v = Integer.parseInt(st.nextToken());
        		if(v == -1) break;
        		e[i].add(v - 1);
        	}
        }
        for(int i = 0; i < n; i++)
        	sb.append(sol(i)).append("\n");
        System.out.print(sb);
    }
    static int sol(int idx) {
    	if(e[idx].size() == 0) return ary[idx];
    	if(dp[idx] > 0) return dp[idx];
    	for(int it : e[idx])
    		dp[idx] = Math.max(sol(it), dp[idx]);
    	dp[idx] += ary[idx];
    	return dp[idx];
    }
}