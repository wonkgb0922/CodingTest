#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	string s;
	int t;
	int score, res;
	cin >> t;
	while (t--)
	{
		cin >> s;
		res = 0;
		score = 0;
		for (auto& x : s)
		{
			if (x == 'O')
			{
				score++;
				res += score;
			}
			else score = 0;
		}
		printf("%d\n", res);
	}
	return 0;
}