#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char ary[1000][1000] = { 0, };
queue<pair<short, short>> loc, fire;

int main()
{
	int w, h, level;
	short f, s, t;
	bool solve;
	cin >> t;
	while(t--) {
		level = 0;
		solve = false;
		//loc = queue<pair<int, int>>();
		//fire = queue<pair<int, int>>();
		while (!loc.empty()) loc.pop();
		while (!fire.empty()) fire.pop();
		scanf("%d%d\n", &w, &h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%c", &ary[i][j]);
				if (ary[i][j] == '@') loc.push({ i,j });
				if (ary[i][j] == '*') fire.push({ i,j });
			}				
			getchar();
		}
		while (!loc.empty()) {
			level++;
			int qsize = fire.size();
			for (int i = 0; i < qsize; i++) {
				f = fire.front().first;
				s = fire.front().second;
				fire.pop();
				if (f < h - 1 && ary[f + 1][s] != '#' && ary[f + 1][s] != '*') {
					ary[f + 1][s] = '*';
					fire.push({ f + 1, s });
				}
				if (f > 0 && ary[f - 1][s] != '#' && ary[f - 1][s] != '*') {
					ary[f - 1][s] = '*';
					fire.push({ f - 1, s });
				}
				if (s < w - 1 && ary[f][s + 1] != '#' && ary[f][s + 1] != '*') {
					ary[f][s + 1] = '*';
					fire.push({ f, s + 1 });
				}
				if (s > 0 && ary[f][s - 1] != '#' && ary[f][s - 1] != '*') {
					ary[f][s - 1] = '*';
					fire.push({ f, s - 1 });
				}
			}
			qsize = loc.size();
			for (int i = 0; i < qsize; i++) {
				f = loc.front().first;
				s = loc.front().second;
				loc.pop();
				if (f == h - 1 || f == 0 || s == w - 1 || s == 0) {
					solve = true;
					break;
				}
				else {
					if (f < h - 1 && ary[f + 1][s] == '.') {
						ary[f + 1][s] = '@';
						loc.push({ f + 1, s });
					}
					if (f > 0 && ary[f - 1][s] == '.') {
						ary[f - 1][s] = '@';
						loc.push({ f - 1, s });
					}
					if (s < w - 1 && ary[f][s + 1] == '.') {
						ary[f][s + 1] = '@';
						loc.push({ f, s + 1 });
					}
					if (s > 0 && ary[f][s - 1] == '.') {
						ary[f][s - 1] = '@';
						loc.push({ f, s - 1 });
					}
				}
			}
			if (solve) break;
		}
		if (solve) printf("%d\n", level);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
