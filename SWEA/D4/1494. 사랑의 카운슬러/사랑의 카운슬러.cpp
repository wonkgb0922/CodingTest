#include <iostream>
#include <stdlib.h>

using namespace std;

int ary[20][2];
int n, fn, cnt;
long long res;

void sol(int idx, long long f, long long s) {
	if (idx + fn - cnt > n) return;
	if (idx == n) {
		long long temp = f * f + s * s;
		res = min(res, temp);
		return;
	}
	if (cnt < fn) {
		cnt++;
		sol(idx + 1, f + ary[idx][0], s + ary[idx][1]);
		cnt--;
	}

	sol(idx + 1, f - ary[idx][0], s - ary[idx][1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a, b;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		res = 800000000001;
		cin >> n;
		fn = n >> 1;
		for (int i = 0; i < n; i++) {
			cin >> ary[i][0] >> ary[i][1];
		}
		cnt = 1;
		sol(1, ary[0][0], ary[0][1]);
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}