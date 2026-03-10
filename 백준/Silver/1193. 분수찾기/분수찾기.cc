#include <iostream>

using namespace std;

int main(void)
{
	int a=1, b; // 분자, 분모
	int n; // 입력 받는 값
	int cnt = 0; // 최대 분모값
	int even = 1;
	cin >> n;

	if (n == 1) cout << "1/1";
	else
	{
		int j = 2;
		int i;
		int k;

		for (i = 2;;i++)
		{
			if (n <= j) // Check
			{
				// j - i는 세로줄이 됨
				if (n <= j-i)
				{
					j = j - 4 * (even - 1);
					i--;
				}				
				break;

			}
			if (i % 2) // 홀수 일 때
			{
				j++;
			}

			if (i % 2 == 0) // 짝수 일때 
			{

				j += 4*even;
				even++;
			}
			
		}
		//k = j - i;
		//cout << "j: " << j << "\ni : " << i << endl;
		if (j < n)
		{
			b = i - (n - j);
			a = (i + 1) - b;
		}
		else
		{
			b = i - (j - n);
			a = (i + 1) - b;
		}
		cout << a << "/" << b;
		
	}
	
}