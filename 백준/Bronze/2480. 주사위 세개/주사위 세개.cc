#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
	int input, max = 0, num;
	int n;
	multiset<int> ms;
	for (int i = 0; i < 3; i++)
	{
		//scanf("%d", &ary[i]);
		scanf("%d", &input);
		ms.insert(input);
	}
	for (int i = 6; i > 0; i--)
	{
		n = ms.count(i);
		if (n > max)
		{
			max = n;
			num = i;
		}
	}
	if (max == 1) printf("%d", num * 100);
	else if (max == 2) printf("%d", 1000 + num * 100);
	else if (max == 3) printf("%d", 10000 + num * 1000);


	return 0;
}