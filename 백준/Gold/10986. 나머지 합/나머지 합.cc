#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int S[1000001] = { 0, };
int mcnt[1000] = { 0, };

int main(void) {
	int n, m;
	long long int in, cnt = 0;

	scanf("%d%d", &n, &m);
	mcnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &in);
		S[i] = (S[i - 1] + in) % m;
		cnt += mcnt[S[i]]++;
	}
	cout << cnt;
	return 0;
}