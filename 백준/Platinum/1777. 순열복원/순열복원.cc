#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int t[MAX * 4];

int n, ary[MAX], res[MAX];

int update(int p, int tl, int tr, int idx, int val) {
	if (tl + 1 == tr) {
		if (tl == idx)
			t[p] = val;
		return t[p];
	}
	int mid = (tl + tr) >> 1;
	if (idx < mid)
		return t[p] = update(p << 1, tl, mid, idx, val) + t[p << 1 | 1];
	return t[p] = t[p << 1] + update(p << 1 | 1, mid, tr, idx, val);
}

int getKth(int p, int tl, int tr, int k) {
	if (tl + 1 == tr) return tl;

	int mid = (tl + tr) >> 1;
	if (t[p << 1] < k)
		return getKth(p << 1 | 1, mid, tr, k - t[p << 1]);
	return getKth(p << 1, tl, mid, k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
		update(1, 0, n, i, 1);
	}
	int k, pos;
	for(int i = n - 1; i >= 0; i--) {
		k = i - ary[i] + 1;
		pos = getKth(1, 0, n, k);
		res[pos] = i + 1;
		update(1, 0, n, pos, 0);
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	return 0;
}