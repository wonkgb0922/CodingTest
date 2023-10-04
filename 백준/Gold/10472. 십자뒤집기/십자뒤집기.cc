#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int dir[5][2] = { {0,1},{0,-1},{0,0},{1,0},{-1,0} };

int main() {
	int t, qsize, level;
	string str[3],val, cop;
	queue<string> q;
	set<string> s;
	cin >> t;
	while(t--) {
		bool sol = false;
		level = -1;
		for (int i = 0; i < 3; i++)
			cin >> str[i];
		s.clear();
		q = queue<string>();
		q.push(str[0] + str[1] + str[2]);
		s.insert(str[0] + str[1] + str[2]);
		while (!q.empty()) {
			level++;
			qsize = q.size();
			while (qsize--) {
				val = q.front();
				q.pop();
				if (val == ".........") {
					sol = true;
					break;
				}
				for (int i = 0; i < 9; i++) {
					int x = i % 3, y = i / 3;
					cop = val;
					for (int j = 0; j < 5; j++) {
						int nx = x + dir[j][0];
						int ny = y + dir[j][1];
						if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
							if (cop[ny * 3 + nx] == '.') cop[ny * 3 + nx] = '*';
							else cop[ny * 3 + nx] = '.';
						}
					}
					if (!s.count(cop)) {
						s.insert(cop);
						q.push(cop);
					}
				}
			}
			if (sol) break;
		}
		printf("%d\n", level);
	}
	return 0;
}