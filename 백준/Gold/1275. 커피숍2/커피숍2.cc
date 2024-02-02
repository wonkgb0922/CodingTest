#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long seg[400000];
int n, ary[100000];

long long construct(int l, int r, int idx)
{
	if (l == r) seg[idx] = ary[l];
	else {
		int mid = (l + r) / 2 ;
		seg[idx] = construct(l, mid, idx * 2 + 1) + construct(mid + 1, r, idx * 2 + 2);
	}
	return seg[idx];
}

long long update(int l, int r, int loc, int idx, int val)
{
	if (idx < l || idx > r) return seg[loc];
	if (l == r) {
		if (l == idx) seg[loc] = val;
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
	int q, in1, in2, in3, in4;
	scanf("%d%d", &n, &q);

	for (int i = 0; i < n; i++)
		scanf("%d", ary + i);

	construct(0, n - 1, 0);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &in1, &in2, &in3, &in4);
		in1--, in2--, in3--;
		if (in1 > in2) swap(in1, in2);
		printf("%lld\n", sum(in1, in2, 0, n - 1, 0));
		update(0, n - 1, 0, in3, in4);
	}

	return 0;
}