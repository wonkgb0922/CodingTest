#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[100001] = { 0 };
long long S[100001] = { 0 };


int main(void) {
	int n, t, k, l, sum;

	cin >> n >> t;
	scanf("%d", &ary[0]);
	S[0] = ary[0];
	for (int i = 1; i < n; i++) {
		scanf("%d", &ary[i]);
		S[i] = S[i - 1] + ary[i];
	}
	while (t--) {
		scanf("%d %d", &k, &l); // k부터 l까지 사이의 합
		if (k == 1) sum = S[l - 1];
		else sum = S[l - 1] - S[k - 2];
		printf("%d\n", sum);
	}

	return 0;
}