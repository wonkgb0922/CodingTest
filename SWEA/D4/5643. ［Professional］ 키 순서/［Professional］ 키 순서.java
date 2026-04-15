import java.io.*;
import java.util.*;

public class Solution {
	static int n, m;
	static int dis[][];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int v, u;
        
        for(int tc = 1; tc <= T; tc++) {
        	n = Integer.parseInt(br.readLine());
        	m = Integer.parseInt(br.readLine());
        	dis = new int[n + 1][n + 1];
        	while(m-- > 0) {
        		st = new StringTokenizer(br.readLine());
        		v = Integer.parseInt(st.nextToken());
        		u = Integer.parseInt(st.nextToken());
        		dis[v][u] = 1;
        	}
        	for(int k = 1; k <= n; k++) {
        		for(int i = 1; i <= n; i++) {
        			for(int j = 1; j <= n; j++)
        				dis[i][j] = (dis[i][j] & 1) | ((dis[i][k] & 1) & dis[k][j] & 1);
        		}
        	}
        	int cnt, res = 0;
        	for(int i = 1; i <= n; i++) {
        		cnt = 1;
        		for(int j = 1; j <= n; j++) {
        			// 자신에게서 뻗는 개수와 자신으로 향하는 개수를 찾으면 됨.
        			if(i == j) continue;
        			if((dis[i][j] & 1) > 0 || (dis[j][i] & 1) > 0)
        				cnt++;
        		}
        		if(cnt == n)
        			res++;
        	}
        	sb.append("#").append(tc).append(" ").append(res).append("\n");
        }
        System.out.print(sb);
    }
}