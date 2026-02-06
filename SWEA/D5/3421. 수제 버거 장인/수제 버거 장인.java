import java.util.*;
import java.io.*;

class Solution
{
	static int n, m;
	static int res;
	static int valid[];
	static Pair[][] se = new Pair[20][2];
	static TreeSet<Pair> s = new TreeSet<Pair>();
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int in1, in2;
        for(int i = 0; i < 20; i++) {
        	se[i][0] = new Pair(i, 0);
        	se[i][1] = new Pair(i + 1, 0);
        }
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	res = 1;
        	valid = new int[n];
            s.clear();
        	while(m-- > 0) {
        		st = new StringTokenizer(br.readLine());
        		in1 = Integer.parseInt(st.nextToken()) - 1;
        		in2 = Integer.parseInt(st.nextToken()) - 1;
        		if(in1 > in2) {
        			int temp = in1;
        			in1 = in2;
        			in2 = temp;
        		}
        		s.add(new Pair(in1, in2));
        	}
        	for(int i = 0; i < n; i++)
        		dfs(i);
        	sb.append("#").append(t).append(" ").append(res).append("\n");

        }
        System.out.println(sb);
    }
	
	static void dfs(int idx) {
		res++;
		if(idx == n - 1) return;
		
		for(Pair p : s.subSet(se[idx][0], se[idx][1]))
			valid[p.second]++;
		
		for(int i = idx + 1; i < n; i++) {
			if(valid[i] == 0)
				dfs(i);
		}
		for(Pair p : s.subSet(se[idx][0], se[idx][1]))
			valid[p.second]--;
	}
}
class Pair implements Comparable<Pair> {
	int first;
	int second;
	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
	
	@Override
	public boolean equals(Object obj) {
		Pair p = (Pair) obj;
		return this.first == p.first && this.second == p.second;
	}
	@Override
	public int hashCode() {
		return this.first * 1000 + this.second;
	}
	
	public int compareTo(Pair o) {
		int ret = Integer.compare(this.first, o.first);
		return (ret != 0) ? ret : Integer.compare(this.second, o.second);
	}

}