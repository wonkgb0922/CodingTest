#include <iostream>
#include <stdlib.h>

using namespace std;

pair<int, int> ary[20];
int n, fn;
long long res;

void sol(int idx, int state, int cnt) {
	if (idx + fn - cnt > n) return;
	if (idx == n) {
		long long f = 0, s = 0, temp;
		for (int i = 0; i < n; i++) {
			if (state & (1 << i)) {
				f += ary[i].first;
				s += ary[i].second;
			}
			else {
				f -= ary[i].first;
				s -= ary[i].second;
			}
		}
		temp = f * f + s * s;
		res = min(res, temp);
		return;
	}

	sol(idx + 1, state, cnt);
	if(cnt < fn)
		sol(idx + 1, state | (1 << idx), cnt + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a, b;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		res = 800000000001;
		cin >> n;
		fn = n / 2;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			ary[i] = { a, b };
		}
		sol(1, 1, 1);
		cout << "#" << tc << " " << res << "\n";
	}

	
	return 0;
}