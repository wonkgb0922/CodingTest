#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long int S[200000][27] = {0, };

int main(void) {
	char in;
	int q, s, e;
	for (int i = 1;; i++) {
		scanf("%c", &in);
		if (in == '\n') break;
		for (int j = 0; j < 27; j++) {
			S[i][j] = S[i - 1][j];
			if (in - 'a' == j) S[i][j]++;
		}
	}
	scanf("%d", &q);
	while (q--) {
		cin >> in;
		scanf("%d%d", &s, &e);
		printf("%lld\n", S[e + 1][in - 'a'] - S[s][in - 'a']);
	}
	return 0;
}