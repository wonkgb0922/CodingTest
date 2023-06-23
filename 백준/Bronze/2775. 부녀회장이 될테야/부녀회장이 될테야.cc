#include <iostream>

using namespace std;

int func(int k, int n)
{
	if (k <= 0) return n;
	if (n <= 1) return 1;
	return func(k - 1, n) + func(k, n - 1);
}

int main(void)
{
	int T; // 테스트 데이터
	int k, n; // 층, 호수

	int ans;

	
	cin >> T;

	for (; T > 0; T--)
	{
		cin >> k >> n;
		if (k == 0) ans = n;
		else
		{
			ans = func(k, n);
		}
		cout << ans << endl;

	}

	return 0;
	
}