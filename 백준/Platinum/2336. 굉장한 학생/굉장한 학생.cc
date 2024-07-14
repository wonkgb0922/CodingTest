#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;

int ary[3][500001], seg[2000000];

int construct(int l, int r, int idx)
{
	if (l == r) seg[idx] = MAX;
	else {
		int mid = (l + r) / 2;
		seg[idx] = min(construct(l, mid, idx * 2 + 1), construct(mid + 1, r, idx * 2 + 2));
	}
	return seg[idx];
}

int update(int l, int r, int idx, int loc, int val)
{
	if (l > loc || r < loc) return seg[idx];
	if (l == r) {
		if (l == loc) seg[idx] = val;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = min(update(l, mid, idx * 2 + 1, loc, val), update(mid + 1, r, idx * 2 + 2, loc, val));
	}
	return seg[idx];
}

int Min(int l, int r, int idx, int L, int R)
{
	if (L > R) return MAX;
	if (r < L || l > R) return MAX;
	if (L <= l && r <= R) return seg[idx];
	int mid = (l + r) / 2;
	return min(Min(l, mid, idx * 2 + 1, L, R), Min(mid + 1, r, idx * 2 + 2, L, R));
}

int main()
{
	// 0등, 1번부터 카운팅
	// 인덱스는 0번부터
	int n, in, cnt = 0;
	cin >> n;
	construct(0, n - 1, 0);

	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[0][i]);
		ary[0][i]--;
	}

	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &in);
			ary[i][in - 1] = j;
		}
	}
	for (int i = 0; i < n ; i++) {
		in = ary[0][i];
		update(0, n - 1, 0, ary[1][in], ary[2][in]);
		int mm = Min(0, n - 1, 0, 0, ary[1][in] - 1);
		if (ary[2][in] < mm)
			cnt++;
	}
	printf("%d", cnt);
	
	return 0;
}