#include <iostream>
#include <stdlib.h>

using namespace std;

int ary[20][2];
int n, fn;
long long res;

void sol(int idx, int cnt, long long f, long long s) {
	if (idx + fn - cnt > n) return;
	if (idx == n) {
		long long temp = f * f + s * s;
		res = min(res, temp);
		return;
	}

	sol(idx + 1, cnt, f - ary[idx][0], s - ary[idx][1]);
	if (cnt < fn)
		sol(idx + 1, cnt + 1,  f + ary[idx][0], s + ary[idx][1]);
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
		sol(1, 1, ary[0][0], ary[0][1]);
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}