import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static List<Integer>[] e;
	static int[] cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        e = new List[n + 1];
        cnt = new int[n + 1];
        int v, u;
        for(int i = 1; i <= n; i++)
        	e[i] = new ArrayList<>();
        for(int i = 0; i < m; i++) {
        	st = new StringTokenizer(br.readLine());
        	v = Integer.parseInt(st.nextToken());
        	u = Integer.parseInt(st.nextToken());
        	e[v].add(u);
        	cnt[u]++;
        }
        Queue<Integer> q = new ArrayDeque<>();
        for(int i = 1; i <= n; i++) {
        	if(cnt[i] == 0)
        		q.offer(i);
        }
        while(!q.isEmpty()) {
        	int t = q.poll();
        	sb.append(t).append(" ");
        	for(int it : e[t]) {
        		if(--cnt[it] == 0)
        			q.offer(it);
        	}
        }
        System.out.println(sb);
    }
}