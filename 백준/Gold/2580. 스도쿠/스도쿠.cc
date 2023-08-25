#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int ary[9][9] = { 0, };
bool horizen[9][10] = {0,};
bool vertical[9][10] = {0,};
bool area[9][10] = {0,};

bool dfs(int idx) {
	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", ary[i][j]);
			printf("\n");
		}
		return true;
	}
	int x = idx / 9, y = idx % 9;
	if (ary[x][y] != 0)
		return dfs(idx + 1);
	for (int i = 1; i <= 9; i++) {
		if (!horizen[x][i] && !vertical[y][i] && !area[(x / 3) * 3 + (y / 3)][i]) {
			horizen[x][i] = vertical[y][i] = area[(x / 3) * 3 + (y / 3)][i] = true;
			ary[x][y] = i;
			if (dfs(idx + 1)) return true;
			horizen[x][i] = vertical[y][i] = area[(x / 3) * 3 + (y / 3)][i] = false;
			ary[x][y] = 0;
		}
	}
	return false;
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &ary[i][j]);
			horizen[i][ary[i][j]] = true;
			vertical[j][ary[i][j]] = true;
			area[(i / 3) * 3 + (j / 3)][ary[i][j]] = true;
		}
	}
	dfs(0);
	return 0;
}