#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long seg[3000001];
long long n, m, k, idx;

void construct() {
	for (int i = idx - 1; i >= 0; i--)
		seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
	
}

void update(long long loc, long long val) {
	loc += idx;
	seg[loc] = val;
	for (int i = (loc - 1) / 2; i > 0; i = (i - 1) / 2) {
		seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
	}
	seg[0] = seg[1] + seg[2];
}

long long sol(long long loc, long long l, long long r, long long nodeL, long long nodeR) {
	if (r < nodeL || nodeR < l) return 0;
	if (l <= nodeL && nodeR <= r) return seg[loc];
	int mid = (nodeL + nodeR) / 2;
	return sol(loc * 2 + 1, l, r, nodeL, mid) + sol(loc * 2 + 2, l, r, mid + 1, nodeR);
}

int main()
{
	long long in1, in2, in3;
	cin >> n >> m >> k;
	idx = ceil(log2(n));
	idx = pow(2, idx) - 1;
	for (int i = idx; i < idx + n; i++) {
		scanf("%lld", seg + i);
	}
	construct();
	for (int i = 0; i < m + k; i++) {
		scanf("%lld%lld%lld", &in1, &in2, &in3);
		in2--;
		if (in1 == 1) {
			update(in2, in3);
		}
		else {	
			printf("%lld\n", sol(0, in2, in3 - 1, 0, idx));
		}
	}
	return 0;
}