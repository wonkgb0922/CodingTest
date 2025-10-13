#include <stdio.h>
#include <iostream>

using namespace std;

int res, n, r, c;
int dir[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };

void sol(int i, int j, int len) {
	int l = len / 2;
	for (int k = 0; k < 4; k++) {
		int curi = i + dir[k][0] * l;
		int curj = j + dir[k][1] * l;
		if (curi <= r && r < curi + l
			&& curj <= c && c < curj + l) {
			sol(curi, curj, l);
			break;
		}
		res += l * l;
	}
}

int main() {
	cin >> n >> r >> c;
	sol(0, 0, 1 << n);
	printf("%d", res);
	return 0;
}