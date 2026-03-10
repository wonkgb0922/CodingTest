#include <stdio.h>
#include <iostream>

using namespace std;

int mem[246913] = { 0, }; // 0이 소수인거로 체크

int main(void)
{
	int n;
	int cnt = 0;

	mem[1] = -1;
	for (int i = 2; i < 246913; i++)
	{
		if (mem[i] == -1) continue;
		for (int j = 2; j * i < 246913; j++)
		{
			mem[j * i] = -1; // 소수 부정
		}
	}
	while (1)
	{
		cin >> n;
		cnt = 0;
		if (n != 0)
		{
			
			for (int i = n+1; i <= 2 * n; i++)
			{
				if (mem[i] == 0) cnt++;
			}
			printf("%d\n", cnt);
		}
		else break;
	}



	return 0;

}