import java.util.*;
import java.io.*;

public class Solution {
	static int dir[][] = {{0, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	static int pos[][];
	static List<BC> bc = new ArrayList<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int res, m, a, pax, pay, pbx, pby, abc, bbc, max, sum;
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			res = 0;
			st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken());
			pos = new int[2][m + 1];
			for(int i = 0; i < 2; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 1; j <= m; j++)
					pos[i][j] = Integer.parseInt(st.nextToken());
			}
			bc.clear();
			for(int i = 0; i < a; i++) {
				st = new StringTokenizer(br.readLine());
				bc.add(new BC(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
			}
			pax = 1;
			pay = 1;
			pbx = 10;
			pby = 10;
			for(int w = 0; w <= m; w++) {
				pax += dir[pos[0][w]][0];
				pay += dir[pos[0][w]][1];
				pbx += dir[pos[1][w]][0];
				pby += dir[pos[1][w]][1];
				abc = 0;
				bbc = 0;
				int idx = 0;
				for(BC btc : bc) {
					if(Math.abs(btc.x - pax) + Math.abs(btc.y - pay) <= btc.c)
						abc |= 1 << idx;
					if(Math.abs(btc.x - pbx) + Math.abs(btc.y - pby) <= btc.c)
						bbc |= 1 << idx;
					idx++;
				}
				max = 0;
				for(int i = 0; i < a; i++) {
					if((abc & (1 << i)) == 0) sum = 0;
					else sum = bc.get(i).p;
					for(int j = 0; j < a; j++) {
						if( (bbc & (1 << j)) == 0) {
							max = Math.max(max, sum);
						}
						else {
							if(i == j) max = Math.max(max, bc.get(j).p);
							else max = Math.max(max, sum + bc.get(j).p);
						}
					}
				}
				res += max;
			}
			sb.append(String.format("#%d %d\n", t, res));
		}
		
		System.out.println(sb);
	}
}
class BC {
	int x;
	int y;
	int c;
	int p;
	BC(int x, int y, int c, int p) {
		this.x = x;
		this.y = y;
		this.c = c;
		this.p = p;
	}
}