#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

long long int S[1001] = { 0, };

int main(void) {
	int t, n, in;

	cin >> t;
	while (t--) {
		long long int res = -999;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &in);
			S[i] = S[i - 1] + in;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++)
				if(res < S[j] - S[i]) res = S[j] - S[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}