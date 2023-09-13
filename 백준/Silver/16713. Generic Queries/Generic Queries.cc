#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

long long S[1000001] = { 0, };

int main(void) {
	int n, q, in, in2;
	long long res = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &in);
		S[i] = S[i - 1] ^ in;
	}
	while (q--) {
		scanf("%d%d", &in, &in2);
		res ^= S[in2] ^ S[in - 1];
	}
	printf("%lld", res);
	return 0;
}