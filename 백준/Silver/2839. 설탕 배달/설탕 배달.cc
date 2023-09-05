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
	int n;
	int cnt = 0;
	int fail = 0;

	cin >> n;

	for (;;)
	{
		 /*
		if (n % 5 == 0)
		{
			cnt = n / 5;
			break;
		}
		else if (n % 5 == 3)
		{
			cnt = n / 5 + 1;
			break;
		}
		else if (n % 5 != 0 && n % 3 != 0)
		{
			cnt = -1;
			break;
		}
		*/
		if (n % 5 == 0)
		{
			cnt += n / 5;
			break;
		}
		else
		{
			if (n < 3)
			{
				fail = 1;
				break;
			}
			n -= 3;
			cnt++;
			continue;
		}
		if (n % 3 == 0)
		{
			cnt += n / 3;
			break;

		}
		
		
	}
	if (fail) cnt = -1;
	cout << cnt;

	return 0;
	
}