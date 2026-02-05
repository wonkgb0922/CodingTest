import java.util.*;
import java.io.*;

class Solution
{
	static int res[];
	static int ary[];
	static int s[];
	static int n, x;
	static int tot;
	static List<Record> l = new LinkedList<Record>();
	
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        
        for(int t = 1; t <= T; t++) {
        	l.clear();
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	x = Integer.parseInt(st.nextToken());
        	int m = Integer.parseInt(st.nextToken());
        	ary = new int[n];
        	res = new int[n];
        	s = new int[n + 1];
        	tot = -1;

        	while(m-- > 0) {
        		st = new StringTokenizer(br.readLine());
        		l.add(new Record(Integer.parseInt(st.nextToken()) - 1,
        				Integer.parseInt(st.nextToken()) - 1,
        				Integer.parseInt(st.nextToken())));
        	}
        	dfs(0);
        	sb.append("#").append(t).append(" ");
        	if(tot == -1)
            	sb.append("-1\n");
            else {
            	for(int i = 0; i < n; i++)
            		sb.append(res[i]).append(" ");
            	sb.append("\n");
            }
        }        	
        System.out.println(sb);
    }
	
	static void dfs(int idx) {
		if(idx == n) {
			for(Record r : l) {
				if(s[r.end + 1] - s[r.start] != r.s)
					return;
			}
			if(tot < s[idx]) {
				tot = s[idx];
				res = Arrays.copyOf(ary, n);
			}
			return;
		}
		for(int i = 0; i <= x; i++) {
			ary[idx] = i;
			s[idx + 1] = s[idx] + i;
			dfs(idx + 1);
		}
		
	}
}

class Record {
	int start;
	int end;
	int s;
	Record(int start, int end, int s) {
		this.start = start;
		this.end = end;
		this.s = s;
	}
}