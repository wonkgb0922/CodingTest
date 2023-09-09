#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int S[200000][26] = { 0, };

int main(void) {
	char in;
	int q, s, e;
	for (int i = 1;; i++) {
		scanf("%c", &in);
		if (in == '\n') break;
		for (int j = 0; j < 26; j++)
			S[i][j] = S[i - 1][j];
		S[i][in - 'a']++;
	}
	scanf("%d", &q);
	while (q--) {
		cin >> in;
		scanf("%d%d", &s, &e);
		printf("%d\n", S[e + 1][in - 'a'] - S[s][in - 'a']);
	}
	return 0;
}