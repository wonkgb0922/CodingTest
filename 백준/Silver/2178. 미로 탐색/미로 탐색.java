import java.util.*;
import java.io.*;

class Main
{
	static boolean visited[][];
	static int dir[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        visited = new boolean[n][m];
        String s[] = new String[n];
        for(int i = 0; i < n; i++)
        	s[i] = br.readLine();
        int res = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0][0] = true;
        boolean flag = false;
        while(!q.isEmpty()) {
        	int qsize = q.size();
        	while(qsize-- > 0) {
        		int i = q.peek() / m;
            	int j = q.poll() % m;
            	if(i == n - 1 && j == m - 1) {
            		flag = true;
            		break;
            	}
            	for(int k = 0; k < 4; k++) {
            		int ii = i + dir[k][0];
            		int jj = j + dir[k][1];
            		if(ii >= 0 && ii < n && jj >= 0 && jj < m) {
            			if(!visited[ii][jj] && s[ii].charAt(jj) == '1') {
            				visited[ii][jj] = true;
            				q.offer(ii * m + jj);
            			}
            		}
            	}
            	
        	}
        	res++;
        	if(flag) break;
        }
        System.out.println(res);
        br.close();
    }

    
}