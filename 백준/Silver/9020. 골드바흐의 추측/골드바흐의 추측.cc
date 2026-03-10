#include <stdio.h>
#include <iostream>

using namespace std;

int mem[10000] = { 0, }; // 0이 소수인거로 체크

int main(void)
{
	int n, T;
	int cnt = 0;
	int a=0, b=0;

	for (int i = 2; i < 10000; i++)
	{
		if (mem[i] != 0) continue;
		for (int j = 2; j * i < 10000; j++)
		{
			mem[j * i] = -1;
		}
	}
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		for (int j = 2;; j++)
		{
			if (mem[j] == 0) // j가 소수라면
			{
				if (mem[n-j] == 0)// b가 소수 라면
				{
					if (j == b && n - j == a)
					{
						break;
					}
					else if (j == n - j)
					{
						a = j;
						b = n - a;
						break;
					}
					else
					{
						a = j;
						b = n - a;
					}
				}
			}
			//cout << "j, mem[j] : " << j << ", " << mem[j] << endl;
			//cout << "n-j, mem[n-j] : " << n - j << ", " << mem[n - j] << endl;
		}
		printf("%d %d\n", a, b);

	}

	return 0;

}