#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 199999

using namespace std;

long long seg[800000], seg2[800000];

long long update(int l, int r, int idx, int loc)
{
	if (loc < l || loc > r) return seg[idx];
	if (l == r) {
		if (l == loc) seg[idx] += loc;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = update(l, mid, idx * 2 + 1, loc) + update(mid + 1, r, idx * 2 + 2, loc);
	}
	return seg[idx];
}

long long update2(int l, int r, int idx, int loc)
{
	if (loc < l || loc > r) return seg2[idx];
	if (l == r) {
		if (l == loc) seg2[idx]++;
	}
	else {
		int mid = (l + r) / 2;
		seg2[idx] = update2(l, mid, idx * 2 + 1, loc) + update2(mid + 1, r, idx * 2 + 2, loc);
	}
	return seg2[idx];
}

long long sum(int start, int end, int l, int r, int idx)
{
	if (r < start || l > end) return 0;
	if (start <= l && r <= end) return seg[idx];
	int mid = (l + r) / 2;
	return sum(start, end, l, mid, idx * 2 + 1) + sum(start, end, mid + 1, r, idx * 2 + 2);
}

long long cnt(int start, int end, int l, int r, int idx)
{
	if (r < start || l > end) return 0;
	if (start <= l && r <= end) return seg2[idx];
	int mid = (l + r) / 2;
	return cnt(start, end, l, mid, idx * 2 + 1) + cnt(start, end, mid + 1, r, idx * 2 + 2);
}

int main()
{
	int n, in;
	long long res = 1, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		update(0, MAX, 0, in);
		update2(0, MAX, 0, in);
		temp = (cnt(0, in - 1, 0, MAX, 0) * in) - sum(0, in - 1, 0, MAX, 0)
			+ sum(in + 1, MAX, 0, MAX, 0) - (cnt(in + 1, MAX, 0, MAX, 0) * in);
		if (i > 0) {
			res *= temp % 1000000007;
			res %= 1000000007;
		}
	}
	cout << res;

	return 0;
}