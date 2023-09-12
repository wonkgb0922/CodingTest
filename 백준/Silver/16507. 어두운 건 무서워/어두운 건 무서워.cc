#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int S[1001][1001] = { 0, };

int main(void) {
	int r, c, q, in;
	int r1, c1, r2, c2, res;
	scanf("%d%d%d", &r, &c, &q);
	for (int i = 0; i < r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &in);
			S[i][j] = S[i][j - 1] + in;
		}
	}
	while (q--) {
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		res = 0;
		r1--;
		r2--;
		for (int i = r1; i <= r2; i++)
			res += (S[i][c2] - S[i][c1 - 1]);
		printf("%d\n", res / ((r2 - r1 + 1) * (c2 - c1 + 1)));
	}
	return 0;
}