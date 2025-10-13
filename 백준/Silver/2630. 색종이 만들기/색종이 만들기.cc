#include <stdio.h>	
#include <iostream>

using namespace std;

int n, cnt[2]; // White:0, Blue:1
int dir[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
int ary[128][128];

int typeOfPaper(int bi, int bj, int len) {
	int cur = ary[bi][bj];
	for (int i = bi; i < bi + len; i++) {
		for (int j = bj; j < bj + len; j++) {
			if (ary[i][j] != cur) return 2;
		}
	}
	return cur;
}

void sol(int i, int j, int len) {
	int l = len / 2;
	int t[4];
	for (int k = 0; k < 4; k++) {
		int curi = i + dir[k][0] * l;
		int curj = j + dir[k][1] * l;
		t[k] = typeOfPaper(curi, curj, l);
		if (t[k] == 2) sol(curi, curj, l);
	}
	if (t[0] == t[1] && t[0] == t[2] && t[0] == t[3]) {
		if (t[0] != 2) {
			cnt[t[0]]++;
			return;
		}
	}
	for (int k = 0; k < 4; k++)
		cnt[t[k]]++;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
	}
	sol(0, 0, n);
	printf("%d\n%d", cnt[0], cnt[1]);
	return 0;
}