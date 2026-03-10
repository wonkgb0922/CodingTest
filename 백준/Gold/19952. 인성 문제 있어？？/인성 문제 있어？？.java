import java.util.*;
import java.io.*;

public class Main {
	static boolean visited[][];
	static int map[][];
	static int dir[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		Queue<Integer> q = new ArrayDeque<>();
		int T = Integer.parseInt(br.readLine());
		boolean flag;
		int h, w, o, f, xs, ys, xe, ye, x, y, level;
		for(int t = 0; t < T; t++) {
			q.clear();
			st = new StringTokenizer(br.readLine());
			h = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			o = Integer.parseInt(st.nextToken());
			f = Integer.parseInt(st.nextToken());
			xs = Integer.parseInt(st.nextToken()) - 1;
			ys = Integer.parseInt(st.nextToken()) - 1;
			xe = Integer.parseInt(st.nextToken()) - 1;
			ye = Integer.parseInt(st.nextToken()) - 1;
			visited = new boolean[h][w];
			map = new int[h][w];
			flag = false;
			for(int i = 0; i < o; i++) {
				st = new StringTokenizer(br.readLine());
				x = Integer.parseInt(st.nextToken()) - 1;
				y = Integer.parseInt(st.nextToken()) - 1;
				map[x][y] = Integer.parseInt(st.nextToken());
			}
			visited[xs][ys] = true;
			q.offer(xs * w + ys);
			level = 0;
			while(!q.isEmpty()) {
				int qsize = q.size();
				while(qsize-- > 0) {
					int i = q.peek() / w;
					int j = q.poll() % w;
					if(i == xe && j == ye) {
						flag = true;
						break;
					}
					if(f == level) break;
					for(int d = 0; d < 4; d++) {
						int ii = i + dir[d][0];
						int jj = j + dir[d][1];
						if(ii >= 0 && ii < h && jj >= 0 && jj < w) {
							if(!visited[ii][jj]) {
								if(f - level >= map[ii][jj] - map[i][j]) {
									visited[ii][jj] = true;
									q.offer(ii * w + jj);
								}
							}
						}
					}
				}
				level++;
				if(flag) break;				
			}
			if(flag) sb.append("잘했어!!\n");
			else sb.append("인성 문제있어??\n");
		}
		System.out.println(sb);
	}
}
