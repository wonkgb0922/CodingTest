#include <iostream>

using namespace std;

int main()
{
	int n, ary[6], t, p, cnt = 0;
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> ary[i];
	cin >> t >> p;
	for (int i = 0; i < 6; i++) {
		cnt += ary[i] / t;
		if (ary[i] % t) cnt++;
	}
	cout << cnt << '\n';
	cout << n / p << ' ' << n % p;
	return 0;
}