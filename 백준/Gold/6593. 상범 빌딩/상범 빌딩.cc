#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

bool visited[30][30][30] = { false, };

char ary[30][30][30];

int main()
{
	int l, r, c;
	short res;
	bool sol, s;
	queue<pair<short,pair<short,short>>> q;

	while (true) {
		scanf("%d%d%d", &l, &r, &c);
		if (l == (r == (c == 0))) break;

		memset(&visited[0][0][0], false, l * r * c);
		q = queue<pair<short, pair<short, short>>>();
		res = 0;
		sol = false;
		s = false;

		for (short i = 0; i < l; i++) {
			for (short j = 0; j < r; j++) {
				scanf("%s", ary[i][j]);
				if (!s) {
					for (short k = 0; k < c; k++) {
						if (ary[i][j][k] == 'S') {
							q.push({ i,{j,k} });
							visited[i][j][k] = true;
							s = true;
						}
					}
				}
				
			}
		}

		while (!q.empty() && !sol) {
			short qsize = q.size();
			while (qsize--) {
				auto& loc = q.front();
				q.pop();
				short i = loc.first;
				short j = loc.second.first;
				short k = loc.second.second;
				// i if문
				if (i > 0) {
					if (!visited[i - 1][j][k]) {
						if (ary[i - 1][j][k] == 'E') {
							sol = true;
							break;
						}
						else if (ary[i - 1][j][k] == '.') {
							visited[i - 1][j][k] = true;
							q.push({ i - 1,{j,k} });
						}
					}
				}
				if (i < l - 1) {
					if (!visited[i + 1][j][k]) {
						if (ary[i + 1][j][k] == 'E') {
							sol = true;
							break;
						}
						else if (ary[i + 1][j][k] == '.') {
							visited[i + 1][j][k] = true;
							q.push({ i + 1,{j,k} });
						}
					}
				}
				// j if문
				if (j > 0) {
					if (!visited[i][j - 1][k]) {
						if (ary[i][j - 1][k] == 'E') {
							sol = true;
							break;
						}
						else if (ary[i][j - 1][k] == '.') {
							visited[i][j - 1][k] = true;
							q.push({ i,{j - 1,k} });
						}
					}
				}
				if (j < r - 1) {
					if (!visited[i][j + 1][k]) {
						if (ary[i][j + 1][k] == 'E') {
							sol = true;
							break;
						}
						else if (ary[i][j + 1][k] == '.') {
							visited[i][j + 1][k] = true;
							q.push({ i,{j + 1,k} });
						}
					}
				}
				// k if문
				if (k > 0) {
					if (!visited[i][j][k - 1]) {
						if (ary[i][j][k - 1] == 'E') {
							sol = true;
							break;
						}
						else if (ary[i][j][k - 1] == '.') {
							visited[i][j][k - 1] = true;
							q.push({ i,{j,k - 1} });
						}
					}
				}
				if (k < c - 1) {
					if (!visited[i][j][k + 1]) {
						if (ary[i][j][k + 1] == 'E') {
							sol = true;
							break;
						}
						else if (ary[i][j][k + 1] == '.') {
							visited[i][j][k + 1] = true;
							q.push({ i,{j,k + 1} });
						}
					}
				}
			}
			res++;
		}
		if (sol) printf("Escaped in %d minute(s).\n", res);
		else printf("Trapped!\n");
	}
	return 0;
}