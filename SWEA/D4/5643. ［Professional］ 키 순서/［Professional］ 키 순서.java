import java.io.*;
import java.util.*;
 
public class Solution {
    static int n, m;
    static ArrayList<Integer>[] edge, redge;
    static boolean visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int v, u, cnt, res;
        
        for(int tc = 1; tc <= T; tc++) {
            n = Integer.parseInt(br.readLine());
            m = Integer.parseInt(br.readLine());
            edge = new ArrayList[n + 1];
            redge = new ArrayList[n + 1];
            visited = new boolean[n + 1];
            for(int i = 1; i <= n; i++) {
            	edge[i] = new ArrayList<>();
            	redge[i] = new ArrayList<>();
            }
            while(m-- > 0) {
                st = new StringTokenizer(br.readLine());
                v = Integer.parseInt(st.nextToken());
                u = Integer.parseInt(st.nextToken());
                edge[v].add(u);
                redge[u].add(v);
            }
            res = 0;
            for(int i = 1; i <= n; i++) {
            	visited[i] = true;
            	cnt = dfs(i);
            	cnt += rdfs(i);
            	if(cnt == n + 1) 
            		res++;
            	for(int j = 1; j <= n; j++)
            		visited[j] = false;
            }
            sb.append("#").append(tc).append(" ").append(res).append("\n");
        }
        System.out.print(sb);
    }
    static int dfs(int v) {
    	int ret = 1;
    	
    	for(Integer it : edge[v]) {
    		if(!visited[it]) {
    			visited[it] = true;
    			ret += dfs(it);
    		}
    	}
    	return ret;
    }
    static int rdfs(int v) {
    	int ret = 1;
    	for(Integer it : redge[v]) {
    		if(!visited[it]) {
    			visited[it] = true;
    			ret += rdfs(it);
    		}
    	}
    	return ret;
    }
}