#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long S[100001] = { 0 };

int main(void) {
	int n, t, in, s, e;

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		S[i + 1] = S[i] + in;
	}
	while (t--) {
		scanf("%d%d", &s, &e);
		printf("%d\n", S[e] - S[s - 1]);
	}

	return 0;
}