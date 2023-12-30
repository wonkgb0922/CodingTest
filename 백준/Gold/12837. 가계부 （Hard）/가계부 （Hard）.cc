#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, seg[4000000];

long long update(int l, int r, int loc, int idx, int val)
{
	if (idx < l || idx > r) return seg[loc];
	if (l == r) {
		if(l == idx) seg[loc] += val;
		return seg[loc];
	}
	int mid = (l + r) / 2;

	seg[loc] = update(l, mid, loc * 2 + 1, idx, val) + update(mid + 1, r, loc * 2 + 2, idx, val);
	return seg[loc];
}

long long sum(int L, int R, int l, int r, int idx)
{
	if (l > R || r < L) return 0;
	if (L <= l && R >= r) return seg[idx];
	int mid = (l + r) / 2;
	return sum(L, R, l, mid, idx * 2 + 1) + sum(L, R, mid + 1, r, idx * 2 + 2);
}


int main()
{
	int q, in1, in2, in3;
	scanf("%lld%d", &n, &q);

	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &in1, &in2, &in3);
		in2--;
		if (in1 == 1)
			update(0, n - 1, 0, in2, in3);
		else
			printf("%lld\n", sum(in2, in3 - 1, 0, n - 1, 0));
	}

	return 0;
}