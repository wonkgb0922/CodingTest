import java.util.*;
import java.io.*;

public class Solution {
	static int ary[][];
	static int dir[][] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		int qsize, cur, level, i, j, ii, jj;
		ary = new int[4][4];
		Queue<Integer> q;
		HashSet<Integer> set;
		for(int tc = 1; tc <= T; tc++) {
			q = new ArrayDeque<>();
			set = new HashSet<>();
			for(i = 0; i < 4; i++) {
				st = new StringTokenizer(br.readLine());
				for(j = 0; j < 4; j++) {
					ary[i][j] = Integer.parseInt(st.nextToken());
					q.offer(ary[i][j] * 100 + (i * 4 + j));
				}
			}
			level = 1;
			while(!q.isEmpty()) {
				qsize = q.size();
				while(qsize-- > 0) {
					cur = q.poll();
					i = (cur % 100) / 4;
					j = (cur % 100) % 4;
					cur /= 100;
					if(level == 7) {
						set.add(cur);
						continue;
					}
					for(int d = 0; d < 4; d++) {
						ii = i + dir[d][0];
						jj = j + dir[d][1];
						if(ii >= 0 && ii < 4 && jj >= 0 && jj < 4)
							q.offer((cur * 10 + ary[ii][jj]) * 100 + (ii * 4 + jj));
					}
				}
				level++;
			}
			sb.append(String.format("#%d %d\n", tc, set.size()));
		}
		System.out.println(sb);
	}
}