#include <iostream>
#include <stdlib.h>
#define MAX 100000

using namespace std;

int seg[MAX * 4 + 1];
int n;

int set(int idx, int tl, int tr, int t, int val) {
	if (tl == tr) {
		if (tl == t)
			seg[idx] = val;
		return seg[idx];
	}
	int mid = (tl + tr) >> 1;
	if(t <= mid)
		seg[idx] = set(idx << 1, tl, mid, t, val) + seg[idx<<1 | 1];
	else
		seg[idx] = seg[idx << 1] + set(idx << 1 | 1, mid + 1, tr, t, val);
	return seg[idx];
}

int getKth(int idx, int tl, int tr, int k) {
	if (tl == tr)
		return tl;
	int mid = (tl + tr) >> 1;
	if (seg[idx << 1] < k)
		return getKth(idx << 1 | 1, mid + 1, tr, k - seg[idx << 1]);
	return getKth(idx << 1, tl, mid, k);
}

int res[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int in, pos;
	for (int i = 0; i < n; i++)
		set(1, 0, n - 1, i, 1);

	for (int i = 1; i <= n; i++) {
		cin >> in;
		in++;
		pos = getKth(1, 0, n - 1, in);
		res[pos] = i;
		set(1, 0, n - 1, pos, 0);
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << "\n";
	return 0;
}