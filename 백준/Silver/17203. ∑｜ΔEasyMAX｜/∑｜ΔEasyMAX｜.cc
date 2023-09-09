#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int S[1001] = { 0 };
int ary[1001];

int main(void) {
	int n, q, in, s, e, prev = 0;

	cin >> n >> q;
	S[0] = 0;
	cin >> in;
	prev = in;
	for (int i = 1; i < n; i++) {
		scanf("%d", &in);
		S[i] = S[i - 1] + max(in - prev, prev - in);
		prev = in;
	}
	while (q--) {
		scanf("%d%d", &s, &e);
		printf("%d\n", S[e - 1] - S[s - 1]);
	}

	return 0;
}