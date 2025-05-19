#include <stdio.h>
#include <iostream>

using namespace std;

int mcnt[1000];

int main() {
	int n, m, t = 0;
	long long in, cnt = 0;

	scanf("%d%d", &n, &m);
	mcnt[0] = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &in);
		t = (t + in) % m;
		cnt += mcnt[t]++;
	}
	cout << cnt;
	return 0;
}