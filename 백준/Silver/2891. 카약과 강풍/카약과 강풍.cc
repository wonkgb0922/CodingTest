#include <iostream>

using namespace std;

int ary[11];

int main()
{
	int n, s, r, in, cnt = 0;
	cin >> n >> s >> r;
	for (int i = 0; i < s; i++) {
		cin >> in;
		ary[in]--;
	}
	for (int i = 0; i < r; i++) {
		cin >> in;
		ary[in]++;
	}
	for (int i = 1; i <= n; i++) {
		if (ary[i] < 0) {
			if (ary[i - 1] > 0) {
				ary[i - 1]--;
				ary[i]++;
			}
			else if (ary[i + 1] > 0) {
				ary[i + 1]--;
				ary[i]++;
			}
			else cnt++;
		}
	}
	cout << cnt;

	return 0;
}