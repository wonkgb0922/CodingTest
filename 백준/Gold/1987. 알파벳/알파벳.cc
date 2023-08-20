#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, MAX = 0;
char ary[20][20] = {};
bool visited[20][20] = { false, }, alphabet[27] = { false, };
int dir[4][2] = { {1,0}, {0,1},{-1,0},{0,-1} };

void dfs(int i, int j, int cnt) {
	MAX = max(MAX, cnt);
	int ni, nj;
	alphabet[ary[i][j] - 'A'] = true;
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		ni = i + dir[k][0];
		nj = j + dir[k][1];
		if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
			if (!visited[ni][nj] && !alphabet[ary[ni][nj] - 'A']) {
				dfs(ni, nj, cnt + 1);
			}
		}
	}
	visited[i][j] = false;
	alphabet[ary[i][j] - 'A'] = false;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		scanf("%s", &ary[i]);
	}
	dfs(0, 0, 1);
	visited[0][0] = true;
	cout << MAX;
	return 0;
}