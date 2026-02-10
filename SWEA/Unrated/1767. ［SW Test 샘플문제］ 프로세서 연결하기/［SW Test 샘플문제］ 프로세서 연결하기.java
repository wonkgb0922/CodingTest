import java.util.*;
import java.io.*;

public class Solution {
	static int n, max, total, min;
	static int map[][];
	static int dir[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	static ArrayList<int[]> list;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			map = new int[n][n];
			list = new ArrayList<>();
			max = 0;
			min = Integer.MAX_VALUE;
			total = 0;
			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if((i == 0 || j == 0 || i == n - 1 || j == n - 1) && map[i][j] == 1) continue;
					if(map[i][j] == 1) {
						list.add(new int[] {i, j});
					}
				}
			}
			total = list.size();
			
			setPower(0, 0, 0);
			System.out.println("#" + t + " " + min);			
		}
	}
	
	static void setPower(int idx, int coreCnt, int lineCnt) {
		if(total - idx + coreCnt < max) return;
		
		if(idx == total) {
			if(max < coreCnt) {
				max = coreCnt;
				min = lineCnt;
			}
			else if(max == coreCnt)
				min = Math.min(min, lineCnt);
			return;				
		}		
		int[] cur = list.get(idx);
		int r = cur[0];
		int c = cur[1];
		// 해당 코어를 4방향으로 전선 놓기 시도
		for(int d = 0; d < 4; d++) {
			// 해당 코어를 d 방향으로 놓는 것이 가능한지 체크
			if(!isAvailable(r, c, d)) continue;
			
			// 해당 코어를 d방향으로 전선 놓기
			int cnt = setStatus(r, c, d, 2);
			// 다음 코어로 넘어가기
			setPower(idx + 1, coreCnt + 1, lineCnt + cnt);
			// 해당 코어를 d방향으로 전선 지우기
			setStatus(r, c, d, 0);
		}
		// 해당 코어를 전선놓기 하지 않기
		setPower(idx + 1, coreCnt, lineCnt);
	}
	
	static boolean isAvailable(int r, int c, int d) {
		int nr = r, nc = c;
		while(true) {
			nr += dir[d][0];
			nc += dir[d][1];
			if(nr < 0 || nr >= n || nc < 0 || nc >= n) break;
			if(map[nr][nc] > 0) return false;
		}
		return true;
	}
	
	static int setStatus(int r, int c, int d, int s) {
		int nr = r, nc = c, cnt = 0;
		while(true) {
			nr += dir[d][0];
			nc += dir[d][1];
			if(nr < 0 || nr >= n || nc < 0 || nc >= n) break;
			map[nr][nc] = s;
			cnt++;
		}
		return cnt;
	}
}