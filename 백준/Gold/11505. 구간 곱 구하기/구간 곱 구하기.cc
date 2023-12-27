#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long n, a[1000000], seg[4000000];

long construct(int start, int end, int idx)
{
	if (start == end) {
		seg[idx] = a[start];
		return seg[idx];
	}
	int mid = (start + end) / 2;
	seg[idx] = (construct(start, mid, idx * 2 + 1) * construct(mid + 1, end, idx * 2 + 2)) % 1000000007;

	return seg[idx];
}

long update(int l, int r, int idx, int loc, int val)
{
	if (loc < l || loc > r) return seg[idx];
	if (l == r) {
		if(l == loc) seg[idx] = val;
		return seg[idx];
	}
	int mid = (l + r) / 2;
	seg[idx] = (update(l, mid, idx * 2 + 1, loc, val) * update(mid + 1, r, idx * 2 + 2, loc, val)) % 1000000007;
	return seg[idx];
}

long mul(int l, int r, int il, int ir, int idx)
{
	if (l > ir || r < il) return 1;
	if (il <= l && ir >= r) return seg[idx];
	int mid = (l + r) / 2;
	return (mul(l, mid, il, ir, idx * 2 + 1) * mul(mid + 1, r, il, ir, idx * 2 + 2)) % 1000000007;
}

int main()
{
	int m, k, in1, in2, in3;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	construct(0, n - 1, 0);

	for (int i = 0; i < m + k; i++) {
		scanf("%d%d%d", &in1, &in2, &in3);
		in2--;
		if (in1 == 1) {
			update(0, n - 1, 0, in2, in3);
		}
		else {
			printf("%ld\n", mul(0, n - 1, in2, in3 - 1, 0));
		}
	}

	return 0;
}