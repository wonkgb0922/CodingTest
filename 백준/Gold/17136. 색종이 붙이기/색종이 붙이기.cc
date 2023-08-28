#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int ary[10][10] = { 0, };
bool visited[10][10] = { false, }, res = false;
int pcnt[5] = { 0, };
int cnt = 26;

bool valid(int idx, int size) {
	int y = idx / 10, x = idx % 10;
	if (x + size > 10 || y + size > 10) return false;
	if (pcnt[size - 1] >= 5) return false;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++)
			if (ary[i][j] == 0 || visited[i][j]) return false;
	}
	return true;
}
void usePaper(int idx, int size) {
	int y = idx / 10, x = idx % 10;
	pcnt[size - 1]++;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++)
			visited[i][j] = true;
	}
}

void unusedPaper(int idx, int size) {
	int y = idx / 10, x = idx % 10;
	pcnt[size - 1]--;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++)
			visited[i][j] = false;
	}
}

void dfs(int idx, int fcnt) {
	int y = idx / 10, x = idx % 10;
	if (fcnt >= cnt) return;
	if (idx == 99) {
		if (!visited[y][x] && ary[y][x] == 1) {
			if (valid(idx, 1)) {
				fcnt++;
			}
			else return;
		}
		if (cnt > fcnt) cnt = fcnt;
		res = true;
		return;
	}
	if (visited[y][x] || ary[y][x] == 0) dfs(idx + 1, fcnt);
	if (ary[y][x] == 1 ) {
		for (int size = 1; size <= 5; size++) {
			if (valid(idx, size)) {
				usePaper(idx, size);
				dfs(idx + 1, fcnt + 1);
				unusedPaper(idx, size);
			}
		}
	}
}


int main()

{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &ary[i][j]);

	dfs(0, 0);
	if (res) printf("%d", cnt);
	else printf("-1");

	return 0;
}