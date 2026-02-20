import java.util.*;
import java.io.*;
 
class Solution
{
	static List<Integer> e[];
	static int cnt[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = 10;
        int n, m, v1, v2;
        Queue<Integer> q = new ArrayDeque<>();
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	sb.append(String.format("#%d ", t));
        	e = new List[n];
        	cnt = new int[n];
        	for(int i = 0; i < n; i++)
        		e[i] = new ArrayList<>();
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < m; i++) {
        		v1 = Integer.parseInt(st.nextToken()) - 1;
        		v2 = Integer.parseInt(st.nextToken()) - 1;
        		cnt[v2]++;
        		e[v1].add(v2);
        	}
        	for(int i = 0; i < n; i++)
        		if(cnt[i] == 0) q.offer(i);
        	while(!q.isEmpty()) {
        		v1 = q.poll();
        		sb.append(v1 + 1).append(" ");
        		for(int it : e[v1]) {
        			if(--cnt[it] == 0)
        				q.offer(it);
        		}
        		
        	}
        	sb.append("\n");        	
        }
        System.out.println(sb);
    }
}