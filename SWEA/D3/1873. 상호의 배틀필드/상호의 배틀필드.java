import java.util.*;
import java.io.*;

class Solution
{
	static int n, m;
	static int posX, posY;
	static Face f;
    static char[][] map;
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        String command, in;
        char c;
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	map = new char[n][m];
        	posX = -1;
        	posY = -1;
        	for(int i = 0; i < n; i++) {
        		in = br.readLine();
        		map[i] = in.toCharArray();
        		if(posX >= 0) continue;
        		for(int j = 0; j < m; j++) {
        			c = map[i][j];
        			if(c == '^' || c == 'v' || c == '>' || c == '<') {
        				posX = j;
        				posY = i;
        				if(c == '^') f = Face.U;
        				else if(c == 'v') f = Face.D;
        				else if(c == '>') f = Face.R;
        				else f = Face.L;
        			}
        		}
        	}
        	br.readLine();
        	command = br.readLine();
        	for(int i = 0; i < command.length(); i++) {
        		c = command.charAt(i);
        		if(c == 'U') {
        			f = Face.U;
        			move(-1, 0);
        		}
        		else if(c == 'D') {
        			f = Face.D;
        			move(1, 0);
        		}
        		else if(c == 'R') {
        			f = Face.R;
        			move(0, 1);
        		}
        		else if(c == 'L') {
        			f = Face.L;
        			move(0, -1);
        		}
        		else
        			shoot();
        	}
        	if(f == Face.U) {
        		map[posY][posX] = '^';
        	}
        	else if(f == Face.D)
        		map[posY][posX] = 'v';
        	else if(f == Face.R)
        		map[posY][posX] = '>';
        	else
        		map[posY][posX] = '<';
        	sb.append("#").append(t).append(" ");
        	for(int i = 0; i < n; i++) {
        		for(int j = 0; j < m; j++) {
        			sb.append(map[i][j]);
        		}
        		sb.append("\n");
        	}
        }
        System.out.println(sb);
    }
	static void move(int dy, int dx) {
		map[posY][posX] = '.';
		int nx = posX + dx;
		int ny = posY + dy;
		if(nx < 0 || nx >= m) return;
		if(ny < 0 || ny >= n) return;
		if(map[ny][nx] == '.') {
			posY = ny;
			posX = nx;
		}
		
	}
	static void shoot() {
		int dx = 0, dy = 0;
		if(f == Face.U)
			dy = -1;
		else if(f == Face.D)
			dy = 1;
		else if(f == Face.R)
			dx = 1;
		else
			dx = -1;
		
		if(dy != 0) {
			for(int i = posY; i < n && i >= 0; i += dy) {
				if(map[i][posX] == '*') {
					map[i][posX] = '.';
					break;
				}
				else if(map[i][posX] == '#')
					break;
			}
		}
		else if(dx != 0) {
			for(int j = posX; j < m && j >= 0; j += dx) {
				if(map[posY][j] == '*') {
					map[posY][j] = '.';
					break;
				}
				else if(map[posY][j] == '#')
					break;
			}
		}
	}
}

enum Face {
	U, D, R, L;
}
