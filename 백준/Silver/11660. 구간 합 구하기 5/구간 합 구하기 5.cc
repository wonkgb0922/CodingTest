#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[1025][1025] = { 0 };
long long S[1025][1025] = { 0 };


int main(void) {
	int n;
	int t;
	int sum = 0;
	int x1, y1, x2, y2;

	cin >> n >> t;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ary[i][0]);
		S[i][0] = ary[i][0];
		for (int j = 1; j < n; j++)
		{
			scanf("%d", &ary[i][j]);
			S[i][j] = S[i][j-1] + ary[i][j];
		}
	}
	while (t--)
	{
		sum = 0;
		scanf("%d %d", &y1, &x1); // x1,y1부터 x2,y2까지 사이의 합
		scanf("%d %d", &y2, &x2); 
		if (x1 == 1)
		{
			for (int i = y1 - 1; i < y2; i++)
				sum += S[i][x2 - 1];
		}
		else
		{
			for (int i = y1 - 1; i < y2; i++)
			{
				sum += S[i][x2 - 1] - S[i][x1 - 2];
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}