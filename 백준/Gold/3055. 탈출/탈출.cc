#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char ary[1000][1000] = { 0, };
queue<pair<short, short>> loc, water;

int main()
{
	int w, h, level = 0;
	short f, s;
	bool solve;
	solve = false;
	scanf("%d%d\n", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%c", &ary[i][j]);
			if (ary[i][j] == 'S') loc.push({ i,j });
			else if (ary[i][j] == '*') water.push({ i,j });
		}
		getchar();
	}
	while (!loc.empty()) {
		level++;
		int qsize = water.size();
		
		for (int i = 0; i < qsize; i++) {
			f = water.front().first;
			s = water.front().second;
			water.pop();
			if (f < h - 1 && ary[f + 1][s] != 'X' && ary[f + 1][s] != '*' && ary[f + 1][s] != 'D') {
				ary[f + 1][s] = '*';
				water.push({ f + 1, s });
			}
			if (f > 0 && ary[f - 1][s] != 'X' && ary[f - 1][s] != '*' && ary[f - 1][s] != 'D') {
				ary[f - 1][s] = '*';
				water.push({ f - 1, s });
			}
			if (s < w - 1 && ary[f][s + 1] != 'X' && ary[f][s + 1] != '*' && ary[f][s + 1] != 'D') {
				ary[f][s + 1] = '*';
				water.push({ f, s + 1 });
			}
			if (s > 0 && ary[f][s - 1] != 'X' && ary[f][s - 1] != '*' && ary[f][s - 1] != 'D') {
				ary[f][s - 1] = '*';
				water.push({ f, s - 1 });
			}
		}
		qsize = loc.size();
		for (int i = 0; i < qsize; i++) {
			f = loc.front().first;
			s = loc.front().second;
			loc.pop();
			if (f < h - 1 && (ary[f + 1][s] == '.' || ary[f + 1][s] == 'D')) {
				if (ary[f + 1][s] == 'D') {
					solve = true;
					break;
				}
				ary[f + 1][s] = 'S';
				loc.push({ f + 1, s });
			}
			if (f > 0 && (ary[f - 1][s] == '.' || ary[f - 1][s] == 'D')) {
				if (ary[f - 1][s] == 'D') {
					solve = true;
					break;
				}
				ary[f - 1][s] = 'S';
				loc.push({ f - 1, s });
			}
			if (s < w - 1 && (ary[f][s + 1] == '.' || ary[f][s + 1] == 'D')) {
				if (ary[f][s + 1] == 'D') {
					solve = true;
					break;
				}
				ary[f][s + 1] = 'S';
				loc.push({ f, s + 1 });
			}
			if (s > 0 && (ary[f][s - 1] == '.' || ary[f][s - 1] == 'D')) {
				if (ary[f][s - 1] == 'D') {
					solve = true;
					break;
				}
				ary[f][s - 1] = 'S';
				loc.push({ f, s - 1 });
			}
		}
		if (solve) break;
	}
	if (solve) printf("%d", level);
	else printf("KAKTUS");
	return 0;
}