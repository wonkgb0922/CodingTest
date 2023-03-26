#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

int n, m, ary[100000] = { 0 };
int Sum[100000] = { 0 };

int main(void) {
	
	int i, j, sum;

	scanf("%d", &n);
	scanf("%d", &ary[0]);
	Sum[0] = ary[0];
	for (i = 1; i < n; i++)
	{
		scanf("%d", &ary[i]);
		Sum[i] = Sum[i - 1] + ary[i];
	}
	scanf("%d", &m);

	while (m--)
	{
		scanf("%d%d", &i, &j);
		if(i == 1) sum = Sum[j - 1];
		else sum = Sum[j - 1] - Sum[i - 2];
		printf("%d\n", sum);
	}

	
	return 0;
}