#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

char ary[6][6];
int n;

bool valid() {
	int r1, r2;
	for (int i = 0; i < n; i++) {
		r1 = r2 = 0;
		for (int j = 0; j < n; j++) {
			if (ary[i][j] == 'S') {
				if (r1 == 0) r1 = 1;
				else if (r1 == 2) return false;
			}
			else if (ary[i][j] == 'T') {
				if (r1 == 0) r1 = 2;
				else if (r1 == 1) return false;
			}
			else if (ary[i][j] == 'O') r1 = 0;

			if (ary[j][i] == 'S') {
				if (r2 == 0) r2 = 1;
				else if (r2 == 2) return false;
			}
			else if (ary[j][i] == 'T') {
				if (r2 == 0) r2 = 2;
				else if (r2 == 1) return false;
			}
			else if (ary[j][i] == 'O') r2 = 0;
		}
	}
	return true;
}

bool dfs(int pos, int cnt) {
	int x = pos % n;
	int y = pos / n;
	if (pos == n * n) return false;
	ary[y][x] = 'O';
	if (cnt >= 2) {
		if (valid()) return true;
		ary[y][x] = 'X';
		return false;
	}
	for (int i = 1; i + pos < n * n; i++) {
		if (ary[(pos + i) / n][(pos + i) % n] == 'X') {
			if (dfs(pos + i, cnt + 1)) return true;
		}
	}
	ary[y][x] = 'X';
	return false;
}

int main(void) {
	bool res = false;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf(" %c", &ary[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ary[i][j] == 'X') {
				if (dfs(i * n + j, 0)) {
					res = true;
					break;
				}
			}
		}
		if (res) break;
	}
	if (res) printf("YES");
	else printf("NO");
	
}